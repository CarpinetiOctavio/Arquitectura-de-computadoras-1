#include <stdio.h>
#include <stdbool.h>

#define NUM_LEDS 8

void choque(void);
void disp_binary(unsigned char pattern);

int main() {
    int opcion;
    bool encendido = true;

    printf("Opciones:\n");
    printf("\t* 1 choque\n");
    printf("\t* 2 carrera\n");
    printf("\t* 3 auto fantastico\n");
    printf("\t* 4\n");
    printf("\t* 5\n");
    printf("\t* 0 (salir)\n");
    printf("\t* cualquier otro numero (borrar)\n");
    
    while(encendido) {
        printf("---> ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                choque();
                break;
            case 2:
                printf("opcion 2\n\n");
                break;
            case 3:
                printf("Opcion 3\n\n");
                break;
            case 4:
                printf("Opcion 4\n\n");
                break;
            case 5:
                printf("Opcion 5\n\n");
                break;
            
            case 0:
                encendido = false;
                break;

            default:
                system("cls"); // system("clear"); para Linux
                printf("Opciones:\n");
                printf("\t* 0 (salir)\n");
                printf("\t* 1\n");
                printf("\t* 2\n");
                printf("\t* cualquier otro numero (borrar)\n");
                break;
        }
    }
    return 0;
}

void choque(void)
{
    printf("Mostrando Choque\n"); // Mensaje inicial

    // Definición de patrones iniciales para los LEDs
    unsigned char leftLed = 0x80; // LED izquierdo, encendido en la posición más a la izquierda (10000000 en binario)
    unsigned char rightLed = 0x01; // LED derecho, encendido en la posición más a la derecha (00000001 en binario)

    // Bucle principal para la animación de choque
    for (int i = 0; i < NUM_LEDS - 1; i++)
    {

        // Combinar los patrones de ambos LEDs para obtener el patrón completo
        unsigned char pattern = leftLed | rightLed;

        disp_binary(pattern); // Llamada a la función para mostrar el patrón actual
        sleep(1); // Pausa de 1 segundo antes de continuar

        // Actualizar patrones de LEDs de forma independiente
        if (i < (NUM_LEDS / 2) - 1)
        {
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
    {
        // Verificar si el bit actual está encendido (1) o apagado (0)
        if (pattern & t)
        {
            printf("*"); // Imprimir un asterisco si el bit está encendido
        } else
        {
            printf("-"); // Imprimir un guion bajo si el bit está apagado
        }
    }
    printf("\n"); // Imprimir una nueva línea al final del patrón
}