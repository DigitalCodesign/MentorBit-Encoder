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
    Este sketch cambia la configuracion de los leds constantemente para poder ver 
    los diferentes modos de funcionamiento. Estos son, apagados, encendidos y encendido solo 
    el led con el numero de la cuenta del encoder.

    Para el correcto funcionamiento de los leds en los modos de encendido es necesario que el 
    encoder este funcionando en modo con limites.

*/

// Se incluye la libreria del encoder de MentorBit
#include <MentorBitEncoder.h>
// Se crea el objeto encoder
MentorBitEncoder encoder;

void setup() {
  /*
    Se recomienda mover el eje del encoder para poder observar
    el cambio de funcionamiento de los leds en una posicion
    intermedia
  */
  // Tambien se pueden encender los leds de forma individual 
  for(int i=0;i<17;i++){
    encoder.encenderLed(i);
    delay(50);
  }
  for(int i=16;i>0;i--){
    encoder.encenderLed(i);
    delay(50);
  }
  /*
    Solo se puede encender un led, por lo que si se enciende otro
    el primero se apagara
  */
}

void loop() {
  // Se configuran los leds en modo individual
  encoder.configurarLeds(encoder.individual);
  delay(2000);
  // Se configuran los leds en modo multiplexado
  encoder.configurarLeds(encoder.encendidos);
  delay(2000);
  // Se configuran los leds en modo apagado
  encoder.configurarLeds(encoder.apagados);
  delay(2000);
}
