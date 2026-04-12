/*
Ingresar por teclado el valor de la hora y la cantidad de horas trabajadas por un empleado.
Calcular su sueldo tomando en cuenta que recibe un premio del 20% extra si trabajó más de 50
horas y, además, si trabajó más de 150 horas se le otorga un 10% adicional. Informar con
mensaje aclaratorio.
*/

#include<stdio.h>

int main(){
    int valor_hora, cantidad_horas;
    printf("Digite el valor de la hora: ");
    scanf("%d",&valor_hora);
    printf("\nDigite la cantidad de horas: ");
    scanf("%d",&cantidad_horas);
    int tot_valor = cantidad_horas * valor_hora;
    if(cantidad_horas >= 50){
        tot_valor *= 1.2;
    }
    if(cantidad_horas >= 150){
        tot_valor *= 1.1;
    }
    printf("El salario total del empleado es de: %d\n",tot_valor);
}
