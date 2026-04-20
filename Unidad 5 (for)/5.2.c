/*
5.2.2 Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50.
*/

#include<stdio.h>

int main(){
    int suma = 0;
    for(int i = 100; i>=50; i-=5){
        suma+=i;
    }
    printf("La suma fue: %d",suma);
}