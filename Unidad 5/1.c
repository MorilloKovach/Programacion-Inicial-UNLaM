/*
Confeccionar un programa que calcule e informe los valores de las potencias de 2 cuyo
resultado sean menores a 6000. (1 2 4 8 16 …).
*/

#include<stdio.h>

int main(){
    int pot2 = 1;
    int calc = 0;
    while(pot2 < 6000){
        printf("El resultado de 2^%d es: %d\n",calc++,pot2);
        pot2*=2;
    }
}