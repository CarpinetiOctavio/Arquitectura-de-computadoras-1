/*
* Codigo de validacion de acceso al sistema. Solicita clave de 5 digitos para poder acceder, teniendo unicamente 3 intentos.
*/


#include <stdio.h>
#include <string.h>
#include <conio.h> // Biblioteca necesaria para _getch en Windows

// Prototipo de la función para verificar el acceso
int verificarAcceso(const char* clave);

int main()
{
    // Definición de la clave predefinida
    const char clavePredefinida[6] = "12345";

    // Llamada a la función para verificar el acceso
    int resultado = verificarAcceso(clavePredefinida);

    // Mensaje de bienvenida o bloqueo según el resultado
    if (resultado == 1)
    {
        printf("\nBienvenido al Sistema.\n");
    } else
    {
        printf("\nAcceso bloqueado. Demasiados intentos fallidos.\n");
    }

    return 0;
}

// Función para verificar el acceso
int verificarAcceso(const char* clave)
{
    char password[100];     // Contraseña ingresada por el usuario
    int intentos = 0;   // Contador de intentos
    int correcta = 0;   // Bandera para indicar si la contraseña es correcta

    // Ciclo para permitir hasta 3 intentos de ingreso
    while (intentos < 3)
    {
        printf("Ingresar clave de 5 digitos: ");
        fflush(stdout); // Vaciar el buffer de salida para imprimir inmediatamente

        int i = 0;  // Índice para recorrer la contraseña

        // Ciclo para capturar la contraseña ingresada
        while (1)
        {
            char c = _getch();  // Leer un carácter sin imprimirlo en pantalla

            // Manejo de la entrada del usuario
            if (c == '\r')  // Si se presiona 'Enter'
            {
                break;  // Salir del ciclo de captura de contraseña
            } else if (c == '\b' && i > 0)  // Manejar el retroceso si hay caracteres ingresados
            {
                i--;    // Decrementar el índice para borrar el último carácter
                printf("\b \b");    // Borrar el último carácter impreso
            } else if (c >= '0' && c <= '9')    // Solo permitir dígitos decimales
            {
                if (i < 5)  // Asegurar que no se exceda la longitud máxima de la contraseña
                {
                    password[i++] = c; // Almacenar el carácter en la contraseña y avanzar el índice
                    putchar('*'); // Imprimir un asterisco en lugar del carácter
                    fflush(stdout); // Asegurar que el asterisco se imprime inmediatamente
                }
            }
        }

        /*
         * fflush(stdout) --> Vacía el buffer de salida 'stdout', asegurando que cualquier texto pendiente ('*') se imprima de inmediato en la consola.
         * while (1) {...} --> Bucle infinito (1 = cond. verdadera)
         * _getch() --> Lee el caracter de entrada sin necesidad de presionar 'Enter'
         * if (c == '\r') { ... } --> Bloque cond. que verifica si se presiona 'Enter', indicando que completa la entrada de la clave
         * else if (c == '\b' && i > 0) { ... }: --> Bloque cond. que maneja el caso en que se presiona la tecla de retroceso ('\b') para borrar el último carácter ingresado. Siempre que haya al menos un carácter ingresado (i > 0), se elimina el último carácter de la contraseña (i--) y se borra el asterisco correspondiente de la pantalla.
         */

        password[i] = '\0'; // Terminar la cadena con un nulo

        // Después de salir del bucle de captura de contraseña, se agrega un carácter nulo ('\0') al final de la cadena de la contraseña para marcar su final.

        printf("\n"); // Nueva línea después de la entrada

        // Verificar que la longitud de la contraseña sea exactamente 5
        if (i != 5)
        {
            printf("Incorrecto: Clave de 5 digitos.\n");
            intentos++; // Incrementar el contador de intentos
            printf("Le quedan %d intentos.\n", 3 - intentos);   // Informar los intentos restantes
            continue;   // Volver al inicio del ciclo para permitir un nuevo intento
        }

        // Validar la contraseña ingresada con la predefinida
        correcta = 1;   // Asumimos que es correcta, la validamos a continuación
        for (int j = 0; j < 5; j++)
        {
            if (password[j] != clave[j])
            {
                correcta = 0;   // Si algún carácter no coincide, la contraseña es incorrecta
                break;  // Salir del ciclo de validación
            }
        }

        // Mensaje de acceso concedido o denegado según la validez de la contraseña
        if (correcta)
        {
            printf("\nAcceso concedido!\n");
            return 1;   // Indica que el acceso es correcto
        } else
        {
            printf("\nAcceso denegado.\n");
            intentos++; // Incrementar el contador de intentos
            if (intentos < 3)
            {
                printf("Le quedan %d intentos.\n", 3 - intentos);   // Informar los intentos restantes
            }
        }
    }

    return 0;   // Acceso denegado después de 3 intentos fallidos
}
