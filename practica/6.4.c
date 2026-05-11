/*
Se ingresan números enteros comprendidos entre 100 y 2000. Determinar:
a. Cantidad de números ingresados entre 100 y 500
b. Cantidad de números pares ingresados entre 500 y 1200
c. Promedio de números ingresados entre 1200 y 2000
El ingreso de datos finaliza cuando se ingresa un número igual a 99.
Para realizar este programa se deben realizarlassiguientesfunciones:
• EstaDentroDelRango: Recibe 3 enteros correspondientes a un número a validar y
los límites superior e inferior del rango. La función debe retornar un 1 (verdadero)
si el número a validar se encuentra dentro del rango indicado o un 0 (falso) si no lo
está.
• LeerYValidar: Recibe los límites superior e inferior de un rango y retorna un
número que se encuentre dentro del mismo. El ingreso de datos se realiza dentro
de la función. Para validar el rango utilizar la función EstaDentroDelRango
analizada en el punto anterior.
*/

#include <stdio.h>

int EstaDentroDelRango(int limite_inferior, int limite_superior, int numero);
int LeerYValidar(int limite_inferior, int limite_superior);

int main()
{
    int cant_100_500 = 0, cant_pares_500_1200 = 0, suma_1200_2000 = 0, contador_1200_2000 = 0, numero;
    numero = LeerYValidar(100, 2000);
    while (numero != 99)
    {
        if (EstaDentroDelRango(100, 500, numero))
        {
            cant_100_500++;
        }
        if (EstaDentroDelRango(500, 1200, numero) && numero % 2 == 0)
        {
            cant_pares_500_1200++;
        }
        if (EstaDentroDelRango(1200, 2000, numero))
        {
            suma_1200_2000 += numero;
            contador_1200_2000++;
        }
        numero = LeerYValidar(100, 2000);
    }
    printf("\nLos numeros ingresados entre 100 y 500 son %d", cant_100_500);
    printf("\nLos numeros ingresados entre 500 y 1200 y que son pares son %d", cant_pares_500_1200);
    if (contador_1200_2000 != 0)
    {
        printf("\nEl promedio de los ingresados entre 1200 y 2000 es %d", suma_1200_2000 / contador_1200_2000);
    }
}

/*
EstaDentroDelRango(100, 2000, numero);

limite_inferior = 100;
limite_superior = 2000;
*/

int EstaDentroDelRango(int limite_inferior, int limite_superior, int numero)
{
    int band = 0;
    if (limite_inferior <= numero && numero <= limite_superior)
    {
        band = 1;
    }
    return band;
}

int LeerYValidar(int limite_inferior, int limite_superior)
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);
    while (!(EstaDentroDelRango(limite_inferior, limite_superior, numero)) && numero != 99)
    {
        printf("\nIngrese un numero valido: ");
        scanf("%d", &numero);
    }
    return numero;
}