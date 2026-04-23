/*
5.2.11 Escriba un programa que pregunte cuántos números se van a introducir, pida esos números,
y realice los siguiente:
a) Informe el mayor valor ingresado y en qué posición se ingresó.
b) Informar el menor valor ingresado con la posición de ingreso.
c) Informar la media aritmética. Se recuerda que la media aritmética de un conjunto
de valores es la suma de esos valores dividida por la cantidad de valores.
d) Informar el promedio de los valores negativos.
e) Informar el porcentaje de valores positivos ingresados respecto del total de
números ingresados.
*/

#include<stdio.h>

int main(){
    int N;
    printf("\nIngrese la cantidad de valores: ");
    scanf("%d",&N);
    int max_val=-9999999, pos_max_val=0;
    int min_val=999999, pos_min_val=0;
    int prom = 0;
    int prom_neg = 0, neg=0;
    int posi = 0;
    for(int i = 0; i<N; i++){
        int c;
        printf("\nIngrese un valor: ");
        scanf("%d",&c);
        prom+=c;
        if(c<0){
            prom_neg+=c;
            neg++;
        }
        if(max_val < c){
            max_val = c;
            pos_max_val = i+1;
        }
        if(min_val > c){
            min_val = c;
            pos_min_val = i+1;
        }
        if(c>0){
            posi++;
        }
    }
    printf("\nEl mayor valor ingresado es el %d en la posicion %d",max_val, pos_max_val);
    printf("\nEl menor valor ingresado es el %d y en la posicion %d",min_val, pos_min_val);
    printf("\nLa media aritmetica es %d",prom/N);
    printf("\nEl promedio de los valores negativos es: %d",prom_neg/neg);
    printf("\nEl porcentaje de valores positivos respecto a los ingresados es: %.2f",(float)posi/N*100.0);
}