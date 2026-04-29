/*
Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor-10. Calcular:
a. Porcentaje de números son primos.
b. Cantidad de números pares.
c. Promedio de los números impares.
Utilizar las siguientes funciones:
• IngrDatoValCF: Recibe tres parámetros que son el rango y la condición de fin, que
es un número que no pertenece al rango válido. El ingreso se hace dentro de la
función y se retorna el dato ingresado y validado.
• CalculaResto: Recibe por parámetro el Dividendo y el Divisor, retorna el resto de la
división.
• esPar: Recibe por parámetro un número, retorna 1 (verdadero) si es Par, 0 (falso) si es
Impar. Invoca a la función CalculaResto.
• esPrimo: Recibe por parámetro un número, retorna 1 (verdadero) si es primo, 0
(falso) si no es primo. Invoca a la función CalculaResto. (un número es primo si
sólo es divisible por 1 y por sí mismo).
• Promedio: Recibe por parámetro una variable acumuladora y una variable
contadora. Retorna el promedio si contador es mayor a 0 sino Retorna 0. Se debe preguntar después del retorno el valor del promedio.
*/

/*
Primos existentes en el rango [1,50]
[2,3,5,7,11,13,17,19,23,27,31,37,41,43,47]
*/

#include<stdio.h>

int CalculaResto(int dividendo, int divisor)
{
    return dividendo % divisor;
}

int esPar(int num)
{
    return num % 2 == 0;
}

int esPrimo(int num)
{
    return (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19 || num == 23 || num == 27 || num == 31 || num == 37 || num == 41 || num == 43 || num == 47);
}

float promedio(int acum, int cont)
{
    if (cont > 0)
        return (float)acum / cont;
    return 0;
}
int IngrDatoValCF(int inicio, int fin, int condicion)
{
    int num;
    printf("\nIngrese el numero: ");
    scanf("%d", &num);
    int cantPrimos = 0, cant = 0, cant_pares = 0, cant_impares = 0, suma_impares = 0;
    while (num != condicion)
    {
        while (num < inicio || num > fin)
        {
            printf("\nIngrese un numero valido: ");
            scanf("%d", &num);
        }
        cant++;
        cant_pares += esPar(num);
        cant_impares += !esPar(num);
        suma_impares += !esPar(num) * num;
        cantPrimos += esPrimo(num);
        printf("\nIngrese el numero: ");
        scanf("%d", &num);
    }
    printf("\nEl porcentaje de numeros primos que existe es: %.2f%%",(float)cantPrimos/cant*100.0);
    printf("\nLa cantidad de numeros pares que existe son de: %d",cant_pares);
    printf("\nEl promedio de los impares es: %.2f",promedio(suma_impares, cant_impares));
}

int main()
{
    IngrDatoValCF(1, 50, -10);
    return 0;
}