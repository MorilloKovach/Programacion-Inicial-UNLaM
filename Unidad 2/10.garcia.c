/*
Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide
transformarlo a un número con formato (aammdd) e informar el número original y el
resultante con leyenda aclaratoria.
*/

#include<stdio.h>

int main(){
    int fecha, copiar_fecha;
    printf("Ingrese la fecha en formato (ddmmaa): ");
    scanf("%d",&fecha);
    copiar_fecha = fecha;
    int rescatar_anio2 = fecha%10;
    fecha/=10;
    int rescatar_anio1 = fecha%10;
    fecha/=10;
    int rescatar_mes2 = fecha%10;
    fecha/=10;
    int rescatar_mes1 = fecha%10;
    fecha/=10;
    int rescatar_dia2 = fecha%10;
    fecha/=10;
    int rescatar_dia1 = fecha;
    fecha = rescatar_dia2 + rescatar_dia1 * 10 + rescatar_mes2 * 100 + rescatar_mes1 * 1000 + rescatar_anio2 * 10000 + rescatar_anio1 * 100000;
    printf("El numero original de la fecha es %d y el nuevo es de %d\n",copiar_fecha,fecha);
}