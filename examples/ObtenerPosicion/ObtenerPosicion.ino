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
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Se imprime por pantalla la posición del encoder
  Serial.println("El encoder esta en la posicion: " + String(encoder.obtenerPosicion()));
  // Se evalua si se ha presionado el pulsador del encoder
  if(encoder.leerPulsador()){
    // Se imprime por pantalla el aviso
    Serial.println("Se ha presionado el pulsador");
  }
  // Delay para no llenar el monitor serial de mensajes
  delay(1000);
}
