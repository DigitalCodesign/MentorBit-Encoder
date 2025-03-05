# MentorBitEncoder

Librería para el control de un encoder rotatorio con pulsador y LEDs integrados en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitEncoder` facilita el control de encoders rotatorios con pulsador y LEDs integrados en módulos compatibles con MentorBit. Permite leer la posición del encoder, detectar pulsaciones del botón, controlar los LEDs integrados y configurar el modo de funcionamiento del encoder. La comunicación se realiza mediante I2C, lo que simplifica la conexión y el uso del módulo.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitEncoder" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitEncoder.h>

    MentorBitEncoder encoder;

    void setup() {
      Serial.begin(9600);
      encoder.configurarEncoder(encoder.acotado); // Modo acotado (0-16)
      encoder.configurarLeds(encoder.encendidos); // LEDs encendidos automáticamente
    }

    void loop() {
      uint16_t posicion = encoder.obtenerPosicion();
      bool pulsado = encoder.leerPulsador();

      Serial.print("Posicion: ");
      Serial.print(posicion);
      Serial.print(" - Pulsador: ");
      Serial.println(pulsado);

      delay(100);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitEncoder(uint8_t i2c_addr = 0x1A)`: Crea un objeto `MentorBitEncoder`.
    * `i2c_addr`: Dirección I2C del encoder. El valor predeterminado es `0x1A`.

### Métodos

* `uint16_t obtenerPosicion()`: Obtiene la posición actual del encoder.
* `bool leerPulsador()`: Lee el estado del pulsador y lo resetea. Devuelve `true` si se ha pulsado, `false` en caso contrario.
* `void configurarLeds(uint8_t modoleds)`: Configura el modo de los LEDs integrados.
    * `modoleds`: Puede ser `apagados`, `encendidos` o `individual`.
* `void encenderLed(uint8_t numero_led)`: Enciende un LED individual. Deshabilita el encendido automático.
    * `numero_led`: Número del LED a encender.
* `void configurarEncoder(uint8_t modo_encoder)`: Configura el modo de funcionamiento del encoder.
    * `modo_encoder`: Puede ser `acotado` (0-16) o `sin_acotar` (0-255).
* `void cambiarDireccionI2c(uint8_t i2c_addr)`: Cambia la dirección I2C del módulo.

### Constantes Públicas

* `const uint8_t apagados = 0`: Modo de LEDs apagados.
* `const uint8_t encendidos = 1`: Modo de LEDs encendidos automáticamente.
* `const uint8_t individual = 2`: Modo de control individual de LEDs.
* `const bool acotado = 1`: Modo de encoder acotado (0-16).
* `const bool sin_acotar = 0`: Modo de encoder sin acotar (0-255).
