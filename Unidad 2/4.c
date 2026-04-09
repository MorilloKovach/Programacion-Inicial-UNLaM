/*
Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a: yardas,
pulgadas, centímetros y metros. Informar con mensajes aclaratorios. NOTA: 1 pie = 12
pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.
*/
#include<stdio.h>

int main(){
    int pie;
    printf("Ingrese la medida en pies: ");
    scanf("%d",&pie);

    int pulgadas = pie * 12;

    int yardas = pie * 3;

    float centimetros = pulgadas*2.54;
    float metros = centimetros*100;

    printf("El valor de la medida en pulgadas es: %d\n",pulgadas);
    printf("El valor de la medida en yardas es: %d\n",yardas);
    printf("El valor de la medida en centimetros es: %.2f\n",centimetros);
    printf("El valor de la medida en metros es: %.2f\n",metros);
}