/*
Confeccionar un programa que me permita calcular y mostrar una cantidad de números
primos que se solicita por la pantalla. Los números se calculan a partir del 2. Por ejemplo: Si
se ingresa el número 6, se deben generar los números: 2 , 3 , 5 , 7 , 11 , 13. El algoritmo para
el cálculo de si un número es primo o no, debe estar optimizado para que, si encuentra un
divisor, no siga buscando ya que se sabe que el número NO es primo.
*/

#include<stdio.h>

int main(){
    int N;
    printf("Digite la cantidad de primos que quiere: ");
    scanf("%d",&N);
    int a = 2;
    while(N>=0){
        int iterador = 2;
        int encontroDivisor = 0;
        while(iterador < a && encontroDivisor == 0){
            if(a%iterador == 0){
                encontroDivisor = 1;
            }
            iterador++;
        }
        if(!encontroDivisor){
            N--;
            printf("%d ",a);
        }
        a++;
    }
}