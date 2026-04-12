/*
Confeccionar un programa que pueda determinar de tres números enteros que se ingresan
por teclado, si alguno de ellos es igual a la suma de los otros dos. Informar con leyenda
aclaratoria.
*/

#include<stdio.h>

int main(){
    int a,b,c;
    printf("Ingrese los tres numeros: ");
    scanf("%d%d%d",&a,&b,&c);

    if(a==b+c){
        printf("El %d es equivalente a %d+%d",a,b,c);
    }
    else if(b==a+c){
        printf("El %d es equivalente a %d+%d",b,a,c);
    }
    else if(c==a+b){
        printf("El %d es equivalente a %d+%d",c,a,b);
    }
    else{
        printf("No hay un numero que valga la suma de los otros dos...");
    }
    printf("\n");
}