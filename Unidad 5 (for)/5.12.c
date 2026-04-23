/*
Una empresa les paga a sus 10 empleados con base en las horas trabajadas en la semana.
Para esto, se registra el código del empleado (entero) y las horas trabajadas en la semana.
Al comienzo de la carga, se ingresa por única vez el valor en pesos de la hora.
Determinar:
a) El sueldo semanal de cada empleado, informando código y sueldo.
b) El código del empleado que más sueldo cobró en la semana. 
c) El porcentaje de empleados que trabajaron menos de 20 horas en la semana.
d) El promedio de dinero pagado en sueldos a los empleados durante la semana.

*/
#include<stdio.h>
int main(){
    int valor_hora,codigo,horas_semanales, maxisueldo=0, codigomaxi=0, trabajan_menos_2hs=0, promedio_sueldos=0,sueldo;
    printf("Ingrese el valor hora: ");
    scanf("%d",&valor_hora);
    while(valor_hora <= 0){
        printf("\n¿Qué, tu empleado no cobra? Ingresa un valor: ");
        scanf("%d",&valor_hora);
    }
    for(int i = 0; i<10; i++){
        printf("\nIngrese el codigo del empleado: ");
        scanf("%d",&codigo);
        printf("\nIngrese la cantidad de horas semanales que trabaja este empleado: ");
        scanf("%d",&horas_semanales);
        sueldo = horas_semanales * valor_hora;
        printf("\nEl empleado con codigo %d posee un sueldo de $%d pesos a la semana",codigo, sueldo);
        if(sueldo > maxisueldo){
            sueldo = maxisueldo;
            codigomaxi = codigo;
        }
        if(horas_semanales < 20){
            trabajan_menos_2hs++;
        }
        promedio_sueldos+=sueldo;
    }
    printf("\nEl codigo de empleado que mas cobro en la semana fue: %d",codigomaxi);
    printf("\nEl porcentaje de empleados que trabajan menos de 20hs en la semana fue: %d%%",trabajan_menos_2hs*10);
    printf("\nEl promedio de dinero pagado en sueldos a los empleados en la semana fue: $%.2f",(float)promedio_sueldos/10);
}