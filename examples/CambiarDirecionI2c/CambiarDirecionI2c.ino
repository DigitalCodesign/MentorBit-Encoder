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
    Este sketch cambia la direccion I2C del modulo de encoder. Despues de eso inicializa el bus 
    serial y muetsra el valor del encoder por el monitor Serial. Cuando se cambia la direccion 
    I2C la libreria hace los cambios necesarios para seguir conectada al módulo. Si la direccion I2C
    antigua o nueva no coincide con la que tiene el modulo no será posible conectarse con este.

*/

// Se incluye la libreria del encoder de MentorBit
#include <MentorBitEncoder.h>
// Se definen las direcciones I2c
#define DireccionI2C 0x1A
#define NuevaDireccionI2C 0x1B
// Se crea el objeto encoder
MentorBitEncoder encoder(DireccionI2C);

void setup() {
  // Cambiamos la direccion I2C del modulo
  encoder.cambiarDireccionI2c(NuevaDireccionI2C);
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  Serial.println("Se ha cambiado la direccon I2C a:" + String(NuevaDireccionI2C));
}

void loop() {
  // Mostramos el valor de la posicion para asegurarnos que funciona bien
  Serial.println("Valor del encoder: "+ String(encoder.obtenerPosicion()));
  delay(1000);
}
