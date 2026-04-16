#include<stdio.h>

int main(){
    float lado1,lado2,lado3;

    printf("Ingrese tres lados: ");
    scanf("%f%f%f",&lado1,&lado2,&lado3);

    if(lado1==lado2 && lado2==lado3){
        printf("Equilatero");
    }
    else if(lado1==lado2 || lado1==lado3 || lado2==lado3){
        printf("Isosceles");
    }
    else{
        printf("Escaleno");
    }
}
