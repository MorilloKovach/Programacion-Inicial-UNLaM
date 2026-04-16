/*
 Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena e
informarlos con mensaje aclaratorio.
*/

#include<stdio.h>

int main(){
    int numero;
    printf("Digite el numero de 3 cifras: ");
    scanf("%d",&numero);
    printf("La cantidad de unidades es de: %d",numero%10);
    numero/=10;
    printf("La cantidad de decenas es de: %d",numero%10);
    numero/=10;
    printf("La cantidad de centenas es de: %d",numero%10);
}