/*Se ingresan la cantidad de horas trabajadas y el valor en pesos por hora de un empleado.
Determinar el sueldo de dicho empleado con leyendas aclaratorias.*/

#include<stdio.h>

int main(){
    float valor_hora;
    printf("Ingresar el valor de la hora del empleado: ");
    scanf("%f",&valor_hora);

    int horas_trabajadas;
    printf("Ingresar las horas trabajadas del empleado: ");
    scanf("%d",&horas_trabajadas);

    float salario = horas_trabajadas*valor_hora;

    printf("El sueldo de dicho empleado es de: $%.2f\n",salario);
    
    return 0;
}