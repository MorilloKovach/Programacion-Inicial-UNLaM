/*
Se ingresan 50 números enteros. Determinar el promedio de los números pares.
*/

#include<stdio.h>

int main(){
    int num=0,sum=0, pares=0;
    for(int i = 0; i<50; i++){
        printf("\nIngrese un numero: ");
        scanf("%d",&num);
        sum+=(num%2==0?num:0);
        pares+=(num%2==0);
    }

    printf("\nEl numero promedio de los pares es: %.2f",sum/pares);

}