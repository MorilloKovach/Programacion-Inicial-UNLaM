/*
 Un negocio vende distintos artículos identificados por un código, según se muestra:
• código 1; 10; 100: 1000 pesos la unidad.
• código 2; 22; 222: 700 pesos la unidad. La caja de 10 unidades vale 6500 pesos.
• código 3; 33: 300 pesos la unidad. Si la compra es por más de 10 unidades se hace
un descuento del 10% sobre el total de la compra.
• código 4; 44: 100 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a
comprar y se informe el importe de la compra, con las siguientes leyendas:
ARTÍCULO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx
*/

#include<stdio.h>

int main(){
    int codigo,unidades;
    printf("Ingrese el codigo del articulo: ");
    scanf("%d",&codigo);
    printf("Ingrese las unidades que ha comprado: ");
    scanf("%d",&unidades);

    if(codigo==1 || codigo == 10 || codigo == 100){
        printf("ARTICULO 10 CANTIDAD %d IMPORTE A PAGAR $%.2f",unidades,1000.0*unidades);
    }
    else if(codigo==2 || codigo == 22 || codigo == 222){
        float val = unidades/10 * 6500;
        int aux = unidades;
        unidades%=10;
        val+=unidades*700;
        unidades = aux;
        printf("ARTICULO 22 CANTIDAD %d IMPORTE A PAGAR $%.2f",unidades,val);
    }
    else if(codigo==3 || codigo == 33 ){
        float val = unidades * 300;
        if(unidades>10) val*=0.9;
        printf("ARTICULO 33 CANTIDAD %d IMPORTE A PAGAR %.2f",unidades,val);
    }
    else if(codigo==4 || codigo == 44){
        float val = unidades * 100;
        printf("ARTICULO 44 CANTIDAD %d IMPORTE A PAGAR %.2f",unidades,val);
    }
    else{
        printf("No existe tal codigo");
    }
    printf("\n");
}