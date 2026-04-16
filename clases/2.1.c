/*

Este es el problema de los ifs mal hechos

if(n1>=n2)
    if(n1==n2)
        resu = 1
else
    resu = 2

ESA CONCATENACIÓN DE IF ELSE NO ESTÁ BIEN, NO VA ORIENTADO AL PRIMER IF, VA AL SEGUNDO IF...

SIEMPRE ANIDAR, MIRAR 2.2.c
*/
#include <stdio.h>

int main()
{
    int num1, num2, resu = 0;
    printf("Ingrese dos numeros: ");
    printf("\nIngrese num1: ");
    scanf("%d", &num1);
    printf("\nIngrese num2: ");
    scanf("%d", &num2);
    if (num1 >= num2)
    {
        if (num1 == num2)
        {
            resu = 1;
        }
    }
    else
    {
        resu = 2;
    }

    printf("Resultado: %d\n", resu);
}