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

#include <stdio.h>
int CalculaResto(int dividendo, int divisor);
int esPar(int num);
int esPrimo(int num);
float promedio(int acum, int cont);
int IngrDatoValCF(int inicio, int fin, int condicion);

int main()
{
    int cantPrimos = 0, cant = 0, cant_pares = 0, cant_impares = 0, suma_impares = 0;
    int num = IngrDatoValCF(1, 50, -10);
    while (num != -10)
    {
        cant++;
        cant_pares += esPar(num);
        cant_impares += !esPar(num);
        suma_impares += !esPar(num) * num;
        cantPrimos += esPrimo(num);
        num = IngrDatoValCF(1, 50, -10);
    }
    printf("\n%d %d ", cantPrimos, cant);
    printf("\nEl porcentaje de numeros primos que existe es: %.2f%%", (float)cantPrimos / cant * 100.0);
    printf("\nLa cantidad de numeros pares que existe son de: %d", cant_pares);
    printf("\nEl promedio de los impares es: %.2f\n", promedio(suma_impares, cant_impares));
    return 0;
}
int CalculaResto(int dividendo, int divisor)
{
    int cuenta = dividendo % divisor;
    return cuenta;
}

int esPar(int num)
{
    int band = 0;
    if (CalculaResto(num,2)==0)
        band = 1;
    return band;
}

int esPrimo(int num)
{
    int n1 = 2;
    int band = 1;
    if (num == 1){
        band = 0;
    }
    while (n1 < num && band)
    {
        if (CalculaResto(num,n1)==0)
        {
            band = 0;
        }
        n1++;
    }
    return band;
}

float promedio(int acum, int cont)
{
    float cuenta;
    if(cont == 0) cuenta = 0;
    else cuenta = (float)acum/cont;
    return cuenta;
}
int IngrDatoValCF(int inicio, int fin, int condicion)
{
    int num;
    printf("\nIngrese el valor: ");
    scanf("%d", &num);
    while (num != condicion && (num < inicio && num > fin))
    {
        printf("\nIngrese un valor valido: ");
        scanf("%d", &num);
    }
    return num;
}