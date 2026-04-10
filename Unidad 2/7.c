/*
Una pizzería vende empanadas por unidad o por docena. Como primer paso, se pide al usuario
que ingrese el precio por docena y el precio por unidad del día. Si se compran empanadas que
no se agrupen en docenas, las adicionales se cobran por unidad. Indicar con leyendas
aclaratorias, el precio total a abonar, ingresando la cantidad de empanadas vendidas.
*/

#include<stdio.h>

int main(){
    int precio_docena, precio_unidad, empanadas_vendidas;

    printf("Ingrese el precio de la docena de empanadas: ");
    scanf("%d",&precio_docena);

    printf("\nIngrese el precio de la unidad: ");
    scanf("%d",&precio_unidad);

    printf("\nIngrese la cantidad de empanadas compradas: ");
    scanf("%d",&empanadas_vendidas);

    int precio_total = empanadas_vendidas/12 * precio_docena + empanadas_vendidas%12 * precio_unidad;

    printf("\nEl precio total a abonar es de: $%d\n",precio_total);
}