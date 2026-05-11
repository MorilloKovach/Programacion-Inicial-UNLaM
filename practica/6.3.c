#include<stdio.h>

int main(){
    int numero1,numero2;
    for(numero1=1;numero1<=5;numero1++){
        for(numero2=1;numero2<=5;numero2++){
            printf("La multiplicacion de %d por %d es: %d\n",numero1,numero2,numero1*numero2);
        }
    }
}