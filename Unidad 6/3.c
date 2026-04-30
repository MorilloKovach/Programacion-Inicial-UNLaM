/*
Confeccionar un programa que permita ingresar diversas ternas de valores enteros
mayores que 0 y menores que 99. Finalizar el ingreso cuando se informen 3 valores iguales
a 96, 97 y 98. Determinar:
• Informar para cada terna, el mayor y el menor de los valores.
• Informar el promedio total de los valores mayores de cada terna.
• Indicar cuál es el valor mínimo ingresado tomado en cuenta todas las ternas.
Confeccionar y utilizar una función con parámetros llamada MayorMenor, que permita
calcular el menor o el mayor valor de cada terna según un parámetro de configuración.
*/

#include <stdio.h>
int MayorMenor(int v1, int v2, int v3, int mi);

int main()
{
    int a1, a2, a3;
    int sumar_may = 0;
    int contar=0;
    int minimo_terna = 0;
    int aux=1;
    int maxi,mini;
    printf("\nIngrese la terna: ");
    scanf("%d%d%d", &a1, &a2, &a3);
    while (a1 != 96 || a2 != 97 || a3 != 98)
    {
        while (a1 > 99 || a1 < 0 || a2 > 99 || a2 < 0 || a3 > 99 || a3 < 0)
        {
            printf("\nIngresa una terna valida: ");
            scanf("%d%d%d", &a1, &a2, &a3);
        }
        mini = MayorMenor(a1,a2,a3, 1);
        maxi = MayorMenor(a1,a2,a3,0);
        contar++;
        sumar_may+=maxi;
        if(aux || mini < minimo_terna){
            minimo_terna = mini;
            aux = 0;
        }
        printf("\nEl minimo de la terna es %d y su maximo es %d",mini,maxi);
        printf("\nIngrese la terna: ");
        scanf("%d%d%d", &a1, &a2, &a3);
    }
    printf("\nEl promedio de los mayores de las ternas es: %.2f",(float)sumar_may/contar);
    printf("\nEl minimo ingresado es: %d",minimo_terna);
}
int MayorMenor(int v1, int v2, int v3, int mi)
{
    if (mi)
    {
        if (v1 < v2 && v1 < v3)
            return v1;
        else if (v2 < v1 && v2 < v3)
            return v2;
        else if (v3 < v1 && v3 < v2)
            return v3;
        else
        {
            if (v1 == v2)
                return v1;
            else if (v1 == v3)
                return v1;
            return v2;
        }
    }
    if (v1 > v2 && v1 > v3)
        return v1;
    else if (v2 > v1 && v2 > v3)
        return v2;
    else if (v3 > v1 && v3 > v2)
        return v3;
    else
    {
        if (v1 == v2)
            return v1;
        else if (v1 == v3)
            return v1;
        return v2;
    }
}
