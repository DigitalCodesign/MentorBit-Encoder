# MentorBit-Encoder

Esta librería está diseñada para que puedas utilizar el módulo **MentorBit de encoder con LEDs** con la placa MentorBit y leer de forma sencilla la posición del encoder (número de veces que se ha girado el encoder hacia un sentido) o el estado del pulsador del encoder.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit Encoder.](https://github.com/DigitalCodesign/MentorBit-Encoder/blob/main/assets/Encoder_Module.png)

Con esta librería, podrás crear controles giratorios, menús interactivos o medición de desplazamiento para tus proyectos.

---

## Descripción

### ¿Qué es un encoder rotativo?

Un encoder rotativo es un dispositivo que permite detectar el giro de un eje, así como su dirección (horaria o antihoraria). Algunos modelos también incluyen un pulsador integrado cuando se presiona el eje. Es ampliamente utilizado en sistemas de control, interfaces de usuario o robótica.

---

### ¿Qué hace esta librería?

La librería **MentorBit-Encoder** te permite:

- Leer los cambios de giro en el encoder (conocer la posición).
- Si el encoder ha sido presionado.
- Cambiar el modo de funcionamiento del encoder entre: 
    - Acotado: asigna un límite superior al encoder (0-16), la cuenta siempre estará entre estos dos valores
    - Sin acotar: No hay limite superior ni inferior y la cuenta puede saltar entre los valores mínimo y máximo (255)
- Cambiar el modo de funcionamiento de los leds entre:
    - Apagador: apaga todos los leds del módulo
    - encendidos: enciende los leds en el modo configurado previamente
    - multiplexados: los leds se encienden en modo multiplexados
    - individual: los les se encienden de forma individual
    - libre: Se puede encender y apagar cualquier led 

Todo con funciones simples para facilitar la integración en tus proyectos.

---

### ¿Qué puedes construir con este módulo?

- Interfaces de menú con navegación giratoria.
- Controladores de volumen, brillo o velocidad.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo encoder a uno de los I2C con conector JST de 4 pines que están en la sección "Comunicaciones" de la placa MentorBit. Requiere del protocolo I2C para poder ser utilizado. 

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-Encoder*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-Encoder/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer giro y botón

Este ejemplo muestra en el monitor serie si el encoder gira y en qué dirección, y si se ha presionado el botón.

```cpp
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
```

---

## Funciones Principales

- `uint16_t obtenerPosicion()`  
  Devuelve el valor de la cuenta actual del módulo.

- `void encenderLed(uint8_t numero_led)`  
  Enciende un led de forma individual, independientemente de la cuenta del encoder.

- `void configurarEncoder(uint8_t modo_encoder)`  
  Configura el modo de funcionamiento del módulo de encoder

- `void cambiarDireccionI2c(uint8_t i2c_addr)`  
  Configura la forma de encenderse de los leds del módulo.

---

## Atributos Principales (clase encoder)

- `encoder.apagar`  
  Apaga todos los leds del módulo.

- `encoder.encdender`  
  Enciende los leds del módulo en el anterior modo de funcionamiento.

- `encoder.multiplexados`  
  Los leds se encienden multiplexados.

- `encoder.individual`  
  los leds se encienden individualmente.

- `encoder.leds_linked`  
  El funcionamiento de los leds esta asociado a la cuenta del encoder.

- `encoder.leds_libres`  
  El funcionamiento de los leds lo define el usuario.

- `encoder.cuenta_acotada`  
  La cuenta del encoder esta acotada entre 0 y 16.

- `encoder.cuenta_sin_acotar`  
  La cuenta del encoder puede toimar cualquier valor entre 0 y 255. Se permite el salto entre 0 y 255, al igualñ que el caso contrario

---


## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Encoder](https://digitalcodesign.com/shop/00038966-mentorbit-modulo-de-encoder-con-leds-8128?search=encoder&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1Zw4GrUTFgx-nUpweF6XMzOYxFH-7lOTZ/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/18qgXYxI0iFYRF5yRx6Pfvf_F9YkeEFzc/view?usp=drive_link)
