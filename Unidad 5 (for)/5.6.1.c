/*
5.2.6 Dadas los legajos y las notas de 20 alumnos de un curso, determinar:
a. La cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha
Promocionado”.
c. El promedio de notas de los alumnos que han sido enviados a final, con por lo
menos dos decimales en dicho promedio.
*/
#include<stdio.h>


int main(){
    int a,b, s = 0,c = 0, aplazados=0,i;
    for(i = 0; i<20; i++){
        printf("\nIngrese el legajo del alumno: ");
        scanf("%d",&b);
        printf("\nIngrese la nota del alumno: ");
        scanf("%d",&a);
        while(a < 1 || a > 10){
            printf("\nIngrese una nota valida: ");
            scanf("%d",&a);
        }
        if (a>=7){
            printf("\nEl alumno con legajo %d ha promocionado ",b);
        }
        else if(a >= 4 && a < 7){
            s+=a;
            c++;
        }
        else aplazados++;
    }
    printf("\nLa cantidad de alumnos aplazados fue: %d",aplazados);
    printf("\nEl promedio de notas de los alumnos que fueron enviados a final es de: %.2f",(float)s/c);


}