/*
    Una pizzería vende empanadas por unidad por docena. Como primer paso, se pide al usuario que ingrese el precio por docena y el precio por unidad del día. 
    Si se compran empanads que no se agrupen en docenas, las adicionales se cobran por unidad, indicar con leyendas aclaratorias, el precio total a abonar, ingresando la cantidad de empanas vendidas
*/

# include "stdio.h"

int main () {
    int precio_por_unidad;
    printf("Ingresar el precio por la unidad de la empanada\n");
    scanf("%d", &precio_por_unidad);
    
    int precio_por_docena;
    printf("Ingresar el precio por docena\n");
    scanf("%d", &precio_por_docena);
    
    int empanadas_quantity;
    printf("Y cuantas empanadas vas a llevar\n");
    scanf("%d", &empanadas_quantity);
    int resto = empanadas_quantity%12;

    int cantidadDocenas = empanadas_quantity/12;

    int docena_price = cantidadDocenas * precio_por_docena;
    int unidad_price = resto * precio_por_unidad;

    printf("El total a llevar es %d", docena_price + unidad_price);
}