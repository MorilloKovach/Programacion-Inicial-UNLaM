#include<stdio.h>

int main(){
    char cod;

    float precio;
    printf("Digite el codigo: ");
    scanf("%c",&cod);

    float efect_caja = 0, vta_tarj = 0, vta_cheq = 0;
    float tot_venta = 0;
    float iva = 0;
    while(cod != 'F'){
        printf("\nDigite el precio: ");
        scanf("%f", &precio);
        if(cod == 'C'){
            precio = precio*1.2;
            vta_cheq+=precio;
        }
        else if(cod=='E'){
            precio = precio * 0.9;
            efect_caja+=precio;
        }
        else if(cod=='T'){
            precio = precio * 1.12;
            vta_tarj+=precio;
        }
        else{
            printf("\nVuelva a digitar otro codigo.: ");
        }
        getchar();
        tot_venta+=precio;
        printf("\nDigite otro codigo: ");
        scanf("%c",&cod);
    }
    printf("El total del efectivo en caja: %.2f\n",efect_caja);
    printf("El total de ventas con tarjeta de credito: %.2f\n",vta_tarj);
    printf("El total de ventas con cheque: %.2f\n",vta_cheq);
    printf("Total de ventas: %.2f\n",tot_venta);
    printf("Total de ventas con IVA: %.2f\n",tot_venta*1.21);
}