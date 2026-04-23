/*
5.2.13 Elaborar un programa que lea 15 números reales e informe:
a) La sumatoria de los números leídos.
b) La productoria de los números leídos.
c) El promedio de los números leídos.
d) El mayor y el menor número leído.
e) El porcentaje de números mayores a 1000 que se ingresaron.
*/

#include<stdio.h>

int main(){
    float s = 0, p = 1, prom = 0,maxi,mini,maxiMayo1000=0;
    int band = 0;
    for(int i = 0; i<15; i++){
        float num;
        printf("\nIngrese el valor: ");
        scanf("%d",&num);
        s+=num;
        p*=num;
        if(!band){
            maxi = mini = num;
            band = 1;
        }
        if(maxi < num) maxi = num;
        if(mini > num) mini = num;
        if(num > 1000) maxiMayo1000++;
    }

    printf("\nLa sumatoria es %d",s);
    printf("\nEl producto de los numeros es: %d",p);
    printf("\nEl promedio de los numeros leidos es: %d",prom/15);
    printf("\nEl mayor numero es %d y el menor es %d",maxi, mini);
    printf("\nEl porcentaje de numeros mayores a 1000 que se ingresaron fue: %.2f",maxiMayo1000/15*100.0);

}