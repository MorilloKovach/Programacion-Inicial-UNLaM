/*
Se ingresan tres números enteros distintos. Determinar e informar el mayor de los tres
números.
*/

#include<stdio.h>

int main(){
    int a,b,c;
    printf("Ingresar el primer numero: ");
    scanf("%d",&a);
    printf("\nIngresar el segundo numero: ");
    scanf("%d",&b);
    printf("\nIngresar el tercer numero: ");
    scanf("%d",&c);

    if(a>b && a > c){
        printf("El numero mas grande es el primero, cuyo valor es de %d",a);
    }
    else if(b>a && b > c){
        printf("El numero mas grande es el segundo, cuyo valor es de %d",b);
    }
    else if(c > a && c > b){
        printf("El numero mas grande es el tercero, cuyo valor es de %d",c);
    }
    else{
        printf("No hay numero mas grande, existen empates");
    }
    printf("\n");
}