/*
Confeccionar un programa que permita ingresar cuatro números enteros por teclado, de a
uno por vez, y determine el menor valor y su número de orden. Informe los valores ingresados
e identifique al menor con mensaje aclaratorio.
*/

#include<stdio.h>

int main(){
    int n1,n2,n3,n4;
    printf("Ingrese el primer numero: ");
    scanf("%d",&n1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&n2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d",&n3);
    printf("\nIngrese el cuarto numero: ");
    scanf("%d",&n4);

    printf("Los numeros ingresados fueron: %d,%d,%d y %d",n1,n2,n3,n4);

    if(n1 < n2 && n1 < n3 && n1 < n4){
        printf("El numero de menor valor es el primero, cuyo valor es de %d",n1);
    }
    else if(n2 < n1 && n2 < n3 && n2 < n4){
        printf("El numero de menor valor es el segundo, cuyo valor es de %d",n2);
    }
    else if(n3 < n1 && n3 < n2 && n3 < n4){
        printf("El numero de menor valor es el tercero, cuyo valor es de %d",n3);
    }
    else if(n4 < n1 && n4 < n2 && n4 < n3){
        printf("El numero de menor valor es el cuarto, cuyo valor es de %d",n4);
    }
    else{
        printf("Existen empates.");
    }
    printf("\n");
}