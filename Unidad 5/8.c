#include <stdio.h>

int main()
{
    char continuar = 'S';

    while (continuar != 'N')
    {
        int n, antiguedad, cant_hijos, estudios_superiores;
        float sal;
        printf("\nIngrese el numero del empleado: ");
        scanf("%d",&n);
        if (n < 0)
        {
            printf("\nEl numero no puede ser negativo");
            continue;
        }
        printf("\nIngrese el salario del empleado: ");
        scanf("%f", &sal);
        printf("\nIngrese la antiguedad: ");
        scanf("%d", &antiguedad);
        printf("\nIngrese la cantidad de hijos: ");
        scanf("%d", &cant_hijos);
        printf("\nTiene estudios superiores? (1 SI, 0 NO): ");
        scanf("%d",&estudios_superiores);
        float orig = sal;
        if(antiguedad >= 10){
            sal += orig * 0.1;
        }
        if(cant_hijos == 1 || cant_hijos == 2){
            sal+=orig * 0.1;
        }
        else if(cant_hijos > 2){
            sal+=orig*0.15;
        }
        if(estudios_superiores){
            sal+=orig*0.05;
        }
        printf("El salario final del empleado numero %d es: %.2f\n",n,sal);
        getchar();
        printf("Desea ingresar otro empleado? (S para si, N para no): ");
        scanf("%c",&continuar);

    }
}