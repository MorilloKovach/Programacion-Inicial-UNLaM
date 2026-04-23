/*
Confeccionar un programa que determine e informe los números perfectos comprendidos
entre 1 y 9000. Un número es perfecto cuando es igual a la suma de sus divisores positivos
menores que él.
*/

#include<stdio.h>

int main(){
    for(int i = 2; i<=9000; i++){
        int suma=0;
        for(int j = 1; j<i; j++){
            suma+=(i%j==0)?j:0;
        }
        if(suma==i){
            printf("Un numero perfecto es: %d\n",i);
        }
    }
}