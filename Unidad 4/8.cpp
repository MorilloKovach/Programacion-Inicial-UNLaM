/*
 La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la
siguiente escala:
a. Si es menor de $ 29550 el descuento es del 4.5%
b. Si está entre $ 29550 y $ 45000 el descuento es del 8%
c. Si es más de $ 45000 el descuento es del 10.5%
*/

#include<stdio.h>

int main(){
    float importe;
    printf("Ingrese el valor del importe: ");
    scanf("%f",&importe);
    if(importe < 29550) importe = importe - importe * 0.045;
    else if(importe >= 29550 && importe <= 45000) importe = importe - importe * 0.08;
    else importe = importe - importe * 0.105;

    printf("El valor final del importe es de %0.2f\n",importe);

}