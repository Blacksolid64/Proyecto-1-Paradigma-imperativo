#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED

#include "Mazo.h"
//struct Mazo;

struct Simulador {

    struct Mazo *mazo;//debe ser un puntero
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
    for (int i = 0 ; i<=simulador->m; i++ ){
        tirarManos(simulador);
        //sumo los contadores a totales
        //y los inicializo
    }
    //determino probabilidades
}

//recorre las n manos
void tirarManos (struct Simulador *simulador){ //
    for (int i = 0 ; i<=simulador->n; i++ ){
        //asumo que el mazo ya está formado
        //llamo a la funcion que me da 5 cartas
        //llamo a la funcion que determina cual jugada es
        //sumo a contadores de simulador

    }
}

void identificarMano (){

}
#endif // SIMULADOR_H_INCLUDED
