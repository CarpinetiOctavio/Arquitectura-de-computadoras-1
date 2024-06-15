//Pendulo.s

.text

.global Pendulo

Pendulo:
        PUSH (R4,R5,R6,LR) // Salvo los registros
        MOV R4,#14 // Aca inicializamos en 14 porque va a ser el contador y nuestro array es de 14 bytes
        LDR R5, =array // carga en el registro 5 la dirección del arreglo (va a acceder al array[0])
    //Aca empieza el loop (bucle)
loop:   LDRB R6,[R5],#1 
        MOV R0,R5
        BL disp_binary
        MVN R0, R6
        BL leds
        MOV R6, #300 //Esto tendría que ser con una variable, no con una constante, como para poder
        BL delaymillis
        SUBS R4,R4,#1
        BNE loop
        POP (R4,R5,R6, PC)

.data
//Aca simplemente declaro el arreglo con los valores en hexadecimal que representan las leds
array: 
    .byte 0x88
    .byte 0x48
    .byte 0x28
    .byte 0x18
    .byte 0x14
    .byte 0x12
    .byte 0x11
    .byte 0x12
    .byte 0x14
    .byte 0x18
    .byte 0x28
    .byte 0x48
    .byte 0x48
    .byte 0x88
