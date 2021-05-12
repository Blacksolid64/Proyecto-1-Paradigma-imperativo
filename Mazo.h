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

//es una carta
struct Carta{ // Representa un mazo de cartas
    char palo[10]; // el palo de la carta
    char numero[8]; // el numero de la carta
    unsigned int estado : 1; // Indica si la carta ya fue sacada del mazo;
    unsigned int suerte; // Un numero aleatorio que determina la probabilidad de sacar esta carta
};

struct Mano{ // Representa la mano de cartas extraida
    char palo[10]; // el palo de la carta
    char numero[8]; // el numero de la carta
};

/*#############################*/
/*###Definicion de funciones###*/
/*#############################*/
//
//esta funcion crea el mazo
//mazo es un array de 52 cartas
void establecerMazo(struct Carta mazo[]){//Establece los valores de la baraja en el mazo
    char *Palos[4] = { "oros", "copas", "espadas", "bastos" }; //Las denominaciones del tipo de baraja
    for (int i = 0; i<CARTAS; i++){ //Itera sobre el numero de cartas del tipo de baraja
        char buffer[10];
        sprintf(buffer,"%d",i%13); //Funcion para convertir un valor numerico a un caracter.
        switch(i%13){ //Determina si el numero actual corresponde a un valor no n�merico dentro de la baraja por medio del modulo de 13
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
        mazo[i].suerte = rand() % 100;
        }
    };

void mostrarCartas(struct Carta mazo[]){ //Imprime todas las cartas en el mazo
    for (int i = 0; i<CARTAS; i++){
            printf("Palo:%s\t",mazo[i].palo);
            printf("Numero:%s\t",mazo[i].numero);
            printf("Tomada:%d\n",mazo[i].estado);
            printf("Suerte:%d\n",mazo[i].suerte);
    }

};

//no sé para que son los dos array de cartas
void sacarCartas(struct Carta mazo[],struct Carta mano[]){ //Saca 5 cartas aleatorias del mazo
    for (int i = 0; i < TOMA; i++){
        for(;;){ // Ciclo infinito hasta que encuentre una carta que no haya sido sacada
            int VA = rand() % CARTAS; //Valor Aleatorio para determinar la carta a sacar
            if (mazo[VA].estado == 0){
                    mazo[VA].estado = 1;
                    //printf("Palo:%s\tNumero:%s\n",mazo[VA].palo,mazo[VA].numero);
                    strcpy(mano[i].numero, mazo[VA].numero);
                    strcpy(mano[i].palo,mazo[VA].palo);
                    break;
            }
        }
    }
};

int isroyal(struct Carta mano[]){   //Verifica si existe una escalera real dentro de la mano
    int cont =0;                    //Contador de cartas que perfenecen a la escalera real
    if(strcmp(mano[0].palo, mano[1].palo)==0 && strcmp(mano[0].palo, mano[2].palo)==0 && strcmp(mano[0].palo, mano[3].palo)==0 && strcmp(mano[0].palo, mano[4].palo)==0){ //Verifica si todas las cartas son del mismo palo
        for (int i = 0; i<TOMA; i++){
            if(strcmp(mano[i].numero, "10")==0 || strcmp(mano[i].numero, "Jota")==0 || strcmp(mano[i].numero, "Rey")==0 || strcmp(mano[i].numero, "Reina")==0 || strcmp(mano[i].numero, "As")==0 ){ //Verifica si existe la combinacion de escalera real
                cont+=1;
            }
        }
    }
    if (cont==5){                   //Existen las 5 cartas que forman la escalera real?
       return 1;// printf("Es Escalera Real\n");
    }else{
        return 0;//printf("No es una escalera real\n");
    }
};

int isfullhouse(struct Carta mano[]){   //Verifica si existe un full house dentro de la mano
    int firstcount=1;                   //Contador del primer numero de carta observado
    int seccount=0;                     //Contador del segundo numero de carta observado
    char numsec[8] = "";

    for (int i = 1; i<TOMA; i++){       //Ciclo que recorre las 5 cartas del mazo
        if(strcmp(mano[0].numero, mano[i].numero)==0 ){ //Compara la primer carta con las demas
            firstcount+=1;                              //Si tienen el mismo numero, incrementa el contador
        }else if(strcmp(numsec, "")!=0 && strcmp(numsec, mano[i].numero)!=0){
            //Si la variable numsec ya fue asignada, entonces hay 3 numeros distintos, por lo tanto no puede haber un full house
            return 0;//printf("No es un fullhouse\n");
            break;
        }else{
            strcpy(numsec,mano[i].numero);  //Se asigna un segundo numero para hacer las comparaciones
            seccount +=1;
        }
    }
    if (seccount==3 && firstcount==2 || seccount==2 && firstcount==3){ //3 Y 2 son las unicas combinaciones posibles para full house
       return 1;// printf("Es un fullhouse\n");
    } else{
        return 0;//printf("No es un fullhouse\n");
    }
};


int isdouble(struct Carta mano[]){ //Verifica si existe un quad dentro de la mano
    int firstcount=1;   //Contador del primer numero de carta observado
    int seccount=0;     //Contador del segundo numero de carta observado
    int thirdcount=0;   //Contador del tercer numero de carta observado
    char numsec[8] = "";//Almacena el segundo dato observado
    char numthird[8] = "";//Almacena el tercer dato observado

    for (int i = 1; i<TOMA; i++){   //Recorre la mano
        if(strcmp(mano[0].numero, mano[i].numero)==0 ){ //Compara el primer numero de carta con los demas
            firstcount+=1;
        }else if(strcmp(numsec, "")!=0 && strcmp(numsec, mano[i].numero)!=0){//Ya se usò la variable y no coincide con la carta actual del ciclo?
            if(strcmp(numthird, "")!=0 && strcmp(numthird, mano[i].numero)!=0){//Ya se usò la variable y no coincide con la carta actual del ciclo?
                return 0;//printf("No es un double pair\n");
                break;  //No puede haber una combinacion de double
            }else{
                strcpy(numthird,mano[i].numero);  //Se copia el valor de la carta actual a numthird
                thirdcount +=1;
            }
        }else{
            strcpy(numsec,mano[i].numero);      //Se copia el valor de la carta actual a numsec
            seccount +=1;
        }
    }
    //Analiza las posibles combinaciones de un double pair
    if (firstcount==2 && seccount==2){
       return 1; //printf("Es un double pair\n");
    }else if (firstcount==2 && thirdcount==2){
       return 1; //printf("Es un double pair\n");
    }else if (thirdcount==2 && seccount==2){
        return 1; //printf("Es un double pair\n");
    }else{
        return 0;//printf("No es un double pair\n");
    }

};


int isquad(struct Carta mano[]){ //Verifica si existe un double dentro de la mano
    int firstcount=1;   //Contador del primer numero de carta observado
    int seccount=0;     //Contador del segundo numero de carta observado
    char numsec[8] = "";//ALmacena el segundo valor observado

    for (int i = 1; i<TOMA; i++){   //Recorre la mano de cartas
        if(strcmp(mano[0].numero, mano[i].numero)==0 ){ //Coinciden las cartas?
            firstcount+=1;
        }else if(strcmp(numsec, "")!=0 && strcmp(numsec, mano[i].numero)!=0){//Si no coinciden y la segunda variable fue usada, no puede existir un quad
            return 0;
            break;
        }else{
            strcpy(numsec,mano[i].numero); //Se asigna el numero de la carta a la variable
            seccount +=1;
        }
    }
    if (firstcount==4 || seccount==4){  //La primer o segunda carta se reite 4 veces?
       return 1;// printf("Es un quad\n");
    }else{
        return 0;//printf("No es un quad\n");
    }

};

#endif // TEST_H_INCLUDED
