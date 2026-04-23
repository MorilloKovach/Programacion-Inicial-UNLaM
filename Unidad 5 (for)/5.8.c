/*
Confeccionar un programa que solicite el ingreso de unnúmero entero positivoN< 12 y luego
una lista de N números reales sobre la cual debe calcular:
a. El promedio de números ingresados positivos.
b. El promedio de números ingresados negativos.
c. La cantidad de ceros ingresada.
Si el valor ingresado N es mayor que 12 o si es menor o igual a 0, informar “CANTIDAD
INVALIDA” y a continuación finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    printf("\nIngrese N: ");
    scanf("%d", &N);
    if (N < 1 || N > 12)
    {
        printf("\nCANTIDAD INVALIDA");
        exit(0);
    }
    int sPos = 0, pos = 0;
    int sNeg = 0, neg = 0;
    int ceros = 0;
    for (int i = 0; i < N; i++)
    {
        int p;
        printf("\nIngrese el valor: ");
        scanf("%d", &p);
        if (p < 0)
            sNeg += p, neg++;
        else if (p > 0)
            sPos += p, pos++;
        else
            ceros++;
    }
    printf("El promedio de los numeros positivos es: %.2f",(float)sPos/pos*100.0);
    printf("El promedio de los numeros negativos es: %.2f",(float)sNeg/neg*100.0);
    printf("La cantidad de ceros es: %d",ceros);
}