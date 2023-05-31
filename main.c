#include <stdbool.h>
#include "conio.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h> //for system clear

extern int comparePasswords(char* userInput);
void delay(int);

void retardo(unsigned long int); // da tiempo entre las luces
void mostrar(unsigned char);
int fvelocidad(unsigned long int); // aumenta o disminuye velocidad

void auto_fantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void bateriaDescargandose(unsigned long int);
void chocaLos5(unsigned long int);


int main() {
    char userInput[50];
    int attempts = 3;
    int result = -1;

    while (attempts > 0 && result != 0) {
        printf("Enter the password: ");
        fgets(userInput, sizeof(userInput), stdin);

        //Remove trailing newline character from user input
        userInput[strcspn(userInput, "\n")] = '\0';

        result = comparePasswords(userInput);

        if (result == 0) {
            printf("Access granted! \n");
        } else {
            printf("Access denied! \n");
        }
        attempts--;
    }

    if (result != 0) {
        printf("You have been closed out of the system!\n");
        return 0;
    }


    int opcion = 0;
    int contador = 0;
    unsigned long int velocidadAux = 145000000;
    unsigned long int velocidad = velocidadAux;

    do
    {
        if (contador < 3)
        {
            printf("(1) Autos fantastico \n");
            printf("(2) La carrera \n");
            printf("(3) El choque\n");
            printf("(4) Bateria descargandose \n");
            printf("(5) Choca los 5 \n");
            printf("(6) Salir \n");

            printf("\nIngrese la opcion que desee visualizar:\n");
                scanf("%d", &opcion);
            while (opcion < 1 || opcion > 6)
            {
                printf("\nValor erroneo, ingrese nuevamente:\n");
                scanf("%d", &opcion);
            }

            switch (opcion)
            {
                case 1:
                    system("cls");
                    auto_fantastico(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 2:
                    system("cls");
                    carrera(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 3:
                    system("cls");
                    choque(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 4:
                    system("cls");
                    bateriaDescargandose(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 5:
                    system("cls");
                    chocaLos5(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 6:
                    system("cls");
                    printf("\nSistema apagado\n");
                    break;
                default:
                    system("cls");
                    printf("\nNo existe secuencia para ese numero\n");
                    opcion = 0;
            }
        }
    } while (opcion != 6);
}

void retardo(unsigned long int a)
{
    while (a)
        a--;
}

void mostrar(unsigned char dato)
{
    for (unsigned char mascara = 128; mascara > 0; mascara >>= 1)
    {
        if (dato & mascara)
        {
            printf("*");
        }
        else
        {
            printf("_");
        }
    }
}

int fvelocidad(unsigned long int velocidad)
{
    if ((velocidad - 4800000) > 9600000)
    {
        if (GetAsyncKeyState(VK_UP) & 0x0001)
        {
            velocidad -= 4800000;
        }
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x0001)
    {
        velocidad += 4800000;
    }
    return velocidad;
}

void auto_fantastico(unsigned long int velocidad)
{
    unsigned int dato;
    while (1)
    {
        //10000000 en binario.
        dato = 0x80;
        for (int t = 0; t < 8; t++)
        {
            printf("\nPresione ESC para regresar al menu principal\n");
            printf("\nPulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("La demora es %d\n", velocidad);

            mostrar(dato);
            retardo(velocidad);
            system("cls");
            //desplazamiento a la derecha en dato, o sea vamos trasladando la luz
            dato = dato >> 1;
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
        dato = 0x01;
        for (int i = 0; i < 6; i++)
        {
            printf("\nPresione ESC para regresar al menu principal\n");
            printf("\nPulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("La demora es %d\n", velocidad);
            dato = dato << 1;
            mostrar(dato);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }

    }
}

void carrera(unsigned long int velocidad)
{
    uint8_t tabla[] = {
            0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x88, 0x48, 0x24, 0x14, 0xA, 0x6, 0x3, 0x1};


    while (1)
    {
        for (int i = 0; i < 16; ++i)
        {
            printf("\nPresione ESC para regresar al menu principal\n");
            printf("\nPulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("La demora es %d\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

void choque(unsigned long int velocidad)
{
    uint8_t tabla[] = {
            0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42};

    while (1)
    {

        for (int i = 0; i < 7; ++i)
        {
            printf("\nPresione ESC para regresar al menu principal\n");
            printf("\nPulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("La demora es %d\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");

            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

void bateriaDescargandose(unsigned long int velocidad)
{
    unsigned int dato = 0xFF;
    while (1)
    {
        for (int i = 0; i < 9; ++i)
        {
            printf("\nPresione ESC para regresar al menu principal\n");
            printf("La demora es %d\n", velocidad);
            mostrar(dato);
            dato <<= 1;
            retardo(velocidad);
            system("cls");

            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
        dato = 0xFF;
    }
}

