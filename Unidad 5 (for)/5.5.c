/*
Ingresar un número entero positivo N y luego ingresar N números naturales. Determinar e
informar:
• La sumatoria de los valores múltiplos de 3.
• La cantidad de valores múltiplos de 5.
• La sumatoria de los valores que se ingresan en orden par.
*/

#include<stdio.h>

int main(){
    int N;

    printf("Ingresa N: ");
    scanf("%d",&N);
    int suma_pares = 0;
    int val_mul_5 = 0;
    int suma_mul3 = 0;
    while(N<=0){
        printf("\nIngrese un valor positivo: ");
        scanf("%d",&N);
    }
    for(int i = 0; i<N; i++){
        int a;
        printf("\nIngrese el numero %d: ",i+1);
        scanf("%d",&a);
        if((i+1)%2==0) suma_pares+=a;
        if(a%3==0) suma_mul3+=a;
        if(a%5==0) val_mul_5++;
    }
    printf("\nLa sumatoria de todos los valores múltiplos de 3 es: %d",suma_mul3);
    printf("\nLa cantidad de valores de multiplos de 5 es: %d",val_mul_5);
    printf("\nLa sumatoria de los valores ingresados en orden par es: %d",suma_pares);

}