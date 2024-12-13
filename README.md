
# MentorBit-Encoder
Esta librería está diseñada para el uso del módulo encoder con MentorBit, permitiendo la comunicación a través de I2C para leer la posición del encoder, controlar los LEDs y gestionar el pulsador.

Puedes encontrar más material educativo sobre electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de Empleo

Para utilizar esta librería, primero debes incluir el archivo `MentorBitEncoder.h` en tu sketch de Arduino:

```cpp
#include <MentorBitEncoder.h>
```

### Constructor

El constructor del objeto `MentorBitEncoder` permite configurar la dirección I2C del módulo. Si no se especifica una dirección, se usará la predeterminada 0x1A.

```cpp
MentorBitEncoder encoder(PIN_I2C);
```

Donde:
- `PIN_I2C` es la dirección I2C del dispositivo (por defecto 0x1A).

### Métodos Principales

#### `obtenerPosicion()`
Obtiene la posición actual del encoder, devolviendo un valor de 16 bits.

```cpp
uint16_t posicion = encoder.obtenerPosicion();
```

- **Valor devuelto**: El valor de la posición del encoder (16 bits).

#### `leerPulsador()`
Lee el estado del pulsador, devolviendo `true` si ha sido presionado y `false` si no.

```cpp
bool pulsador = encoder.leerPulsador();
```

- **Valor devuelto**: `true` si el pulsador ha sido presionado, de lo contrario, `false`.

#### `configurarLeds(uint8_t modoleds)`
Configura los LEDs del módulo en tres modos diferentes:
- `0`: LEDs apagados.
- `1`: LEDs encendidos.
- `2`: LEDs encendidos de forma individual.

```cpp
encoder.configurarLeds(encoder.encendidos);
```

- **Parámetros**: 
  - `encoder.apagados`: Desactiva los LEDs.
  - `encoder.encendidos`: Activa todos los LEDs.
  - `encoder.individual`: Activa los LEDs de forma individual.

#### `encenderLed(uint8_t numero_led)`
Enciende un LED específico en el módulo. Solo puede encenderse un LED a la vez, y al encender uno, se desactiva el encendido automático.

```cpp
encoder.encenderLed(1);
```

- **Parámetros**: 
  - `numero_led`: El número del LED a encender.

#### `configurarEncoder(uint8_t modo_encoder)`
Configura el funcionamiento del encoder. Los dos modos disponibles son:
- **Modo acotado**: Funciona entre los valores 0 y 16, con LEDs dispuestos en forma circular.
- **Modo sin acotar**: Funciona entre 0 y 255, permitiendo saltos entre estos valores.

```cpp
encoder.configurarEncoder(encoder.acotado);
```

- **Parámetros**: 
  - `encoder.acotado`: Modo acotado entre 0 y 16.
  - `encoder.sin_acotar`: Modo sin acotar entre 0 y 255.

#### `cambiarDireccionI2c(uint8_t i2c_addr)`
Cambia la dirección I2C del módulo, y este cambio se mantiene incluso si se desconecta la alimentación.

```cpp
encoder.cambiarDireccionI2c(0x2A);
```

- **Parámetros**: 
  - `i2c_addr`: La nueva dirección I2C a configurar.

# Atributos

### Atributos Comunes para la Configuración de LEDs

- `const uint8_t apagados`: Apaga los LEDs.
- `const uint8_t encendidos`: Enciende todos los LEDs.
- `const uint8_t individual`: Enciende los LEDs de forma individual.

### Atributos para el Modo del Encoder

- `const bool acotado`: Modo acotado, valores entre 0 y 16.
- `const bool sin_acotar`: Modo sin acotar, valores entre 0 y 255.

