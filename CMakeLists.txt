cmake_minimum_required(VERSION 3.28)
project(Arquitectura_de_computadoras_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Arquitectura_de_computadoras_1
        Acceso/main.c
        Choque/main.c
        "Sec. ADN 1/main.c"
        "Sec. ADN 2/Secuencia ADN 2.c"
        Carrera/main.c
        Pendulo/main.c
        Retardo/Retardo.c
        menu.c)
