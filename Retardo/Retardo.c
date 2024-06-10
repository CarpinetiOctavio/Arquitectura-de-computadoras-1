//
// Created by Octavio Carpineti on 10/06/2024.
//
#include "printf.h"

void retardo(unsigned long int a);

int main (){
    printf("Hello world");
    return 0;
}

void retardo (unsigned long int a)
{
    while (a) a--;
}