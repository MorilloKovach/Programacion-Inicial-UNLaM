/*
Confeccionar un programa que pueda determinar el importe a pagar por una prestación
médica según su código. Los importes se cobran según la siguiente tabla:
Código Importe
A 17000
D 24000
F 31000
M 45000
T 55000
Se debe ingresar el número de historia del paciente y el código de la prestación por teclado.
Se debe emitir un ticket con el número de la historia, el código y el importe a pagar
*/

#include <stdio.h>

int main()
{
    int numero_historia;
    char codigo;
    printf("Ingrese el numero de historia del paciente y su codigo: ");
    scanf("%d %c", &numero_historia, &codigo);
    if (codigo == 'A')
    {
        printf("Numero: %d, codigo: %c, importe: %d", numero_historia, 'A', 17000);
    }
    else if (codigo == 'D')
    {
        printf("Numero: %d, codigo: %c, importe: %d", numero_historia, 'D', 24000);
    }
    else if (codigo == 'F')
    {
        printf("Numero: %d, codigo: %c, importe: %d", numero_historia, 'F', 31000);
    }
    else if (codigo == 'M')
    {
        printf("Numero: %d, codigo: %c, importe: %d", numero_historia, 'M', 45000);
    }
    else if (codigo == 'T')
    {
        printf("Numero: %d, codigo: %c, importe: %d", numero_historia, 'T', 55000);
    }
    else{
        printf("No existe tal codigo.");
    }
    printf("\n");
}