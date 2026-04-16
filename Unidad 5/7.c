#include<stdio.h>

int main(){
    float precio=0;
    float tot_precio=0;
    float maxi_p = 0;
    int cant_men15 = 0;
    int cant = 0;
    char continuar;
    printf("Desea correr operaciones? (S/N): ");
    scanf("%c",&continuar);
    while(continuar != 'S' && continuar != 'N'){
        printf("Ingrese bien la opcion: ");
        getchar();
        scanf("%c",&continuar);
    }
    while(continuar != 'N'){
        printf("\nIngrese el precio del producto: ");
        scanf("%f",&precio);
        while(precio < 0){
            printf("Valor no valido, ingrese un precio correcto: ");
            scanf("%d",&precio);
        }
        float precioOri = precio;
        float desc;
        if(precio < 15000){
            precio = precio - precio * 0.035;
            desc = 3.5;
            cant_men15++;
        }
        else if(precio >= 15000 && precio <= 25000){
            precio = precio - precio * 0.1;
            desc = 10;
        }
        else if(precio >= 25001 && precio <= 35000){
            precio = precio - precio * 0.2;
            desc = 20;
        }
        else{
            precio = precio - precio * 0.25;
            desc = 25;
        }
        if(precio > maxi_p){
            maxi_p = precio;
        }
        tot_precio+=precio;
        cant++;
        printf("\nEl precio original fue de: %.2f, su descuento fue del %.1f y el importe final fue de: %.2f", precioOri, desc, precio);
        printf("\nDesea continuar? (S/N): ");
        getchar();
        scanf("%c",&continuar);
        while(continuar != 'S' && continuar != 'N'){
            printf("Ingrese una opcion valida: ");
            getchar();
            scanf("%c",&continuar);
        }
    }
    printf("\nEl importe promedio por todas las ventas realizadas fue de: %.2f",tot_precio/cant);
    printf("\nEl importe mas grande de venta fue de %.2f",maxi_p);
    printf("\nSe vendieron un total de %d productos con ventas menores a 15000 pesos",cant_men15);
}