/*
 La empresa “EDENORTE” factura a sus clientes el consumo mensual de electricidad.
Solicitar por única vez al comienzo del programa:
• El importe mínimo, para consumos que no excedan los 80 KW (real, mayor a cero).
• El importe de cada KW que exceda los 80 KW, contemplados en el consumo
mínimo (real, mayor a cero).
Cuando el consumo es igual a cero KW, se cobra solamente el importe mínimo.
A continuación, ingresar los datos de cada usuario:
• Código del usuario (entero, mayor a cero)
• Estado del medidor anterior (entero, mayor o igual a cero)
• Estado del medidor actual (entero, mayor a cero)
La carga de datos concluye cuando se ingresa el código de usuario cero.
Se pide que se determine e informe:
a) Para cada usuario, el código y el importe a abonar, es decir, el importe de la
factura.
b) El importe total facturado, la cantidad de facturas emitidas y el promedio
facturado en total.
c) La cantidad de usuarios que no registraron consumo de electricidad. 
d) El código de usuario con el menor consume, entre los que tienen consumo.
*/

#include<stdio.h>

int main(){
    float importe_minimo, importe_unidad;
    int medidor_act, medidor_past=0, no_consumos=0, minimo_consumo = 9999999, usuario_efic;
    int usuario;
    float importe_act;
    float sumaFacturas = 0.0;
    int cantidad_facturas = 0;
    printf("Ingrese el importe minimo para hasta 80KW: ");
    scanf("%f",&importe_minimo);
    while(importe_minimo <= 0){
        printf("\nIngrese un importe valido: ");
        scanf("%f",&importe_minimo);
    }
    printf("\nIngrese el importe por unidad una vez se superan los 80KW: ");
    scanf("%f",&importe_unidad);
    while(importe_unidad <= 0){
        printf("\nIngrese un importe valido: ");
        scanf("%f",&importe_minimo);
    }

    printf("\nIngrese el numero del usuario: ");
    scanf("%d",&usuario);
    while(usuario < 0){
        printf("\nNo es valido ese usuario, ingrese otro: ");
        scanf("%d",&usuario);
    }
    while(usuario > 0){
        printf("\nIngrese el uso de electricidad actual: ");
        cantidad_facturas++;
        scanf("%d",&medidor_act);
        while(medidor_act < 0){
            printf("\nIngrese un consumo valido: ");
            scanf("%d",&medidor_act);
        }
     /*  
        NO HAY UN USO ESPECIFICO DE ESTA PARTE
     printf("Ingrese el uso de electricidad del mes anterior: ");
        scanf("%d",&medidor_past);
        while(medidor_past < 0){
            printf("Ingrese un consumo valido: ");
            scanf("%d",&medidor_past);
        }    
        
        */
        if(medidor_act==0){
            no_consumos++;
        }
        else if(medidor_act < minimo_consumo){
            minimo_consumo = medidor_act;
            usuario_efic = usuario;
        }
        if(medidor_act <= 80){
            importe_act = importe_minimo;
            sumaFacturas+=importe_minimo;
        }
        else{
            importe_act = importe_minimo + importe_unidad * (medidor_act - 80);
            sumaFacturas+=importe_minimo + importe_unidad * (medidor_act - 80);
        }
        printf("\nEl usuario ingresado %d tiene que pagar %.2f", usuario, importe_act);
        printf("\nIngrese otro usuario: ");
        scanf("%d",&usuario);
        while(usuario < 0){
            printf("\nIngrese un usuario no negativo: ");
            scanf("%d",&usuario);
        }
    }
    printf("\nEl importe total facturado fue de: %.2f y su promedio fue %.2f",sumaFacturas, sumaFacturas/cantidad_facturas);
    printf("\nLa cantidad de usuarios que no presentaron consumos fueron: %d",no_consumos);
    printf("\nEl usuario con menor consumo fue: %d",usuario_efic);
}