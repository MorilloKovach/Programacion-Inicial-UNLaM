#include <stdio.h>
int Leer();
void esPar(int);

int main()
{
    int numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
    numero = Leer();
    esPar(numero);
}

int Leer()
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);
    return numero;
}

void esPar(int numero)
{
    if (numero % 2 == 0)
    {
        printf("\nEs par");
    }
    else
    {
        printf("\nEs impar");
    }
}