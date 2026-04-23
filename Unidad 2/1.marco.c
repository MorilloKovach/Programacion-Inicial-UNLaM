// Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con
// mensajes aclaratorios la suma, el producto, el cociente y el resto. Precondición: el segundo
// número es distinto de cero
#include <stdio.h>

int main()
{
    int num1 = 1;
    int num2 = 1;
    printf("ingrese el num 1\n");
    scanf("%d", &num1);

    printf("ingrese el num 2\n");
    scanf("%d", &num2);


    printf("La suma es %d \n",  num1 + num2);

    printf("El producto es %d \n", num1 * num2);
    
    printf("El cociente es %d \n", num1 - num2);

    printf("El resto es %d \n", num1 / num2);

    return num1;

}
