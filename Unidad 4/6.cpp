/*
Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e
informe si lo ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su
correspondiente valor numérico en ASCII.
*/

#include <stdio.h>
#include<ctype.h>
int main()
{
    char caracter;
    printf("Ingrese el caracter: ");
    scanf("%c", &caracter);
    if (caracter == 'a' ||
        caracter == 'A' ||
        caracter == 'E' ||
        caracter == 'e' ||
        caracter == 'i' ||
        caracter == 'I' || caracter == 'O' || caracter == 'o' || caracter == 'u' || caracter == 'U')
    {
        int valor;
        valor = toascii(caracter);
        printf("VOCAL: %d", valor);
    }
    
}