#include <stdio.h>
#include <unistd.h>

#define NUM_LEDS 8

void chargeBar(void);
void disp_binary(unsigned char pattern);

int main() {
    chargeBar();
    return 0;
}

void disp_binary(unsigned char pattern)
{
    for (int t = 128; t > 0; t >>= 1){
        if (pattern & t){
            printf("*");
        } else{
            printf("-");
        }
    }
    printf("\n");
}

void chargeBar(void)
{
    printf("Mostrando Barra de Carga\n");


    unsigned char led = 0x80;

    for (int i = 0; i < NUM_LEDS - 1; i++)
    {
        disp_binary(led);
        sleep(1);
        
        led |= 0x80 >> (i + 1);
    }

    disp_binary(led);
    sleep(1);
}