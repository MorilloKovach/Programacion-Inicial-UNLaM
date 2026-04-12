/*
Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e
informe si lo ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su
correspondiente valor numérico en ASCII.
*/

#include <stdio.h>

int main()
{
    char caracter;
    printf("Ingrese el caracter: ");
    scanf("%c", &caracter);
    if (caracter == 'a' or caracter == 'A' or caracter == 'E' or caracter == 'e' or caracter == 'i' or caracter == 'I' or caracter == 'O' or caracter == 'o' or caracter == 'u' or caracter == 'U')
    {
        int valor;
        if (caracter >= 'A' and caracter <= 'Z')
            valor = caracter - 'A';
        else
            valor = caracter - 'a';
        printf("VOCAL: %d", valor);
    }
    
}