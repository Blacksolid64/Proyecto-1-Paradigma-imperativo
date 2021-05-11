#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazo.h"

int main()
{
    int m;
    struct Mazo mimazo[CARTAS];
    struct Mano mimano[CARTAS];

    establecerMazo(mimazo);
    //mostrarCartas(mimazo);
    sacarCartas(mimazo,mimano);
    isroyal(mimano);
    isfullhouse(mimano);
    isquad(mimano);
    isdouble(mimano);
    printf("Programa para simular eventos probabilisticos en C\n");
    printf("Ingrese el numero de Simulaciones\n");
    scanf("%d",&m);
    return 0;
}
