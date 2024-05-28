#include <stdio.h>
#include <unistd.h> // Para la función sleep

#define NUM_LEDS 16 // Número de LEDs a utilizar en la secuencia

void adn(void);
void disp_binary(unsigned char pattern);

int main() {
    adn(); // Llamada a la función que ejecuta la secuencia de ADN
    return 0; // Fin del programa
}

// Función que implementa la secuencia de ADN
void adn(void) {
    printf("Secuencia ADN por la mitad\n"); // Mensaje inicial
    unsigned char pattern = 0x1C; // Patrón inicial para la secuencia de ADN

    // Bucle que recorre el número de LEDs para crear la secuencia de ADN
    for (int i = 0; i < NUM_LEDS; i++) {
        disp_binary(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Esperar 1 segundo antes de continuar

        // Rotar el patrón a la izquierda una posición
        pattern = (pattern << 1) | (pattern >> 7);
    }
}

// Función para mostrar el patrón de LEDs en formato binario
void disp_binary(unsigned char pattern) {
    // Bucle para recorrer cada bit del patrón
    for (int t = 128; t > 0; t >>= 1) {
        // Verificar si el bit actual está encendido (1) o apagado (0)
        if (pattern & t) {
            printf("#"); // Imprimir un asterisco si el bit está encendido
        } else {
            printf("-"); // Imprimir un guion bajo si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}