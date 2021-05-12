#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazo.h"
#include "ProbabilidadesTeoricas.h"
#include "Estadistica.h"

int main()
{
	
    int m;
    struct Carta mimazo[CARTAS];
    //la mano deberia ser de 5 cartas, nada más
    struct Carta mimano[CARTAS];

    establecerMazo(mimazo);
    //mostrarCartas(mimazo);
    sacarCartas(mimazo,mimano);
    isroyal(mimano);
    isfullhouse(mimano);
    isquad(mimano);
    isdouble(mimano);
    printf("Programa para simular eventos probabilisticos en C\n");
    printf("Ingrese el numero de Simulaciones\n");
    /*scanf("%d",&m);*/
    
    printf("\n****** Probabilidad Teorica *****\n");

    double EscaleraReal = Prob_EscaleraReal();
    printf("Probabilidad de EscaleraReal: %lf %% \n",EscaleraReal*100);

    double Quad = Prob_Quad();
    printf("Probabilidad de Quad:         %lf %% \n",Quad*100);

    double FullHouse = Prob_FullHouse();
    printf("Probabilidad de FullHouse:    %lf %% \n",FullHouse*100);

    double DosPares = Prob_DosPares();
    printf("Probabilidad de Dos Pares:    %lf %% \n",DosPares*100);

    printf("\n****** Metodos Estadisticos *****\n");

    double datos[5] = {19.2, 10.6, 8.7, 17.9, 9.4};
    printf("\ndouble datos[5] = {19.2, 10.6, 8.7, 17.9, 9.4};\n");

    double media = obtener_promedio(5, datos);
    printf("La media:                     %f \n",media);

    double varianza = obtener_varianza(5, datos);
    printf("La varianza:                  %f \n",varianza);

    return 0;
}
