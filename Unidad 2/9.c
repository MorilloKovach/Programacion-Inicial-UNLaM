/*
 Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena e
informarlos con mensaje aclaratorio.
*/

#include<stdio.h>

int main(){
    int numero;
    printf("Digite el numero de 3 cifras: ");
    scanf("%d",&numero);
    int unidad = numero%10;
    numero/=10;
    int decenas = numero%10;
    numero/=10;
    int centenas = numero%10;
    numero/=10;
    printf("El numero de centenas del numero es de %d, el de decenas de %d, y el de unidades de %d\n", centenas,decenas,unidad);
}