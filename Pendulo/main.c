#include <stdio.h>
#include <unistd.h> // Para la función sleep

#define NUM_PATTERNS 14 // Número de patrones en la secuencia

void pendulo(void);
void disp_binary(unsigned char pattern);

int main() {
    pendulo(); // Llamada a la función que ejecuta la secuencia del péndulo
    return 0; // Fin del programa
}

// Función que implementa la secuencia del péndulo
void pendulo(void) {
    printf("Mostrando pendulo\n"); // Mensaje inicial

    // Tabla de patrones en formato hexadecimal para la secuencia del péndulo
    unsigned char patrones[NUM_PATTERNS] = {
            0x88, // *---*---
            0x48, // -*--*---
            0x28, // --*-*---
            0x18, // ---**---
            0x14, // ---*-*--
            0x12, // ---*--*-
            0x11, // ---*---*
            0x11, // ---*---*
            0x12, // ---*--*-
            0x14, // ---*-*--
            0x18, // ---**---
            0x28, // --*-*---
            0x48, // -*--*---
            0x88, // *---*---
    };

    // Bucle que recorre la tabla de patrones
    for (int i = 0; i < NUM_PATTERNS; i++) {
        disp_binary(patrones[i]); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Esperar 1 segundo antes de continuar
    }
}

// Función para mostrar el patrón de LEDs en formato binario
void disp_binary(unsigned char pattern) {
    // Bucle para recorrer cada bit del patrón
    for (int t = 128; t > 0; t >>= 1) {
        // Verificar si el bit actual está encendido (1) o apagado (0)
        if (pattern & t) {
            printf("*"); // Imprimir un asterisco si el bit está encendido
        } else {
            printf("-"); // Imprimir un guion bajo si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}


/*
 * void retardo (unsigned long int a)
 * {
 *      while (a)
 *      {
 *          ...
 *          a--;
 *       }
 * }
 *
 * El sensado de las teclas con Up y Down
 */
