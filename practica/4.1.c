#include<stdio.h>

int main(){
    int a,b,c;
    printf("Ingresar los tres numeros: ");
    scanf("%d %d %d",&a,&b,&c);

    if(a > b && a > c){
        printf("A es mayor que todos");
    }
    else if(b > a && b > c){
        printf("B es mayor a todos");
    }
    else if(a==b && b == c){
        printf("Todos los numeros son iguales");
    }
    /*else if(c > a && c > b){

    }
    */
    else {
        printf("C es mayor a todos");
   }
}

/*
a = 3
b = 5
c = 7

a > b : a > c ? a
b > a ? b > c ? b
c > a ? c > b? c
*/