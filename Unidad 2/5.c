#include<stdio.h>

int main(){
    int kib;
    printf("Ingrese el valor en kib: ");
    scanf("%d",&kib);
    int mib = kib/1024;
    int gib = mib/1024;
    int tib = gib/1024;
    printf("El valor en mib es: %d\n",mib);
    printf("El valor en gib es: %d\n",gib);
    printf("El valor en tib es: %d\n",tib);

    return 0;
}