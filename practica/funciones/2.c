/*
1.- Se necesita la cantidad de numeros 100 <= x <= 500
2.- La cantidad de pares entre 500 <= x <= 1200
3.- El promedio de los ingresados 1200 <= x <= 2000

Finaliza cuando se ingresa un numero igual a 99
*/
#include<stdio.h>

int main(){
    int numero, cantidad_100_500=0, cantidad_500_1200_pares=0, contador_1200_2000=0;
    float promedio = 0.0;
    do{
        printf("\nIngrese un numero: ");
        scanf("%d",&numero);
        if(numero!=99){
            if(numero >= 100 && numero <= 500){
                cantidad_100_500++;
            }
            else{
                if(numero>=500 && numero <= 1200 && numero%2==0){
                    cantidad_500_1200_pares++;
                }
                else{
                    if(numero>=1200 && numero <= 2000){
                        contador_1200_2000++;
                        promedio+=numero;
                    }
                }
            }
        }
    }while(numero != 99);

    printf("\nLa cantidad de numeros entre 100 y 500 es: %d",cantidad_100_500);
    printf("\nLa cantidad de pares entre 500 y 1200 es: %d",cantidad_500_1200_pares);
    printf("\nEl promedio de numeros entre 1200 y 2000 es: %.2f",promedio/contador_1200_2000);
}