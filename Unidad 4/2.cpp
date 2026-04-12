/*
Ingresar por teclado tres números enteros. Determinar e informar con un mensaje si el primer
número ingresado es menor que los otros dos.
*/

#include<stdio.h>

int main(){
    int a,b,c;
    printf("Ingrese los tres numeros: ");
    scanf("%d%d%d",&a,&b,&c);

    if(a<b && a < c){
        printf("El primer numero es mas chico que los otros dos posteriores.\n");
    }
    else{
        printf("El primer numero no es mas chico que los otros dos posteriores.\n");
    }
}