#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazo.h"
#include "Simulador.h"
int main()

{
    srand(time(NULL));
    struct Simulador s;
    iniciarSimulacion(&s);

    return 0;
}
