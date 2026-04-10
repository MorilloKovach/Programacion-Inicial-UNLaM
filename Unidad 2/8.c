/*
Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%.
Confeccionar un programa que recibiendo el precio original y un código que indica si es o no
con descuento (0 no aplica el descuento y 1 aplica el descuento). Informe con leyenda
aclaratoria el precio final.
*/

#include<stdio.h>

int main(){
    int descuento, precio;
    printf("Ingrese el precio original del producto: ");
    scanf("%d",&precio);
    printf("\nIngrese si esta habilitado a descuento o no: ");
    scanf("%d",&descuento);

    int valor_final = precio - (descuento * (precio * 0.2));

    printf("\nEl valor final del precio es de: $%d\n",valor_final);
}