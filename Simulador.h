#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#include "Mazo.h"
#include "Estadistica.h"
#include "ProbabilidadesTeoricas.h"
//constante para el maximo de simulaciones
#define MAX 99999

//estrucutra que llevara el mazo
//el conteo de cada mano, media y varianza en cada simulacion
struct Simulador {

    struct Carta mazo[CARTAS];//debe ser un puntero
    //contadores para cada n manos
    double countDoubles[MAX];//dos pares
    double countFull[MAX];//full house
    double countPoker[MAX];//cuatro iguales
    double countRoyal[MAX];//escalera real


    int countDoubles_total;//dos pares
    int countFull_total;//full house
    int countPoker_total;//cuatro iguales
    int countRoyal_total;//escalera real

    //por si acaso, se puede cambiar
    //dependiendo de donde se manejen
    int n;
    int m;
    int i;

    int criterioReestablecimiento;//Definido en la funcion Tirar Cartas
    //son las manos antes de volver a revolver
    //debe ir en mazo
};
/*
Función : identificarMano
uso : identificarMano(mimano, simulador)
---------------------------------------------
identifica cual mano existe en "mimano"
y suma en el contador dentro de la estructura "simulador"
*/
void identificarMano (struct Carta mimano[],struct Simulador *simulador){
    int a = isroyal(mimano);
    int b = isfullhouse(mimano);
    int c = isquad(mimano);
    int d =isdouble(mimano);
    simulador->countRoyal_total += a;
    simulador->countFull_total += b;
    simulador->countPoker_total += c;
    simulador->countDoubles_total += d;

    int i = simulador->i;

    simulador->countDoubles[i] += d;
    simulador->countFull[i] += b;
    simulador->countPoker[i] += c;
    simulador->countRoyal[i] += a;
}

/*
Funcion : tirarManos
Uso : tirarManos(simulador)
-------------------------------- -------------------
recorre las n manosde cartas en la simulacion
*/
void tirarManos (struct Simulador *simulador){
    //int CriterioReestablecimiento = 10; //Establece un criterio para el reestablecimiento del mazo de cartas
    struct Carta mimano[TOMA];
    for (int i = 0 ; i<simulador->n; i++ ){ //Reestablece las cartas cada vez que se llama
        if (i % simulador->criterioReestablecimiento == 0){
                establecerMazo(simulador->mazo);}
        sacarCartas(simulador->mazo,mimano);  //llamo a la funcion que me da 5 cartas
        identificarMano(mimano,simulador); //llamo a la funcion que determina cual jugada es
        //sumo a contadores de simulador

    }
}

/*
Funcion : printProgress
Uso : printProgress(percentage)
---------------------------------------------------
Imprime la barra de progreso de la simulacion
*/
void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

/*
Funcion : hacerSimulaciones
Uso : hacerSimulaciones(simulador)
---------------------------------------------------
recorre las m simulaciones y dentro llama
a tirar manos
*/
//recorre las m simulaciones
void hacerSimulaciones (struct Simulador *simulador){
    printf("Simulación iniciada! Por favor espere...%d * %d\n",simulador->m,simulador->n);
    for (int i = 0 ; i<simulador->m; i++ ){
        simulador->i = i;
        double progress = ((double)(i+1)/(double)simulador->m); //Calcula el porcentaje que se ha completado de la simulacion
        printProgress(progress); // Muestra el porcentaje de la simulacion
        tirarManos(simulador);
        //sumo los contadores a totales
        //y los inicializo
    }
    printf("\nSimulación completada!\nGracias por su paciencia!\n");
    printf("Los datos encontrados en %d simulaciones con %d manos sacadas por simulacion son los siguientes:\n",simulador->m,simulador->n);
    printf("Dobles:%d\nFullhouse:%d\nPoker:%d\nEscalera Real:%d\n",simulador->countDoubles_total,simulador->countFull_total,simulador->countPoker_total,simulador->countRoyal_total);
    //determino probabilidades
}

/*
Funcion : limpiarArrays
Uso : limpiarArrays(simulador)
---------------------------------------------------
limpia los primeros m campos en el array dejandolos en cero
*/
void limpiarArrays (struct Simulador *simulador){
    for(int i = 0; i<=simulador->m;i++){

        simulador->countDoubles[i] = 0;
        simulador->countFull[i] = 0;
        simulador->countPoker[i] = 0;
        simulador->countRoyal[i] = 0;

    }
}

/*
Funcion : cargarDatos
Uso : cargarDatos(simulador)
---------------------------------------------------
incializa los datos de la estructura "simulador"
y solicita la cantidad m de Simulaciones
y la cantidad n de manos
*/
void cargarDatos(struct Simulador *simulador){

    simulador->countDoubles_total = 0;
    simulador->countFull_total = 0;
    simulador->countPoker_total = 0;
    simulador->countRoyal_total = 0;

    simulador->criterioReestablecimiento = 10;
    simulador->i = 0;

    printf("Programa para simular eventos probabilisticos en C\n");
    printf("Ingrese el numero de Simulaciones no mayor a %d: \n", MAX);
    scanf("%d",&simulador->m);

    printf("Ingrese el numero de Manos : \n");
    scanf("%d",&simulador->n);

    printf("Numero de simulaciones es : %d\n", simulador->m);
    printf("Numero de manos por simulacion es : %d\n", simulador->n);

    limpiarArrays(simulador);

    establecerMazo(simulador->mazo);
}

/*
Funcion : calcularEstadisticas
Uso : calcularEstadisticas(simulador)
---------------------------------------------------
presenta todos los datos recolectados
*/
void calcularEstadisticas (struct Simulador *simulador){

    printf("\n****** Probabilidad de Dobles*****\n");
    printf("Media Experimental  :%f%%\n", obtener_promedio_b(simulador->m * simulador->n,simulador->countDoubles_total)*100);
    printf("Varianza            :%f%%\n", obtener_varianza_b(simulador->m* simulador->n,simulador->m,simulador->countDoubles)*100);
    printf("Prob. teorica       :%f%%\n", Prob_DosPares()*100);
    printf("Error de la media   :%f%%\n", (fabs(Prob_DosPares()-obtener_promedio_b(simulador->m * simulador->n,simulador->countDoubles_total))/Prob_DosPares())*100);


    printf("\n****** Probabilidad de FullHouse*****\n");
    printf("Media Experimental  :%f%%\n", obtener_promedio_b(simulador->m * simulador->n,simulador->countFull_total)*100);
    printf("Varianza            :%f%%\n", obtener_varianza_b(simulador->m* simulador->n,simulador->m,simulador->countFull)*100);
    printf("Prob. teorica       :%f%%\n", Prob_FullHouse()*100);
    printf("Error de la media   :%f%%\n", (fabs(Prob_FullHouse()-obtener_promedio_b(simulador->m * simulador->n,simulador->countFull_total))/Prob_FullHouse())*100);


    printf("\n****** Probabilidad de Quad*****\n");
    printf("Media Experimental  :%f%%\n", obtener_promedio_b(simulador->m * simulador->n,simulador->countPoker_total)*100);
    printf("Varianza            :%f%%\n", obtener_varianza_b(simulador->m* simulador->n,simulador->m,simulador->countPoker)*100);
    printf("Prob. teorica       :%f%%\n", Prob_Quad()*100);
    printf("Error de la media   :%f%%\n", (fabs(Prob_Quad()-obtener_promedio_b(simulador->m * simulador->n,simulador->countPoker_total))/Prob_Quad())*100);


    printf("\n****** Probabilidad de Escalera Real*****\n");
    printf("Media Experimental  :%f%%\n", obtener_promedio_b(simulador->m * simulador->n,simulador->countRoyal_total)*100);
    printf("Varianza            :%f%%\n", obtener_varianza_b(simulador->m* simulador->n,simulador->m,simulador->countRoyal)*100);
    printf("Prob. teorica       :%f%%\n", Prob_EscaleraReal()*100);
    printf("Error de la media   :%f%%\n", (fabs(Prob_EscaleraReal()-obtener_promedio_b(simulador->m * simulador->n,simulador->countRoyal_total))/Prob_EscaleraReal())*100);


}

/*
Funcion : iniciarSimulacion
Uso : iniciarSimulacion(simulador)
---------------------------------------------------
tiene las funciones necesarias para desarrollar el programas
*/
void iniciarSimulacion(struct Simulador *simulador){
    printf("Iniciando simulación:\n");
    cargarDatos(simulador);
    hacerSimulaciones(simulador);
    calcularEstadisticas(simulador);
    //Comentado por que tengo un error con la libreria conio.h; dice que no existe en el sistema
    printf("\n****** Probabilidad Teorica *****\n");

    double EscaleraReal = Prob_EscaleraReal();
    printf("Probabilidad de EscaleraReal: %lf %% \n",EscaleraReal*100);

    double Quad = Prob_Quad();
    printf("Probabilidad de Quad:         %lf %% \n",Quad*100);

    double FullHouse = Prob_FullHouse();
    printf("Probabilidad de FullHouse:    %lf %% \n",FullHouse*100);

    double DosPares = Prob_DosPares();
    printf("Probabilidad de Dos Pares:    %lf %% \n",DosPares*100);



}
#endif // SIMULADOR_H_INCLUDED
