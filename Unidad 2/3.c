/*
Se ingresan las notas de dos evaluaciones de un alumno de una materia. Determinar la nota
promedio del alumno.
*/
#include<stdio.h>

int main(){
    int nota1,nota2;
    printf("Ingresar las notas del alumno: ");
    scanf("%d%d",&nota1,&nota2);
    float promedio = (nota1+nota2)/2.;
    printf("La nota promedio del alumno es: %.2f\n",promedio);
}