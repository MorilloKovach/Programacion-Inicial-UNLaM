#include <stdio.h>

void ponerCero(int leg[], int sue[], int n);
int cargarVect(int leg[], int sue[], int cantMax);
int calcularMaximo(int sue[], int cantidad);
int main()
{
    int legajos_empleado[50], sueldos_empleado[50];
    ponerCero(legajos_empleado, sueldos_empleado, 50);
    int contador = cargarVect(legajos_empleado,sueldos_empleado,50);
    int maximo = calcularMaximo(sueldos_empleado, contador);
    printf("\nLos empleados con el mejor salario son: ");
    for (int i = 0; i < contador; i++)
    {
        if (maximo == sueldos_empleado[i])
        {
            printf("%d ", legajos_empleado[i]);
        }
    }
    printf("\n");
}

int calcularMaximo(int sue[], int cantidad){
    int maximo = sue[0];
    for(int i = 1; i<cantidad; i++){
        if(maximo < sue[i]){
            maximo = sue[i];
        }
    }
    return maximo;
}

int cargarVect(int leg[], int sue[], int cantMax)
{
    int cantidad = 0;
    int band = 0;
    do
    {
        if (band==0)
        {
            printf("\nIngrese el legajo del empleado: ");
            scanf("%d", &leg[cantidad]);
            band = 1;
        }
        else
        {
            if (band == 1)
            {
                printf("\nIngrese el sueldo del empleado: ");
                scanf("%d", &sue[cantidad]);
                band = 2;
            }
            else
            {
                cantidad++;
                band = 0;
            }
        }
    } while ((band == 0 || leg[cantidad] != 0) && cantidad < cantMax);
    return cantidad;
}

void ponerCero(int leg[], int sue[], int n)
{
    for (int i = 0; i < n; i++)
    {
        leg[i] = sue[i] = 0;
    }
}