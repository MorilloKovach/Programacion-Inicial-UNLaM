#include<stdio.h>

int main(){
    int a,b,c;
    printf("Digite los tres numeros");
    scanf("%d %d %d",&a,&b,&c);
    if(a < b && a < c){
        printf("El primer numero es menor a los otros dos");
    }
    else{
        printf("O es mayor a alguno o hay empate");
    }
}

/*
Ingresar por teclado tres números enteros. Determinar e informar con un mensaje si el primer
número ingresado es menor que los otros dos.

a < b y a < c
*/