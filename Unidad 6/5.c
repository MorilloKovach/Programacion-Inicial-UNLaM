#include <stdio.h>


int MayorTerna(int n1, int n2, int n3);
float promedio(int n1, int n2, int n3);
int sumar(int n1, int n2, int n3);
int mostrarMenu();


int main()
{
    int opcion;
    int t1, t2, t3;
    printf("Ingrese la terna: ");
    scanf("%d%d%d", &t1, &t2, &t3);
    opcion = mostrarMenu();
    while (!(t1 < t2 && t2 < t3))
    {

        while (opcion != 4)
        {
            switch (opcion)
            {
            case 1:
                printf("\nEl mayor valor de la terna es: %d",MayorTerna(t1,t2,t3));
                break;
            case 2:
                printf("\nEl promedio de la terna es: %.2f",promedio(t1,t2,t3));
                break;
            case 3:
                printf("\nLa suma de la terna es: %d",sumar(t1,t2,t3));
                break;
            case 4: 
                printf("\nFinalizando el menu...");
                break;
            default:
                printf("\nNo ingreso un valor valido ");
            }
            opcion = mostrarMenu();
        }
        printf("Ingrese otra terna: ");
        scanf("%d%d%d", &t1, &t2, &t3);
    }
}
int MayorTerna(int n1, int n2, int n3)
{
    if (n1 > n2 && n1 > n3)
        return n1;
    else if (n2 > n1 && n2 > n3)
        return n2;
    else if (n3 > n1 && n3 > n2)
        return n3;
    else
    {
        if (n1 == n2 || n1 == n3)
            return n1;
        return n2;
    }
}

float promedio(int n1, int n2, int n3)
{
    return (float)(n1 + n2 + n3) / 3;
}

int sumar(int n1, int n2, int n3)
{
    return n1 + n2 + n3;
}

int mostrarMenu()
{
    int opcion;
    printf("\n ---------Menu------------ \n");
    printf("\n1.-Mayor valor de la terna");
    printf("\n2.-Promedio de la terna");
    printf("\n3.-Suma de la terna");
    printf("\n4.-Finalizar");
    printf("\n**Digite su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
