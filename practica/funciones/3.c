#include<stdio.h>

int EstaDentroDelRango(int,int,int);
int LeerYValidar(int, int, int);
int main(){
    int numero, cant_100_500=0, cant_500_1200_pares=0, cant_1200_2000=0;
    float promedio=0.0;
    do{
        numero = LeerYValidar(100,2000,99);
        if(numero != 0){
            if(EstaDentroDelRango(100,500,numero)){
                cant_100_500++;
            }
            else{
                if(EstaDentroDelRango(500,1200,numero) && numero%2==0){
                    cant_500_1200_pares++;
                }
                else{
                    if(EstaDentroDelRango(1200,2000,numero)){
                        cant_1200_2000++;
                        promedio+=numero;
                    }
                }
            }
        }
    }while(numero != 0);
    printf("\nLa cantidad de numeros entre 100 y 500 es: %d",cant_100_500);
    printf("\nLa cantidad de pares entre 500 y 1200 es: %d",cant_500_1200_pares);
    printf("\nEl promedio de numeros entre 1200 y 2000 es: %.2f",promedio/cant_1200_2000);
}

int EstaDentroDelRango(int limite_inferior, int limite_superior, int numero){
   return limite_inferior <= numero && numero <= limite_superior;
}

int LeerYValidar(int limite_inferior, int limite_superior, int fin){
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d",&numero);
    while(!EstaDentroDelRango(limite_inferior, limite_superior, numero) && numero != fin){
        printf("\nIngrese un numero: ");
        scanf("%d",&numero);
    }
    if(numero==fin) return 0;
    return numero;
}