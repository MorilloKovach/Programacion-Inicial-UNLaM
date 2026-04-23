#include <stdio.h>

int main()
{
    int n1, n2, n3;
    int prom_min = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("\nIngrese la terna: ");
        scanf("%d%d%d", &n1, &n2, &n3);
        while (n1 == n2 || n2 == n3 || n1 == n3)
        {
            printf("\nESCRIBA UNA TERNA CON TODOS LOS VALORES DISTINTOS...:");
            scanf("%d%d%d", &n1, &n2, &n3);
        }

        if (n1 > n2 && n1 > n3)
            printf("\nEl mayor valor es el %d y se encuentra en la primer pos",n1);

        else if (n2 > n1 && n2 > n3)
            printf("\nEl mayor valor ingresado en la terna es %d y se encuentra en la segunda pos.",n2);

        else
            printf("\nEl mayor valor ingresado en la terna es %d y se encuentra en la tercera pos.",n3);
        if (n1 % 7 == 0)
            printf("\nEl primer valor de la terna es multiplo de 7");

        if (n2 % 7 == 0)
            printf("\nEl segundo valor de la terna es multiplo de 7");
        if (n3 % 7 == 0)
            printf("\nEl tercer valor de la terna es multiplo de 7");
        
        if(n1 < n2 && n1 < n3) prom_min+=n1;
        else if(n2 < n1 && n2 < n3) prom_min+=n2;
        else prom_min+=n3;
    }
    printf("\nEl promedio de los menores valores de cada uno es: %.2f",(float)prom_min/6);
}