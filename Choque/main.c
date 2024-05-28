#include <stdio.h>
#include <unistd.h> // Incluye la función sleep para pausas

#define NUM_LEDS 8 // Macro con la que definimos el número de LEDs a utilizar (8)

// Declaración de las funciones
void choque(void);
void disp_binary(unsigned char pattern);

/*
 * Se emplea el termino 'unsigned' (no signado)
 *
 */

int main()
{
    choque(); // Llamada a la función que ejecuta la secuencia "choque"
    return 0; // Fin del programa
}

// Función que implementa la secuencia "choque"
void choque(void)
{
    printf("Mostrando Choque\n"); // Mensaje inicial

    // Definición de patrones iniciales para los LEDs
    unsigned char leftLed = 0x80; // LED izquierdo, encendido en la posición más a la izquierda (10000000 en binario)
    unsigned char rightLed = 0x01; // LED derecho, encendido en la posición más a la derecha (00000001 en binario)

    /*
     * Al emplear numeros con signo, aritmeticamente el desp. a la derecha implica una division en funcion de 2.
     * Si un numero es negativo, al dividirlo por 2 , no puede convertirse en positivo de ser un desplazamiento aritmetico, puesto que conservaria el bit de signo (1)
     */

    // Bucle principal para la animación de choque
    for (int i = 0; i < NUM_LEDS - 1; i++)
    {

        // Combinar los patrones de ambos LEDs para obtener el patrón completo
        unsigned char pattern = leftLed | rightLed;

        /*
         * Usa una operación OR bit a bit (|) para combinar los patrones de leftLed y rightLed.
         * El resultado es un patrón donde ambos LEDs están encendidos en sus posiciones actuales.
         * Esta combinación de estos dos patrones son representadas en un solo valor, mostrado por disp_binary
         */

        disp_binary(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Pausa de 1 segundo antes de continuar

        // Actualizar patrones de LEDs de forma independiente
        if (i < (NUM_LEDS / 2) - 1)
        {
            // NUM_LEDS / 2, ya que se marca cual es el centro de esta forma.
            // (- 1) se realiza porque los índices comienzan desde 0, por lo que se descarta una casilla para completar la cantidad de lineas
            leftLed >>= 1; // Desplazar el LED izquierdo una posición a la derecha
            rightLed <<= 1; // Desplazar el LED derecho una posición a la izquierda
        } else if (i == (NUM_LEDS / 2) - 1)
        {
            // Cond. que indica que se alcanzo el centro de los LEDs
            // Mantener los LEDs en el centro por una iteración adicional
            // No se realiza ninguna actualización de patrones
        } else
        {
            leftLed <<= 1; // Desplazar el LED izquierdo una posición a la izquierda
            rightLed >>= 1; // Desplazar el LED derecho una posición a la derecha
            // Se terminan de desplazar, simulando la colision
        }
    }

    /*
     * El simbolo, en C : '<<' --> Indica desplazamiento a la derecha, en este caso, como la variable es 'unsigned', el desplazamiento es LOGICO.
     * De no ser 'unsigned', seria un desplazamiento aritmetico, el cual conserva el bit de signo.
     * En este caso, se modifica de usar 'unsigned', o no, debido a que la secuencia es dada logicamente.
     * De ser realizada mediante tabla, no variaria en caso de usar 'unsigned' o no, ya que la instruccion estaria dada en al memoria. No realiza un desplazamiento como tal
     */

    // Mostrar el último estado, cuando las luces regresan a la "posición original". Patron final, en el que las posiciones son iguales a como iniciaron
    unsigned char finalPattern = leftLed | rightLed;
    disp_binary(finalPattern);
    sleep(1); // Pausa final de 1 segundo antes de terminar
}

// Función para mostrar el patrón de LEDs en formato binario
void disp_binary(unsigned char pattern)
{
    // Bucle para recorrer cada bit del patrón de izquierda a derecha
    for (int t = 128; t > 0; t >>= 1)

    /*
     * La variable t comienza en: 128(10) = 10000000(2). La misma se desplaza un bit a la derecha (divide su posicion en funcion de 2) mediante el operador '>>=', hasta que t = 0.
     * t = 0, cuando todos los bits han sido desplazados hacia la derecha.
     * En la primera iteración, t representa el bit más significativo '(1 << 7)', y en la última iteración, t representa el bit menos significativo (1 << 0).
     * Esto asegura que cada bit del patrón de LEDs sea probado en su respectiva posición,
     */

    {
        // Verificar si el bit actual está encendido (1) o apagado (0)
        if (pattern & t)

        /*
         * (pattern & t): Operador de bits AND a nivel de bit
         * t se desplaza hacia la derecha en cada iteración del bucle for. De 128 (10000000) hasta 0.
         * Si un bit específico de pattern está activado y el bit correspondiente de t también está activado (es decir, ambos son 1)
         * entonces el resultado de la operación AND será un número diferente de cero, lo que se evalúa como verdadero .
         * En este caso, cuando el resultado de (pattern & t) es diferente de cero (verdadero), significa que el bit correspondiente en pattern está activado
         *  lo que indica que el LED asociado está encendido.
         */

        {
            printf("*"); // Imprimir un asterisco si el bit está encendido
        } else
        {
            printf("-"); // Imprimir un guion bajo si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}

/*
 * La funcion disp_binary se la reconoce como 'Mascara', debido a que la misma proporciona una representación visual del estado de los LEDs.
 * Mediante el uso de asteriscos (*), para indicar los LEDs encendidos, y guiones bajos (-) para los LEDs apagados.
 * Ademas, describe como una capa de abstracción que oculta detalles internos y presenta una interfaz simplificada.
 * En este sentido, la función disp_binary() actúa como una máscara al proporcionar una interfaz simple para visualizar el estado de los LEDs.
 * Sin exponer la complejidad de cómo se calcula o controla ese estado.
 */