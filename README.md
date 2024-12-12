# MentorBit-Encoder

Esta librería está diseñada para interactuar con el módulo Encoder de MentorBit, proporcionando métodos para leer la posición del encoder, controlar el pulsador, gestionar los LEDs y configurar el funcionamiento del encoder.

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Modo de Empleo

Una vez que tengas la librería instalada en el Arduino IDE, inclúyela en tu proyecto con la siguiente línea:

```cpp
#include <MentorBitEncoder.h>
```

## Constructor

### `MentorBitEncoder(uint8_t i2c_addr = 0x1A)`

Este constructor inicializa la dirección I2C del módulo. El parámetro `i2c_addr` es opcional y por defecto tiene el valor `0x1A`.

```cpp
MentorBitEncoder encoder(0x1A);  // Dirección I2C por defecto
```

## Métodos Principales

### `obtenerPosicion()`

Devuelve la posición actual del encoder como un valor de 16 bits (`uint16_t`).

```cpp
uint16_t posicion = encoder.obtenerPosicion();
```

### `leerPulsador()`

Devuelve `true` si el pulsador ha sido presionado, de lo contrario, devuelve `false`. Además, resetea el estado del pulsador después de leerlo.

```cpp
bool pulsador = encoder.leerPulsador();
```

### `configurarLeds(uint8_t modoleds)`

Configura los LEDs del módulo. El parámetro `modoleds` acepta tres valores posibles:

- `0`: Apaga los LEDs.
- `1`: Enciende todos los LEDs y los multiplexa.
- `2`: Enciende los LEDs hasta la posición actual del encoder.

```cpp
encoder.configurarLeds(1);  // Enciende todos los LEDs y los multiplexa
```

### `encenderLed(uint8_t numero_led)`

Enciende un LED específico. Solo se puede encender un LED a la vez. Si intentas encender más de uno, solo se mantendrá el último encendido.

```cpp
encoder.encenderLed(3);  // Enciende el LED número 3
```

### `configurarEncoder(uint8_t modo_encoder)`

Configura el modo de funcionamiento del encoder. Acepta dos modos:

- `0`: Modo sin límite, permite valores entre 0 y 255.
- `1`: Modo acotado, restringe los valores entre 0 y 16 (modo circular).

```cpp
encoder.configurarEncoder(1);  // Modo acotado entre 0 y 16
```

### `cambiarDireccionI2c(uint8_t i2c_addr)`

Permite cambiar la dirección I2C del módulo. Este cambio se mantendrá incluso después de apagar el dispositivo. Puedes volver a cambiarla cuando sea necesario.

```cpp
encoder.cambiarDireccionI2c(0x2A);  // Cambia la dirección I2C a 0x2A
```

## Atributos

### `apagados`

Este atributo apaga los LEDs del encoder.

### `encendidos`

Este atributo enciende todos los LEDs del encoder y los multiplexa.

### `individual`

Este atributo enciende el LED correspondiente a la posición actual del encoder.

### `acotado`

Este atributo restringe los valores del encoder entre 0 y 16, manteniendo la cuenta dentro de ese rango.

### `sin_acotar`

Este atributo elimina el límite superior e inferior, permitiendo que la cuenta del encoder varíe entre 0 y 255.

