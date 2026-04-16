#include<stdio.h>

int main(){
    int a,b;
    printf("Ingrese dos valores: ");
    scanf("%d%d",&a,&b);
    if(a!=b){
        if(a>b) printf("A es mayor a B");
        else printf("B es mayor a A");
    }
    else printf("Son iguales");
}