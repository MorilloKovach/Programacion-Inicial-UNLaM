/*
Crear un programa que haga la suma de dos numeros. 
Debe hacerse por medio de la función suma. Las dos variables son enteras
*/

#include<stdio.h>

int sumar(int a, int b);
int resta(int a, int b);
int producto(int a, int b);
int main(){
    int numero1, numero2;
    printf("\nIngrese el numero 1: ");
    scanf("%d",&numero1);
    printf("\nIngrese el numero 2: ");
    scanf("%d",&numero2);
    printf("La suma del resultado es: %d\n",sumar(numero1,numero2));
    printf("\nLa resta del resultado es: %d\n",resta(numero1,numero2));
    printf("\nEl producto del resultado es: %d\n",producto(numero1,numero2));
    return 0;
}

int sumar(int a, int b){
    return a+b;
}

int resta(int a, int b){
    return a-b;
}

int producto(int a, int b){
    return a*b;
}