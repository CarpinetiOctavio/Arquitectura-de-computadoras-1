#include <stdio.h>
#include <unistd.h> // Para la función sleep

#define NUM_LEDS 8 // Número de LEDs a utilizar en la secuencia

void secuencia_adn(void);
void mostrar_adn(unsigned char pattern);

int main() {
    secuencia_adn(); // Llamada a la función que ejecuta la secuencia "secuencia_adn"
    return 0; // Fin del programa
}

// Función que implementa la secuencia "secuencia_adn"
void secuencia_adn(void) {
    printf("Mostrando ADN\n"); // Mensaje inicial
    unsigned char leftLed = 0x80; // Patrón inicial para el LED izquierdo (10000000 en binario)
    unsigned char rightLed = 0x01; // Patrón inicial para el LED derecho (00000001 en binario)

    // Bucle que recorre el número de LEDs para crear la secuencia de ADN
    for (int i = 0; i < NUM_LEDS - 1; i++) {
        // Combinar los patrones de ambos LEDs para obtener el patrón completo
        unsigned char pattern = leftLed | rightLed;
        mostrar_adn(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Esperar 1 segundo antes de continuar

        // Actualizar patrones de LEDs de forma independiente
        leftLed >>= 1; // Desplazar el LED izquierdo una posición a la derecha
        rightLed <<= 1; // Desplazar el LED derecho una posición a la izquierda
    }

    // Mostrar el estado de ADN por dos iteraciones
    for (int i = 0; i < 2; i++) {
        unsigned char pattern = leftLed | rightLed;
        mostrar_adn(pattern);
        sleep(1);
    }

    // Bucle para regresar los LEDs a su posición original
    for (int i = 0; i < NUM_LEDS - 1; i++) {
        leftLed <<= 1; // Desplazar el LED izquierdo una posición a la izquierda
        rightLed >>= 1; // Desplazar el LED derecho una posición a la derecha

        // Combinar los patrones de ambos LEDs para obtener el patrón completo
        unsigned char pattern = leftLed | rightLed;
        mostrar_adn(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Esperar 1 segundo antes de continuar
    }
}

// Función para mostrar el patrón de LEDs en formato de secuencia de ADN
void mostrar_adn(unsigned char pattern) {
    // Bucle para recorrer cada bit del patrón
    for (int t = 128; t > 0; t >>= 1) {
        // Verificar si el bit actual está encendido (1) o apagado (0)
        if (pattern & t) {
            printf("*"); // Imprimir un asterisco si el bit está encendido
        } else {
            printf("_"); // Imprimir un guion si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}