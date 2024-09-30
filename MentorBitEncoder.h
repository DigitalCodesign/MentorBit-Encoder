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

#ifndef MentorBitEncoder_h
#define MentorBitEncoder_h

#include <Wire.h>

class MentorBitEncoder
{
    
  public:

    MentorBitEncoder(uint8_t i2c_addr = 0x1A);
    
    uint16_t obtenerPosicion();
    bool leerPulsador();
    void configurarLeds(uint8_t modoleds);
    void encenderLed(uint8_t numero_led);
    void configurarEncoder(uint8_t modo_encoder);
    void cambiarDireccionI2c(uint8_t i2c_addr);

    const uint8_t apagados = 0;
    const uint8_t encendidos = 1;
    const uint8_t individual = 2;
    const bool acotado = 1;
    const bool sin_acotar = 0;

  private:

    uint8_t _i2c_addr;

};

#endif