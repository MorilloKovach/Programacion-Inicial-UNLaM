#include <stdio.h>

int main()
{
    int opcion;
    printf("Ingrese la opcion del cajero. 1.- Ingresar, 2.- Retirar: ");
    scanf("%d",&opcion);
    switch(opcion){
        case 1: {
            printf("Estas ingresando plata");
            break;
        }
        case 2: {
            printf("Estas retirando plata");
            break;
        }
        default: {
            printf("No es una opcion valida");
        }
    }
}