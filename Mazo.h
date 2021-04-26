/*########################*/
#ifndef MAZO_H_INCLUDED //Evita que un archivo header sea procesado dos veces por el compilador
#define MAZO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#############################*/
/*####Definicion de Macros#####*/
/*#############################*/
#define CARTAS 52
#define TOMA 5
/*#############################*/
/*##Definicion de estructuras##*/
/*#############################*/

struct Mazo{ // Representa un mazo de cartas
    char palo[10]; // el palo de la carta
    char numero[8]; // el numero de la carta
    unsigned int estado : 1; // Indica si la carta ya fue sacada del mazo;
};

/*#############################*/
/*###Definicion de funciones###*/
/*#############################*/
//
void establecerMazo(struct Mazo mazo[]){//Establece los valores de la baraja en el mazo
    char *Palos[4] = { "oros", "copas", "espadas", "bastos" }; //Las denominaciones del tipo de baraja
    for (int i = 0; i<CARTAS; i++){ //Itera sobre el numero de cartas del tipo de baraja
        char buffer[10];
        sprintf(buffer,"%d",i%13); //Funcion para convertir un valor numerico a un caracter.
        switch(i%13){ //Determina si el numero actual corresponde a un valor no númerico dentro de la baraja por medio del modulo de 13
                case 0:
                    strcpy(mazo[i].numero,"As"); //Copia el valor de un string a otro
                    break;

                case 10: //Se utiliza el 10 por que i fue inicializado en 0
                    strcpy(mazo[i].numero,"Jota");
                    break;

                case 11:
                    strcpy(mazo[i].numero,"Reina");
                    break;

                case 12:
                    strcpy(mazo[i].numero,"Rey");
                    break;

                default:
                    sprintf(buffer,"%d",i%13+1);
                    strcpy(mazo[i].numero,buffer);
                }
        strcpy(mazo[i].palo,Palos[i/13]);
        mazo[i].estado = 0;
        }
    };

void mostrarCartas(struct Mazo mazo[]){ //Imprime todas las cartas en el mazo
    for (int i = 0; i<CARTAS; i++){
            printf("Palo:%s\t",mazo[i].palo);
            printf("Numero:%s\t",mazo[i].numero);
            printf("Tomada:%d\n",mazo[i].estado);
    }

};

void sacarCartas(struct Mazo mazo[]){ //Saca 5 cartas aleatorias del mazo
    for (int i = 0; i < TOMA; i++){
        for(;;){ // Ciclo infinito hasta que encuentre una carta que no haya sido sacada
            int VA = rand() % CARTAS; //Valor Aleatorio para determinar la carta a sacar
            printf("%d\n",VA);
            if (mazo[VA].estado == 0){
                    mazo[VA].estado = 1;
                    printf("Palo:%s\tNumero:%s\n",mazo[VA].palo,mazo[VA].numero);
                    break;
            }
        }
    }
};
/*
TODO:
1) Parar cuando no hayan cartas suficientes en el mazo
*/
#endif // TEST_H_INCLUDED
