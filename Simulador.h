#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#include "Mazo.h"
//#include "ProbabilidadesTeoricas.h"
//#include "Estadistica.h"
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

    int cantidadManos;//Definido en la funcion Tirar Cartas
    //son las manos antes de volver a revolver
    //debe ir en mazo
};

//recorre las m simulaciones
void hacerSimulaciones (struct Simulador *simulador){
    printf("Simulación iniciada! Por favor espere...\n");
    for (int i = 0 ; i<simulador->m; i++ ){
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

//recorre las n manos de cartas en la simulacion
void tirarManos (struct Simulador *simulador){
    int CriterioReestablecimiento = 10; //Establece un criterio para el reestablecimiento del mazo de cartas
    struct Carta mimano[TOMA];
    for (int i = 0 ; i<simulador->n; i++ ){ //Reestablece las cartas cada vez que se llama
        if (i % CriterioReestablecimiento == 0){
                establecerMazo(simulador->mazo);}
        sacarCartas(simulador->mazo,mimano);  //llamo a la funcion que me da 5 cartas
        identificarMano(mimano,simulador); //llamo a la funcion que determina cual jugada es
        //sumo a contadores de simulador

    }
}
//Imprime la barra de progreso de la simulacion
void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}


void identificarMano (struct Carta mimano[],struct Simulador *simulador){
    int a = isroyal(mimano);
    int b = isfullhouse(mimano);
    int c = isquad(mimano);
    int d =isdouble(mimano);
    simulador->countRoyal_total += a;
    simulador->countFull_total += b;
    simulador->countPoker_total += c;
    simulador->countDoubles_total += d;
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
    printf("Numero de simulaciones es : %d\n", simulador->m);
    printf("Numero de manos por simulacion es : %d\n", simulador->n);
    establecerMazo(simulador->mazo);
}

void iniciarSimulacion(struct Simulador *simulador){
    printf("Iniciando simulación:\n");
    cargarDatos(simulador);
    hacerSimulaciones(simulador);
    //Comentado por que tengo un error con la libreria conio.h; dice que no existe en el sistema
    /*printf("\n****** Probabilidad Teorica *****\n");

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
    printf("La varianza:                  %f \n",varianza);*/

}
#endif // SIMULADOR_H_INCLUDED
