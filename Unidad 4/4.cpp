/*
Se ingresan tres números enteros por teclado. Informarlos en orden creciente (de menor a
mayor).
*/

#include<stdio.h>

int main(){
    int a,b,c;
    printf("Ingrese los tres numeros: ");
    scanf("%d%d%d",&a,&b,&c);
    int aux;
    if(b>c){
        aux = c;
        c = b;
        b = aux;
    }
    if(a>c){
        aux = c;
        c = a;
        a = aux;
    }
    if(a>b){
        aux = b;
        b = a;
        a = aux;
    }

    printf("Los numeros en orden creciente son: %d, %d y %d\n",a,b,c);
}