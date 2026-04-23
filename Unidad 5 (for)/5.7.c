/*
Dadas las edades y estaturas de 45 alumnos de un curso, determinar:
a. La edad promedio del curso.
b. La estatura promedio del curso.
c. La cantidad de alumnos mayores de 10 años.
d. El porcentaje de alumnos que miden menos de 1.40 cm.
*/

#include<stdio.h>

int main(){
    int edad_prom=0;
    float est_prom=0;
    int cant_al=0;
    int midmen=0;
    for(int i = 0; i<45; i++){
        int edad;
        printf("\nIngrese la edad del alumno %d: ",i+1);
        scanf("%d",&edad);
        edad_prom+=edad;
        float est;
        printf("\nIngrese la estatura del alumno: ");
        scanf("%f",&est);
        if(edad>=10) cant_al++;
        if(est <= 1.4) midmen++;
    }
    printf("\nLa edad promedio del curso es: %d",edad_prom/45);
    printf("\nLa estatura promedio del curso es: %.2f",est_prom/45);
    printf("\nLa cantidad de alumnos mayores a 10 años son de: %d",cant_al);
    printf("\nEl porcentaje de alumnos que miden menos de 1.4m miden: %.2f%%",midmen/45.0*100.0);

}