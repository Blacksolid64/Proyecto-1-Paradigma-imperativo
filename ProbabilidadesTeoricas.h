/*########################*/
#ifndef PROBABILIDADES_H_INCLUDED //Evita que un archivo header sea procesado dos veces por el compilador
#define PROBABILIDADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Función: factorial
* Uso:  f = factorial(n);
* --------------------------------------------------
* Esta función devuelve el factorial f del número n.
*/
double factorial(int n)
{
    double resultado = 1.0, i;
    if (n > 1)
    {
        for (i = 2; i <= n; i++)
        {
            resultado *= i; /* Esta expresion es una abreviatura de
                                        resultado=resultado*i; */
        }
    }
    return resultado;
}

/*
* Función: combinaciones
* Uso:  c = nCr(n,r);
* --------------------------------------------------------
* Esta función devuelve el valor de la función matemática
* combinaciones(n,r), esto es el número de formas distintas
* en que se pueden elegir z elementos a partir de un conjunto
* de n elementos.
* Función matemática del factorial:
*     n! / ( r! * (n-r)! ) 
*/
int nCr(int n, int r) // Combinaciones
{
    return (factorial(n) / (factorial(r) * factorial(n - r))); // n! / r!*(n-r)!
}

/*
* Función:  Probabilidad de Dos Pares
* Uso:  p = Prob_DosPares();
* --------------------------------------------------------
* Esta función devuelve el valor de la función matemática
* de la probabilidad de obtener la combinación de cartas,
* entre el numero de casos posibles
* Función matemática de probabilidad:
*    (13 nCr 2) * (4 nCr 2) * (4 nCr 2) * (11 nCr 1) * (4 nCr 1) / (52 nCr 5) 
*/
double Prob_DosPares()
{
    int casosFavorables = nCr(13,2) * nCr(4,2) * nCr(4,2) * nCr(11,1) * nCr(4,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

/*
* Función:  Probabilidad de Full House
* Uso:  p = Prob_FullHouse();
* --------------------------------------------------------
* Esta función devuelve el valor de la función matemática
* de la probabilidad de obtener la combinación de cartas,
* entre el numero de casos posibles
* Función matemática de probabilidad:
*    (13 nCr 1) * (4 nCr 3) * (12 nCr 1) * (4 nCr 2) / (52 nCr 5) 
*/
double Prob_FullHouse()
{
    int casosFavorables = nCr(13,1) * nCr(4,3) * nCr(12,1) * nCr(4,2);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

/*
* Función:  Probabilidad de Quad
* Uso:  p = Prob_Quad();
* --------------------------------------------------------
* Esta función devuelve el valor de la función matemática
* de la probabilidad de obtener la combinación de cartas,
* entre el numero de casos posibles
* Función matemática de probabilidad:
*    (13 nCr 1) * (48 nCr 1) / (52 nCr 5) 
*/
double Prob_Quad()
{
    int casosFavorables = nCr(13,1) * nCr(48,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

/*
* Función:  Probabilidad de Escalera Real
* Uso:  p = Prob_EscaleraReal();
* --------------------------------------------------------
* Esta función devuelve el valor de la función matemática
* de la probabilidad de obtener la combinación de cartas,
* entre el numero de casos posibles
* Función matemática de probabilidad:
*    (4 nCr 1) / (52 nCr 5) 
*/
double Prob_EscaleraReal()
{
    int casosFavorables = nCr(4,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

#endif // 