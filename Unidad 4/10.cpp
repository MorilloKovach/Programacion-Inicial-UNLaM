/*
.10 La plataforma on line “TuTele” desea realizar un sistema para calcular el costo de la publicidad
de un determinado cliente. Para realizarlo ingresa por teclado los siguientes datos:
• Código de cliente (entero)
• Código de la publicidad (entero)
• Año de la publicidad (entero)
• Importe de la publicidad por cada proyección (real)
• Forma de pago (carácter, ‘E’: Efectivo; ‘C’: Cheque a 60 días)
• Cantidad de proyecciones al día (entero)
Calcular el importe a cobrar del día, según el siguiente esquema:
▪ Si la publicidad es del año actual (estreno) y el pago es con cheque a 60
días, el importe es un 40% más caro.
▪ Si la publicidad es de los dos años anteriores, el importe es un 20% más
caro.
▪ Si la publicidad tiene más de tres años, y el pago es en efectivo, el importe
es un 10% más barato.
Además, existe la siguiente promoción que se suma a lo anterior, si la cantidad de
proyecciones diarias es 20 o más, se descuenta un 15% al importe a cobrar. Cualquier otro
caso, no hay recargos ni descuentos. Informar el código del cliente, el código de la publicidad
y el importe final a cobrar.
*/

#include<stdio.h>

int main(){
    int cod_cli,cod_pub,anio_pub,proy_dias;
    char pagar;
    float importe;
    printf("Ingrese el codigo de cliente: ");
    scanf("%d",&cod_cli);
    printf("\nAhora ingrese el de la publicidad: ");
    scanf("%d",&cod_pub);
    printf("\nAhora el anio de la publicidad: ");
    scanf("%d",&anio_pub);
    printf("\nIngrese el importe por proyeccion: ");
    scanf("%f",&importe);
    printf("\nIngrese la forma de pago ('E', efectivo, 'C', cheque a 60d): ");
    scanf(" %c",&pagar);
    printf("\nCantidad de proyecciones al dia: ");
    scanf("%d",&proy_dias);
    importe *= proy_dias;
    if(pagar == 'c') pagar = 'C';
    if(pagar == 'e') pagar = 'E';
    int ANIO_ACTUAL = 2026; //Modificar si se ve desde otro año nada que ver

    if(pagar == 'C' && anio_pub == ANIO_ACTUAL) importe*=1.4;
    else if(anio_pub+2 >= ANIO_ACTUAL ) importe*=1.2;
    else if(anio_pub+3 < ANIO_ACTUAL && pagar == 'E') importe*=0.9;
    if(proy_dias >= 20){
        importe *= 0.85;
    }

    printf("El codigo del cliente es %d, su codigo de publicidad de %d y su importe final a cobrar es %0.2f\n",cod_cli,cod_pub,importe);
}