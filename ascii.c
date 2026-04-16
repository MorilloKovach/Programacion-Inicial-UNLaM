#include<stdio.h>

int main(){
    char c;
    printf("Ingrese una letra: ");
    scanf("%c",&c);
    int ascii = c;
    printf("El valor de la letra %c en ascii es: %d",c,ascii);
}