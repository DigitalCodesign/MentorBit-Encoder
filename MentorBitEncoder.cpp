/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: https://github.com/DigitalCodesign/MentorBit-Encoder
  Descripcion:
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo encoder de MentorBit
  Metodos principales:
    MentorBitEncoder -> constructor de la clase
    obtenerPosicion -> Devuelve el valor de la posicion del encoder (uint8_t)
    leerPulsador -> Devuelve un valor de true o false dependiendo de si se ha pulsado el boton anteriormente
    configurarLeds -> Configura los leds del modulo, puede recibir tres atributos
    encenderLed -> Enciende un led determinado. Solo se puede encender un led a la vez
    configurarEncoder ->  Configura el modo de conteo del encoder (Sin limite o con limite)
    cambiarDireccionI2c -> Cambia la direccion I2C del modulo. El modulo almacena este nuevo valor
  Atributos:
    apagados -> Este atributo apaga los leds del encoder
    encendidos -> Este atributo enciende todos los leds multiplexandolos y enciende hasta el numero contado
    individual -> Este atributo enciende el led individual de la posicion del encoder
    acotado -> Este atributo asigna un limite inferior y superior (0-16) al encoder. De estos valores no
                  pasara la cuenta devuelta
    sin_acotar -> Este atributo elimina el limite superior e inferior y permite que la cuenta cambie entre
                  0 y 255.

*/

#include "MentorBitEncoder.h"
#include <arduino.h>

/*
    Constructor, se debe indicar una dirección I2C a la que conectarse
    
    En caso de no darse, se tomara por defecto la dirección 0x1A
*/
MentorBitEncoder::MentorBitEncoder(uint8_t i2c_addr = 0x1A){
    Wire.begin();
    _i2c_addr = i2c_addr;
}

/*
    Función que obtiene el valor de la posicion marcada por el encoder
*/
uint16_t MentorBitEncoder::obtenerPosicion(){
    Wire.requestFrom(_i2c_addr, 2);
    uint16_t posicion_encoder = Wire.read();
    posicion_encoder |= (Wire.read() << 8);
    posicion_encoder &= 0b0111111111111111;
    return posicion_encoder;
}
/*
Funcion que devuelve unvalor de true o false en funcion de si se ha pulsado
o no el pulsador con anterioridad. Tambien resetea el estado
*/
bool MentorBitEncoder::leerPulsador(){
    Wire.requestFrom(_i2c_addr, 2);
    uint16_t posicion_encoder = Wire.read();
    posicion_encoder |= (Wire.read() << 8);
    posicion_encoder &= 0b1000000000000000;
    bool boton_presionado = 0;
    if(posicion_encoder==0b1000000000000000){
      boton_presionado = 1;
    }
    else{
      boton_presionado = 0;
    }
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x2A);
    Wire.endTransmission();
    return boton_presionado;
}

/*
    Función que permite habilitar o deshabilitar los leds del módulo
*/
void MentorBitEncoder::configurarLeds(uint8_t modoleds){
    Wire.beginTransmission(_i2c_addr);
    if(modoleds==0){
        Wire.write(0x60);
    }
    else if(modoleds==1){
        Wire.write(0x61);
    }
    else if(modoleds==2){
        Wire.write(0x62);
    }
    Wire.endTransmission();
}

/*
    Esta función permite encender un solo led de los disponibles en el módulo

    Al encender un led, se deshabilita el encendido automatico de los leds. No 
    se puede encender mas de un led a la vez, en caso de encender dos, se mantendrá
    ecendido el último led indicado
*/
void MentorBitEncoder::encenderLed(uint8_t numero_led){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x25);
    Wire.write(numero_led);
    Wire.endTransmission();
}

/*
    Esta funcion permite cambiar el modo de funcionamiento.

    Actualmente tiene dos modos de funcionamiento. Un funcionamiento acotado entre 0 y 16, 
    con el cual se encienden los leds dispuestos de forma circular en la placa. El segundo modo 
    funciona entre 0 y 255, permitiendo el salto entre estos dos cuando se alkcanzan los valores
    inferior y superior.
*/
void MentorBitEncoder::configurarEncoder(uint8_t modo_encoder){
    Wire.beginTransmission(_i2c_addr);
    if(modo_encoder==1){
        Wire.write(0x63);
    }
    else if(modo_encoder==0){
        Wire.write(0x64);
    }
    Wire.endTransmission();
}
/*
    Esta función permite cambiar la dirección I2C del módulo. Este cambio se mantiene incluso 
    si se desconecta la alimentación del módulo. Se puede volver a cambiar en caso de ser necesario.
*/
void MentorBitEncoder::cambiarDireccionI2c(uint8_t i2c_addr){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x61);
    Wire.write(0x58);
    Wire.write(0x49);
    Wire.write(i2c_addr);
    Wire.endTransmission();
    _i2c_addr = i2c_addr;
}