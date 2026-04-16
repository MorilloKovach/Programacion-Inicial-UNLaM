/*
La estación de servicio “PetroMatanza” imprime tickets por cada venta de los distintos
combustibles que despachan durante un día de venta. Por cada ticket se ingresa:
• Número del artículo (entero, entre 40 y 90)
• Número del cliente (entero, mayor a cero)
• Precio por litro (real, mayor que cero)
• Cantidad de litros (real, mayor que cero)
El ticket debe contener además de los datos ingresados y el importe a cobrar. La finalización
de la venta de combustible del día se logra con un ticket con número de artículo igual a cero.
Realizar un algoritmo que permita:
a) Ingrese los datos e imprima el ticket.
b) Al finalizar el día, informar la cantidad de tickets que se imprimieron y el valor
cobrado en total.
c) Indicar el número de cliente que tiene el ticket más grande en importe.
*/

#include <stdio.h>

int main()
{
    int numero_articulo, num_cliente;
    float precio_litros, cant_litros;
    float suma = 0;
    float p_max = 0, p_cli = 0;
    int cont = 0;
    printf("\nIngrese un numero de articulo: ");
    scanf("%d",&numero_articulo);
    while(numero_articulo < 40 || numero_articulo > 90){
        printf("\nIngrese otro codigo: ");
        scanf("%d",&numero_articulo);
    }
    while (numero_articulo != 0)
    {
        printf("\nIngrese el numero del cliente: ");
        scanf("%d", &num_cliente);
        while (num_cliente <= 0)
        {
            printf("\nIngrese un valor valido: ");
            scanf("%d", &num_cliente);
        }
        printf("\nIngrese el precio de litro: ");
        scanf("%f", &precio_litros);
        while (precio_litros < 0)
        {
            printf("\nIngrese un precio valido: ");
            scanf("%f", &precio_litros);
        }
        printf("\nIngrese la cantidad de litros: ");
        scanf("%f", &cant_litros);
        suma += precio_litros * cant_litros;
        while (cant_litros < 0)
        {
            printf("\nIngrese una cantidad valida: ");
            scanf("%f", &cant_litros);
        }
        if (precio_litros * cant_litros > p_max)
        {
            p_max = precio_litros * cant_litros;
            p_cli = num_cliente;
        }
        printf("\nEl ticket del cliente: Se cobraron %.2f al cliente %d por una cantidad total de %.2f litros del articulo %d: ", precio_litros * cant_litros, num_cliente, cant_litros, numero_articulo);
        printf("\nIngrese otro numero de articulo: ");
        scanf("%d", &numero_articulo);
        while (numero_articulo != 0 && (numero_articulo < 40 || numero_articulo > 90))
        {
            printf("\nIngrese un numero valido: ");
            scanf("%d", &numero_articulo);
        }
        cont++;
    }
    printf("\nEl total de tickets emitidos fue de %d y el total fue de %.2f",cont,suma);
    printf("\nEl cliente con mayor gasto fue: %.2f",p_cli);
}