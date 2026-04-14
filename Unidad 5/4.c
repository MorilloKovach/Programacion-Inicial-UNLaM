/*
En un proceso de control científico se evalúan valores de temperatura, finalizando cuando de
ingresa un valor ficticio de temperatura -50. Determinar el valor máximo y mínimo medido y
sus posiciones respecto al ingreso.
*/

#include<stdio.h>

int main(){
    int maxi = -999;
    int mini = 999;
    int maxiMed = 0;
    int miniMed = 0;
    int t;
    int i = 1;
    scanf(" %d",&t);
    while(t != -50){
        if(t > maxi){
            maxi = t;
            maxiMed = i;
        }
        if(t < mini){
            mini = t;
            miniMed = i;
        }
        i++;
        scanf(" %d",&t);
    }
    printf("La minima temperatura se obtuvo en la posicion %d con una temperatura de %d\n",miniMed,mini);
    printf("La maxima temperatura se obtuvo en la posicion %d con una temperatura de %d\n",maxiMed,maxi);
}