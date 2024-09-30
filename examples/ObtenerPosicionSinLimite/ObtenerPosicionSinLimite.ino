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
    Este sketch cambia la configuracion del encoder al modo de funcionamiento sin limites.

    En este ejemplo los leds no se pueden encender, ya que para que estos funcionen correctamente
    es necesario que el encoder funcione en modo con limite. Tambien se muetsra si se ha presionado
    el pulsador del encoder
*/

// Se incluye la libreria del encoder de MentorBit
#include <MentorBitEncoder.h>
// Se crea el objeto encoder
MentorBitEncoder encoder;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Configuramos el encoder para eliminar los limites inferior y superior
  encoder.configurarEncoder(encoder.sin_acotar); //encoder.acotado para funcionamiento por defecto
  /*
    Al desactivar el limite superior se desactiva el encendido de los leds
    Si se activa el encendido de los leds se desactivara el modo sin limite.
  */
}

void loop() {
  // Se imprime por pantalla la posición del encoder
  Serial.print("El encoder esta en la posicion: ");
  Serial.println(encoder.obtenerPosicion());
  // Se evalua si se ha presionado el pulsador del encoder
  if(encoder.leerPulsador()){
    // Se imprime por pantalla el aviso
    Serial.println("Se ha presionado el pulsador");
  }
  // Delay para no llenar el monitor serial de mensajes
  delay(1000);
}
