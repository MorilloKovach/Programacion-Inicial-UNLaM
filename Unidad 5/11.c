/*
Un negocio de artículos de limpieza por mayor efectúa descuentos en sus ventas según el
importe de estas, con la siguiente escala:
• Menor a $ 100000, el 3.5 %
• Entre $ 100000 y $ 250000, el 10 %
• Entre $ 250001 y $ 350000, el 20 %
• Mayor a $ 350001, el 25 %
Por cada venta se ingresan los siguientes datos:
• Número de cliente (entero, mayor que cero)
• Importe bruto de ventas (real, mayor a cero)
• Forma de pago (caracter, ‘E’: efectivo, ‘D’: tarjeta de débito, ‘C’: tarjeta de
crédito, ‘B’: billetera virtual)
Adicionalmente, se realiza un descuento del 10% de contado (efectivo) y un recargo del
10% con pago con tarjeta de crédito o billetera virtual. La carga de clientes finaliza con un
cliente igual cero.
Confeccionar un programa que:
a) Informe para cada cliente, el importe bruto, la forma de pago, el
descuento/recargo y el valor neto a pagar.
b) Informe el importe promedio de todas las ventas realizadas.
c) Calcular el porcentaje de la venta en cada una de las formas de pago respecto del
total de ventas.
d) Indicar cuál fue el mayor importe neto a pagar, pagado de contado.
e) Indicar cuál fue el menor importe bruto pagado con tarjeta de débito
*/

#include <stdio.h>

int main()
{
    int importe, cliente;
    char forma_pago;
    float precio_a_pagar;
    int conteo = 0, conteoE = 0, conteoC=0, conteoB=0, conteoD=0;
    int maximoNeto = 0;
    float sumaImportes = 0;
    int minimoBruto = 9999999;
    printf("Ingrese el cliente: ");
    scanf("%d", &cliente);
    while (cliente < 0)
    {
        printf("\nIngrese un cliente valido: ");
        scanf("%d", &cliente);
    }
    while (cliente > 0)
    {
        printf("\nIngrese el importe de la venta: ");
        scanf("%d", &importe);
        while (importe <= 0)
        {
            printf("\nIngrese un importe valido: ");
            scanf("%d", &importe);
        }
        printf("\nIngrese la forma de pago: ");
        getchar();
        scanf("%c", &forma_pago);
        while (forma_pago != 'E' && forma_pago != 'D' && forma_pago != 'C' && forma_pago != 'B')
        {
            printf("\nIngrese una forma de pago valido: ");
            getchar();
            scanf("%c", &forma_pago);
        }
        if(forma_pago == 'E') conteoE++;
        else if(forma_pago == 'D') conteoD++;
        else if(forma_pago == 'C') conteoC++;
        else if(forma_pago == 'B') conteoB++;
        conteo++;
        if(forma_pago == 'E'){
            precio_a_pagar = importe * 0.9;

            if(precio_a_pagar > maximoNeto){
                maximoNeto = precio_a_pagar;
            }
            printf("El cliente %d tiene un importe bruto de %d, su forma de pago fue %c, el descuento fue del %.2f y su valor neto a pagar es %.2f",cliente,importe,forma_pago,importe*0.1,precio_a_pagar);
        }
        else if(forma_pago == 'D'){
            precio_a_pagar = importe;
            if(precio_a_pagar < minimoBruto){
                minimoBruto = importe;
            }
        }
        if(forma_pago == 'C' || forma_pago == 'B'){
            precio_a_pagar = importe * 1.1;
            printf("El cliente %d tiene un importe bruto de %d, su forma de pago fue %c, el recargo fue del %.2f y su valor neto a pagar es %.2f",cliente,importe,forma_pago, importe*0.1, precio_a_pagar);
        }
        if(forma_pago != 'E' && forma_pago != 'C' && forma_pago != 'B'){
            printf("El cliente %d tiene un importe bruto de %d, su forma de pago fue %c y su valor neto a pagar es %.2f",cliente,importe,forma_pago, precio_a_pagar);
        }
        printf("\nIngrese otro cliente: ");
        scanf("%d", &cliente);
        sumaImportes+=precio_a_pagar;
        while (cliente < 0)
        {
            printf("\nIngrese un cliente valido: ");
            scanf("%d", &cliente);
        }
    }
    printf("\nEl promedio de todas las ventas fue de: %d", sumaImportes/conteo);
    printf("\nEl porcentaje de ventas en cada una de las debidas fue: %.2f efectivo, %.2f tarjeta de debito, %.2f credito, %.2f billetera virtual",(float)conteoE/conteo*100.0,(float)conteoD/conteo*100.0, conteoC/conteo*100.0, conteoB/conteo*100.0);
    printf("\nEl mayor importe neto a pagar fue: %d",maximoNeto);
    printf("\nEl menor importe bruto a pagar fue: %d",minimoBruto);
}