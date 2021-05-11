#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED

#include "Mazo.h"
//struct Mazo;

struct Simulador {

    struct Carta mazo[CARTAS];//debe ser un puntero
    //contadores para cada n manos
    int countDoubles;//dos pares
    int countFull;//full house
    int countPoker;//cuatro iguales
    int countRoyal;//escalera real

    //para las diferentes simulaciones
    int countDoubles_total;//dos pares
    int countFull_total;//full house
    int countPoker_total;//cuatro iguales
    int countRoyal_total;//escalera real

    //por si acaso, se puede cambiar
    //dependiendo de donde se manejen
    int n;
    int m;

    int cantidadManos;
    //son las manos antes de volver a revolver
    //debe ir en mazo
};

//recorre las m simulaciones
void hacerSimulaciones (struct Simulador *simulador){

    for (int i = 0 ; i<simulador->m; i++ ){
        printf(" m %d",i);
        tirarManos(simulador);
        //sumo los contadores a totales
        //y los inicializo
        printf("\n");
    }
    //determino probabilidades
}

//recorre las n manos
void tirarManos (struct Simulador *simulador){ //
    for (int i = 0 ; i<simulador->n; i++ ){
            printf(" n %d",i);
        //asumo que el mazo ya está formado
        //llamo a la funcion que me da 5 cartas
        //llamo a la funcion que determina cual jugada es
        //sumo a contadores de simulador

    }
}

void identificarMano (){

}

void cargarDatos(struct Simulador *simulador){
    simulador->countDoubles = 0;
    simulador->countFull = 0;
    simulador->countPoker = 0;
    simulador->countRoyal = 0;

    simulador->countDoubles_total = 0;
    simulador->countFull_total = 0;
    simulador->countPoker_total = 0;
    simulador->countRoyal_total = 0;

    simulador->cantidadManos = 1;

    printf("Programa para simular eventos probabilisticos en C\n");
    printf("Ingrese el numero de Simulaciones : \n");
    scanf("%d",&simulador->m);
    printf("Ingrese el numero de Manos : \n");
    scanf("%d",&simulador->n);
    printf("m es : %d\n", simulador->m);
    printf("n es : %d\n", simulador->n);

    //tambien inicializa la mano


}

void iniciarSimulacion(struct Simulador *simulador){
    cargarDatos(simulador);
    hacerSimulaciones(simulador);

}
#endif // SIMULADOR_H_INCLUDED
