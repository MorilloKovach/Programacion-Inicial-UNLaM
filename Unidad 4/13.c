/*
4.13 Confeccionar un programa que permita calcular cuánto hay que pagarle a un trabajador,
ingresando por teclado su sueldo básico y las horas extras trabajadas. Para el pago de las
horas extras se toma en cuenta la categoría del trabajador.
Categoría Precio de la hora extra
A
$ 8000
B
$ 8800
C
$ 10000
D
$ 12000
E
$ 14000
*/

#include<stdio.h>

int main(){
    int sueldo_basico, horas_extras, tot;
    char categoria;
    printf("Ingrese el sueldo basico del trabajador: ");
    scanf("%d",&sueldo_basico);
    printf("\nIngrese la cantidad de horas extras: ");
    scanf("%d",&horas_extras);
    printf("\nIngrese la categoria del trabajador: ");
    scanf(" %c",&categoria);

    if(categoria=='A'){
        tot = sueldo_basico + horas_extras * 8000;
        printf("El sueldo total es de $%d ",tot);
    }
    else if(categoria=='B'){
        tot = sueldo_basico + horas_extras * 8800;
        printf("El sueldo total es de $%d ",tot);
    }
    else if(categoria=='C'){
        tot = sueldo_basico + horas_extras * 10000;
        printf("El sueldo total es de $%d ",tot);
    }
    else if(categoria=='D'){
        tot = sueldo_basico + horas_extras * 12000;
        printf("El sueldo total es de $%d ",tot);
    }
    else if(categoria=='E'){
        tot = sueldo_basico + horas_extras * 14000;
        printf("El sueldo total es de $%d ",tot);
    }
    else{
        printf("No hay tal categoria.");
    }
    printf("\n");
}