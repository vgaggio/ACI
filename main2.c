#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include "EasyPIO.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

void enableNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disableNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}


void autofantastico (int *delay){
    int i;
    char caracter;
    bool termino = false;
    pioInit();
    const unsigned char led[8] = {14, 15, 18, 23, 24, 25, 8, 7};
    for (i = 0; i < 8; i++){
        pinMode(led[i], OUTPUT);
    }

    i = 0;
    while(caracter != ENTER){
        printf("Presione la flecha hacia arriba para aumentar la velocidad, la flecha hacia abajo para disminuir la velocidad o enter para salir.\n");
        caracter = getchar();
        if (caracter == ARRIBA){
            delay -= 100;
        }
        if (caracter == ABAJO){
            delay += 100;
        }
        digitalWrite(led[i],1);
        delayMillis(*delay);
        digitalWrite(led[i],0);
        if (i==0){
            termino = false;
        } else if (i==8){
            termino = true;
        }
        if (!termino){
            i++;
        }else{
            i--;
        }
    }
    for(int k = 0;k < 8;k++){
        digitalWrite(led[k],0);
    }
}

void elchoque (int *delay){
    int i;
    int j;
    char caracter;
    bool termino = false;
    pioInit();
    const unsigned char led[8] = {14, 15, 18, 23, 24, 25, 8, 7};
    for (i = 0; i < 8; i++){
        pinMode(led[i], OUTPUT);
    }

    i = 0;
    j = 7;
    while(caracter != ENTER){
        printf("Presione la flecha hacia arriba para aumentar la velocidad, la flecha hacia abajo para disminuir la velocidad o enter para salir.\n");
        caracter = getchar();
        if (caracter == ARRIBA){
            delay -= 100;
        }
        if (caracter == ABAJO){
            delay += 100;
        }
        digitalWrite(led[i],1);
        digitalWrite(led[j],1);
        delayMillis(*delay);
        digitalWrite(led[i],0);
        digitalWrite(led[j],0);
        if (i==0 && j==7){
            termino = false;
        } else if (i==3 && j==4){
            termino = true;
        }
        if (!termino){
            i++;
            j--;
        }else{
            i--;
            j++;
        }
    }
    for(int k = 0;k < 8;k++){
        digitalWrite(led[k],0);
    }
}

void parimpar (int *delay){
    int i;
    int j;
    char caracter;
    bool cambio = false;
    pioInit();
    const unsigned char led[8] = {14, 15, 18, 23, 24, 25, 8, 7};
    for (i = 0; i < 8; i++){
        pinMode(led[i], OUTPUT);
    }

    while(caracter != ENTER){
        printf("Presione la flecha hacia arriba para aumentar la velocidad, la flecha hacia abajo para disminuir la velocidad o enter para salir.\n");
        caracter = getchar();
        if (caracter == ARRIBA){
            delay -= 100;
        }
        if (caracter == ABAJO){
            delay += 100;
        }
        if (!cambio){
            digitalWrite(led[0],1);
            digitalWrite(led[2],1);
            digitalWrite(led[4],1);
            digitalWrite(led[6],1);
            delayMillis(*delay);
            digitalWrite(led[0],0);
            digitalWrite(led[2],0);
            digitalWrite(led[4],0);
            digitalWrite(led[6],0);
            cambio = true;
        } else{
            digitalWrite(led[1],1);
            digitalWrite(led[3],1);
            digitalWrite(led[5],1);
            digitalWrite(led[7],1);
            delayMillis(*delay);
            digitalWrite(led[1],0);
            digitalWrite(led[3],0);
            digitalWrite(led[5],0);
            digitalWrite(led[7],0);
            cambio = false;
        }
    }
    for(int k = 0;k < 8;k++){
        digitalWrite(led[k],0);
    }
}

void sirena (int *delay){
    int i;
    int j;
    char caracter;
    bool cambio = false;
    pioInit();
    const unsigned char led[8] = {14, 15, 18, 23, 24, 25, 8, 7};
    for (i = 0; i < 8; i++){
        pinMode(led[i], OUTPUT);
    }

    while(caracter != ENTER){
        printf("Presione la flecha hacia arriba para aumentar la velocidad, la flecha hacia abajo para disminuir la velocidad o enter para salir.\n");
        caracter = getchar();
        if (caracter == ARRIBA){
            delay -= 100;
        }
        if (caracter == ABAJO){
            delay += 100;
        }
        if (!cambio){
            digitalWrite(led[0],1);
            digitalWrite(led[1],1);
            digitalWrite(led[2],1);
            digitalWrite(led[3],1);
            delayMillis(*delay);
            digitalWrite(led[0],0);
            digitalWrite(led[1],0);
            digitalWrite(led[2],0);
            digitalWrite(led[3],0);
            cambio = true;
        } else{
            digitalWrite(led[4],1);
            digitalWrite(led[5],1);
            digitalWrite(led[6],1);
            digitalWrite(led[7],1);
            delayMillis(*delay);
            digitalWrite(led[4],0);
            digitalWrite(led[5],0);
            digitalWrite(led[6],0);
            digitalWrite(led[7],0);
            cambio = false;
        }
    }
    for(int k = 0;k < 8;k++){
        digitalWrite(led[k],0);
    }
}

int main() {
    char contraingresada[100];
    int contadorintentos = 0;
    int secuenciaelegida = 0;
    int caracter;
    int tipo = 0;
    int i = 0;
    int estadoluz = 1;
    int delay = 500;

    enableNonCanonicalMode();

        while (contadorintentos < 3) {
            printf("Ingrese la Password: ");
            fflush(stdout);

            i = 0;
            memset(contraingresada, 0, sizeof(contraingresada));

            while (1) {
                if (read(STDIN_FILENO, &caracter, 1) > 0) {
                    if (caracter == '\n' || caracter == '\r') { // Check for Enter key
                        printf("\n");
                        break;
                    } else if (caracter == 127) {
                        if (i > 0) {
                            printf("\b \b");
                            i--;
                        }
                    } else {
                        contraingresada[i] = caracter;
                        printf("*");
                        i++;
                    }
                    fflush(stdout);
                }
            }

            if (strcmp(contraingresada, "contr") == 0) {
                printf("Bienvenido al Sistema\n");
                break;
            } else {
                printf("Password no valida\n");
            }
            contadorintentos++;
        }

        disableNonCanonicalMode();

        if (contadorintentos == 3) {
            printf("Se ha excedido el numero de intentos permitidos.");
            exit(400);
        }

    while (secuenciaelegida != 5) {
        printf("\n");
        printf("Secuencia de luces: \n");
        printf("1) El auto fantastico.\n");
        printf("2) El choque.\n");
        printf("3) Par/Impar.\n");
        printf("4) Sirena.\n");
        printf("5) Salir. \n\n");

        printf("Seleccione la secuencia de luces a reproducir: ");
        scanf("%d", &secuenciaelegida);

        switch (secuenciaelegida) {
            case 1:
                while (tipo != 1 && tipo != 2) {
                    printf("Presione 1 para realizar la secuencia en C, y 2 para realizarla en ARM: ");
                    scanf("%d", &tipo);
                }

                printf("Has elegido la secuencia 'auto fantastico':\n");
                autofantastico(&delay);
                tipo = 0;
                break;
            case 2:
                while (tipo != 1 && tipo != 2) {
                    printf("Presione 1 para realizar la secuencia en C, y 2 para realizarla en ARM: ");
                    scanf("%d", &tipo);
                }

                printf("Has elegido la secuencia 'el choque':\n");
                elchoque(&delay);
                tipo = 0;
                break;
            case 3:
                while (tipo != 1 && tipo != 2) {
                    printf("Presione 1 para realizar la secuencia en C, y 2 para realizarla en ARM: ");
                    scanf("%d", &tipo);
                }

                printf("Has elegido la secuencia 'par/impar':\n");
                parimpar(&delay);
                tipo = 0;
                break;
            case 4:
                while (tipo != 1 && tipo != 2) {
                    printf("Presione 1 para realizar la secuencia en C, y 2 para realizarla en ARM: ");
                    scanf("%d", &tipo);
                }

                printf("Has elegido la secuencia 'sirena':\n");
                sirena(&delay);
                tipo = 0;
                break;
            case 5:
                break;
        }
    }

    return 0;
}


//El para hacerlo pro algorimto en assembly, podemos hacer shift.