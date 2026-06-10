#include <stdio.h>

int main()
{
    int vector[5],i;
    //[0...4]
    /*printf("\nIngrese el numero: ");
    scanf("%d", &vector[0]);
    printf("\nIngrese el numero: ");
    scanf("%d", &vector[1]);
    printf("\nIngrese el numero: ");
    scanf("%d", &vector[2]);
    printf("\nIngrese el numero: ");
    scanf("%d", &vector[3]);
    printf("\nIngrese el numero: ");
    scanf("%d", &vector[4]);
    printf("Los numeros son %d %d %d %d %d",vector[0], vector[1], vector[2], vector[3], vector[4]);
    */
    for(i=0;i<5;i++){
        printf("\nIngrese el numero: ");
        scanf("%d",&vector[i]);
    }
    printf("Los numeros son ");
    for(i=0;i<5;i++){
        printf("%d ",vector[i]);
    }

}