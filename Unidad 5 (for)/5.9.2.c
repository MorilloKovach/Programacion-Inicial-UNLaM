/*
Esta es la segunda version del 5.9 de la unidad 5 del for :)
*/

#include <stdio.h>

int main()
{
    int a, b, c,neg = 0,i;
    for (i = 0; i < 6; i++)
    {
        printf("\nIngrese el valor: ");
        scanf("%d", &a);
        printf("\nIngrese el valor: ");
        scanf("%d", &b);
        printf("\nIngrese el valor: ");
        scanf("%d", &c);
        if(a<0 && b < 0 && c < 0){
            neg++;
        }
    }
    printf("\nLa cantidad de ternas negativas es: %d",neg);

}