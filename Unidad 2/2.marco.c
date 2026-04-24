/*
    Se ingresan la cantidad de horas trabajadas y el valor de pesos por hora de un empleado. De terminar el sueldo de dicho empleado con leyendas aclaratorias.
*/
# include "stdio.h"

int main() {


    int horas;
    printf("Ingrese la cantidad de horas que trabaja por día \n");
    scanf("%d", &horas);

    int pesoPorHora = 0;
    printf("Ingrese los pesos que le pagan por hora \n");
    scanf("%d", &pesoPorHora);

    printf("El sueldo es %d$ ganados por %d horas al día", horas * pesoPorHora, horas);

    return 0;
}