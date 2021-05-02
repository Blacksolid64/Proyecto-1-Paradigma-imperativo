/*########################*/
#ifndef PROBABILIDADES_H_INCLUDED //Evita que un archivo header sea procesado dos veces por el compilador
#define PROBABILIDADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int nCr(int n, int r) // Combinaciones
{
    return (factorial(n) / (factorial(r) * factorial(n - r))); // n! / r!*(n-r)!
}


double Prob_DosPares()
{
    int casosFavorables = nCr(13,2) * nCr(4,2) * nCr(4,2) * nCr(11,1) * nCr(4,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

double Prob_FullHouse()
{
    int casosFavorables = nCr(13,1) * nCr(4,3) * nCr(12,1) * nCr(4,2);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

double Prob_Quad()
{
    int casosFavorables = nCr(13,1) * nCr(48,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

double Prob_EscaleraReal()
{
    int casosFavorables = nCr(4,1);
    int casosPosibles   = nCr(52,5);
    double resultado = (double)casosFavorables / (double)casosPosibles;
    return resultado;
}

#endif // 