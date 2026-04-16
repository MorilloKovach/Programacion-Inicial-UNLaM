#include <stdio.h>

int main()
{
    char continuar;
    printf("Desea correr operaciones? (S/N): ");
    scanf("%c", &continuar);
    while (continuar != 'S' && continuar != 'N')
    {
        printf("\nNo ha puesto una opcion valida, ingrese nuevamente: ");
        getchar();
        scanf("%c", &continuar);
    }
    while (continuar != 'N')
    {
        int n, antiguedad, cant_hijos, estudios_superiores;
        float sal;
        printf("\nIngrese el numero del empleado: ");
        scanf("%d", &n);
        while (n <= 0)
        {
            printf("\nEl valor ingresado NO es correcto, ingrese otro: ");
            scanf("%d", &n);
        }
        printf("\nIngrese el salario del empleado: ");
        scanf("%f", &sal);
        while (sal < 0)
        {
            printf("\nEl valor no es correcto. Ingrese nuevamente: ");
            scanf("%f", &sal);
        }
        printf("\nIngrese la antiguedad: ");
        scanf("%d", &antiguedad);
        while (antiguedad < 0)
        {
            printf("\nEl valor no es correcto. Ingrese nuevamente: ");
            scanf("%f", &antiguedad);
        }
        printf("\nIngrese la cantidad de hijos: ");
        scanf("%d", &cant_hijos);
        while (cant_hijos < 0)
        {
            printf("\nEl valor no es correcto. Ingrese nuevamente: ");
            scanf("%f", &cant_hijos);
        }
        printf("\nTiene estudios superiores? (1 SI, 0 NO): ");
        scanf("%d", &estudios_superiores);
        while(estudios_superiores != 1 && estudios_superiores != 0){
            printf("\nNo ha puesto una opcion valida, ingrese nuevamente: ");
            getchar();
            scanf("%d", &estudios_superiores);
        } 
        float orig = sal;
        if (antiguedad >= 10)
        {
            sal += orig * 0.1;
        }
        if (cant_hijos == 1 || cant_hijos == 2)
        {
            sal += orig * 0.1;
        }
        else if (cant_hijos > 2)
        {
            sal += orig * 0.15;
        }
        if (estudios_superiores)
        {
            sal += orig * 0.05;
        }
        printf("\nEl salario final del empleado numero %d es: %.2f", n, sal);
        getchar();
        printf("\nDesea ingresar otro empleado? (S para si, N para no): ");
        scanf("%c", &continuar);
        while(continuar != 'S' && continuar != 'N'){
            printf("\nNo ha puesto la opcion valida, ingrese nuevamente: ");
            getchar();
            scanf("%c", &continuar);
        } 
    }
}
