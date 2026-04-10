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
    printf("El numero original de la fecha es %d y el nuevo es de %d%d%d%d%d%d\n",copiar_fecha,rescatar_anio1,rescatar_anio2,rescatar_mes1,rescatar_mes2,rescatar_dia1,rescatar_dia2);
}