/*########################*/
#ifndef ESTADISTICA_H_INCLUDED //Evita que un archivo header sea procesado dos veces por el compilador
#define ESTADISTICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "conio.h"

double obtener_promedio(int cantidad, int *datos){
  double suma = 0;
  for (size_t i = 0; i < cantidad; i++) {
    suma += datos[i];
  }
  return suma / cantidad;
}

double obtener_varianza(int cantidad, int *datos){
  int n = cantidad;
  double promedio = obtener_promedio(n, datos);
  double varianza = 0;
  for (size_t i = 0; i < n; i++) {
    varianza += pow((datos[i] - promedio), 2.0);
  }
  return varianza / (n -1);
}

#endif // 