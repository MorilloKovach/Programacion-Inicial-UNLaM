#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int cantidadPrimos, contadorPrimos, i, numero=2;
    bool band=true, esPrimo;

    do{
        if(band){
            printf("\nIngrese la cantidad de primos: ");
            scanf("%d",&cantidadPrimos);
            band=false;
        }
        else{
            printf("Por favor, ingrese una cantidad valida. ");
            band = true;
        }
    }while(cantidadPrimos <= 0);
    contadorPrimos = 0;
    while(contadorPrimos < cantidadPrimos){
        esPrimo = true;
        i = 2;
        while(esPrimo && i < numero){
            if(numero%i==0){
                esPrimo = false;
            }
            i++;
        }
        if(esPrimo){
            contadorPrimos++;
            printf("\nEl primo es %d",numero);
        }
        numero++;
    }
    printf("\n");
}