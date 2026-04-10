/*
Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con
mensajes aclaratorios la suma, el producto, el cociente y el resto. Precondición: el segundo
número es distinto de cero.
*/

#include<stdio.h>
int main(){
    int num1,num2;
    int suma,resto,producto;
    float cociente;

    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&num2);

    suma = num1+num2;
    producto = num1*num2;
    cociente = (float)num1/num2;
    resto = num1%num2;

    printf("\nEl resultado de la suma es: %d",suma);
    printf("\nEl resultado del producto es: %d",producto);
    printf("\nEl resultado del cociente es: %.2f",cociente);
    printf("\nEl resultado de la resta es: %d\n",resto);
    return 0;
}