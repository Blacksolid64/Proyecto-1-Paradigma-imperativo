/*########################*/
#ifndef ESTADISTICA_H_INCLUDED //Evita que un archivo header sea procesado dos veces por el compilador
#define ESTADISTICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
//#include "conio.h"

/*
* Función:  Obtener la varianza
* Uso:  m = obtener_promedio( cantidad , datos );
* --------------------------------------------------------
* Calcula el valor promedio de un conjunto de datos numéricos,
* calculada como la suma del conjunto de valores dividida
* entre el número total de valores.
*/
double obtener_promedio(int cantidad, double *datos){
  double suma = 0;
  for (size_t i = 0; i < cantidad; i++) {
    suma += datos[i];
  }
  return suma / cantidad;
}

double obtener_promedio_b(int cantidad, double totalDatos){

    return totalDatos / cantidad;
}


/*
* Función:  Obtener la Varianza
* Uso:  m = obtener_varianza( cantidad , datos );
* --------------------------------------------------------
* Calcula la medida de dispersión que se utiliza para
* representar la variabilidad de un conjunto de datos
* respecto de la media aritmética de los mismo.
*/
double obtener_varianza(int cantidad, double *datos){
  int n = cantidad;
  double promedio = obtener_promedio(n, datos);
  double varianza = 0;
  for (size_t i = 0; i < n; i++) {
    //varianza += pow((datos[i] - promedio), 2.0);
  }
  return varianza / (n -1);
}


/*
double obtener_varianza_b(int repeticiones, int m, double datos){
    double promedio = obtener_promedio_b(repeticiones, datos);
    double varianza = 0;
    for(size_t i = 0; i < m; i++){
        varianza += pow((datos[i]-promedio),2.0);
    }
    return varianza / (repeticiones-1);
}*/

#endif //
