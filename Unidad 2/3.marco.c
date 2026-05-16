/*
    Se ingresan las notas de dos evaluacionesde un alumno de una materia. Determinar la nota promedio del alumno
*/
#include "stdio.h"

int main() {
    int exam1;
    int exam2;

    printf("Ingrse la nota del examen 1\n");
    scanf("%d", &exam1);

    printf("Ingrse la nota del examen 2\n");
    scanf("%d", &exam2);

    printf("La nota promedio es %d \n", (exam1 + exam2)/2);
    // -- la cantidad posible de if statements es igual a la cantidad de salidas -1

}