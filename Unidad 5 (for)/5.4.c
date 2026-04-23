/*
Confeccionar un programa para calcular la suma de los primeros N números naturales. El valor
de N lo solicita por teclado el programa.
*/

#include<stdio.h>

int main(){
    int suma = 0,N,s,i;
    printf("Digite el valor de N: ");
    scanf("%d",&N);
    for(i = 0; i<N; i++){
        printf("\nIngrese el valor del numero: ");
        scanf("%d",&s);
        suma+= (s > 0 ? s : 0);
    }
    printf("\nLa suma fue: %d",suma);
}