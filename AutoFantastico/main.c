//Debo programar el autofantastico
#include <stdio.h>
#include <unistd.h>

void AutoFantastico();
void disp_binary(unsigned char pattern);

int main(){
    AutoFantastico();
    return 0;
}

void AutoFantastico(void){
    printf("Mostrando Auto Fantastico:\n");
    unsigned char tabla[15] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    //En el regnglón anterior solo creo el arreglo con los valores en hexadecimal
    for (int i=0; i<15; i++){ //hago el for que recorra todo el arreglo
        disp_binary(tabla[i]);//uso la funcion para que me imprima lo que representa las luces
        sleep(1);//hago retraso de 1 segundo
    }
    printf("chau\n");//me despido xd
}

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