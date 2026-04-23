#include <stdio.h>

int main()
{
    char cod;
    float efect_caja = 0, vta_tarj = 0, vta_cheq = 0;
    float tot_venta = 0;
    float iva = 0;
    float precio;
    printf("Digite el codigo: ");
    scanf("%c", &cod);
    while (cod != 'C' && cod != 'E' && cod != 'T' && cod != 'F')
    {
        printf("\nDigite otro codigo, el anterior no fue valido: ");
        getchar();
        scanf("%c", &cod);
    }
    while (cod != 'F')
    {
        efect_caja = 0, vta_tarj = 0, vta_cheq = 0;
        tot_venta = 0;
        iva = 0;
        printf("\nDigite el precio: ");
        scanf("%f", &precio);
        while (precio < 0)
        {
            printf("\nDigite una opcion valida: ");
            scanf("%f", &precio);
        }
        if (cod == 'C')
        {
            precio = precio * 1.2;
            vta_cheq += precio;
        }
        else if (cod == 'E')
        {
            precio = precio * 0.9;
            efect_caja += precio;
        }
        else if (cod == 'T')
        {
            precio = precio * 1.12;
            vta_tarj += precio;
        }
        tot_venta += precio;
        printf("\nDigite otro codigo: ");
        getchar();
        scanf("%c", &cod);
        while (cod != 'C' && cod != 'E' && cod != 'T' && cod != 'F')
        {
            getchar();
            printf("\nDigite otro codigo, el anterior no fue valido: ");
            scanf("%c", &cod);
        }
    }
    printf("El total del efectivo en caja: %.2f\n", efect_caja);
    printf("El total de ventas con tarjeta de credito: %.2f\n", vta_tarj);
    printf("El total de ventas con cheque: %.2f\n", vta_cheq);
    printf("Total de ventas: %.2f\n", tot_venta);
    printf("Total de ventas con IVA: %.2f\n", tot_venta * 1.21);
}