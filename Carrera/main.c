#include <stdio.h>
#include <unistd.h> // Para la función sleep

#define NUM_LEDS 8 // Número de LEDs a utilizar en la secuencia

// Declaracion de funciones
void carrera(void);
void disp_binary(unsigned char pattern);

int main() {
    carrera(); // Llamada a la función que ejecuta la secuencia "carrera"
    return 0; // Fin del programa
}

// Función que implementa la secuencia "carrera"
void carrera(void) {
    printf("Mostrando Carrera\n"); // Mensaje inicial
    // Ambos corredores inician en la misma posicion. Patron inicial 80(16) = 10000000(2)
    unsigned char atleta1 = 0x80;
    unsigned char atleta2 = 0x80;

    int pasos_corredor2 = 0; // Contador de pasos para el segundo corredor

    /*
     * Bucle que recorre el número de LEDs para crear la animación de carrera
     * NUM_LEDS equivalen a 8, pero como el atleta1 se desplaza el doble de rapido que el 2do atleta, para el momento que
     * el 1er atleta llegue a la meta, el 2do estara a la mitad del recorrido, por ello se emplea NUM_LEDS * 2 = 16, para
     * que se muestre hasta que el otro corredor llegue a la meta.
     */
    for (int i = 0; i < NUM_LEDS * 2; i++)
    {
        // Combinar los patrones de ambos corredores para obtener el patrón completo
        unsigned char pattern = atleta1 | atleta2;

        /*
         * Variable pattern combina los patrones de ambos corredores usando el operador OR bit a bit (|).
         * Implica que sii cualquier bit en atleta1 o atleta2 está encendido (1, es decir, DISTINTO DE 0 (falso)),
         * el correspondiente bit en pattern también estará encendido (1).
         */

        disp_binary(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Esperar 1 segundo antes de continuar

        // Actualizar patrón del primer corredor (siempre avanza)
        atleta1 >>= 1;

        // Actualizar patrón del segundo corredor cada dos iteraciones
        // Atleta2 va a la mitad de la velocidad que atleta1
        if (i % 2 == 1) {
            atleta2 >>= 1;
        }

        // Detener si ambos corredores han llegado al final
        if (atleta1 == 0 && atleta2 == 0)
        {
            printf("El 1er atleta gano la carrera! \n");
            break;
        }
    }
}

// Función para mostrar el patrón de LEDs en formato binario
void disp_binary(unsigned char pattern) {
    // Bucle para recorrer cada bit del patrón
    for (int t = 128; t > 0; t >>= 1) {

        /*
        * Verificar si el bit actual está encendido (bit != 0: verdadero) o apagado (0: falso)
        * La variable t comienza en: 128(10) = 10000000(2). La misma se desplaza un bit a la derecha (divide su posicion en funcion de 2) mediante el operador '>>=', hasta que t = 0.
        * t = 0, cuando todos los bits han sido desplazados hacia la derecha.
        * En la primera iteración, t representa el bit más significativo '(1 << 7)', y en la última iteración, t representa el bit menos significativo (1 << 0).
        * Esto asegura que cada bit del patrón de LEDs sea probado en su respectiva posición,
        */

        if (pattern & t) {

         /*
         * (pattern & t): Operador de bits AND a nivel de bit
         * t se desplaza hacia la derecha en cada iteración del bucle for. De 128 (10000000) hasta 0.
         * Si un bit específico de pattern está activado y el bit correspondiente de t también está activado (es decir, ambos son 1)
         * entonces el resultado de la operación AND será un número diferente de cero, lo que se evalúa como verdadero .
         * En este caso, cuando el resultado de (pattern & t) es diferente de cero (verdadero), significa que el bit correspondiente en pattern está activado
         *  lo que indica que el LED asociado está encendido.
         */

            printf("*"); // Imprimir un asterisco si el bit está encendido
        } else {
            printf("-"); // Imprimir un guion si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}