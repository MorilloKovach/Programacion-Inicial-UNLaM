/*
Una librería de artículos universitarios vende cuadernos A4 de una reconocida marca según la
siguiente escala de precios:
• Por unidad, a $ 9000 c/u.
• Por paquete de 10 cuadernos cuesta $ 80.000.-
• Por paquete de 30 cuadernos cuesta $ 250.000.-

Si la compra excede los 50 cuadernos se efectúa además un descuento del 10%.
Se pide que se ingrese una cantidad de cuadernos que se quiere comprar y calcule e informe
el importe a pagar.
*/

#include<stdio.h>

int main(){
    int cuadernos,maximo50,valor_tot;
    printf("Ingrese la cantidad de cuadernos: ");
    scanf("%d",&cuadernos);
    maximo50 = (cuadernos>=50);
    valor_tot = cuadernos/30 * 250000;
    cuadernos%=30;
    valor_tot = valor_tot + cuadernos/10 * 80000;
    cuadernos%=10;
    valor_tot = valor_tot + cuadernos * 9000;
    if(maximo50) valor_tot *= 0.9;
    printf("El total a pagar es de %d\n",valor_tot);
}