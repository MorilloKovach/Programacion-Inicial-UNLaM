/*
Construir un algoritmo que pueda ingresar varios números enteros, distintos de cero, de uno
por vez. El ingreso de los datos finaliza al leer un valor nulo (cero). 
*/

#include<stdio.h>

int main(){
    int positivos=0;
    int minNum=999999999, minOrd=0;
    int ingresados=0,pares=0;
    int valorMul7=0, ordMul7=0;
    int num;
    scanf("%d",&num);
    while(num != 0){
        if(num > 0) positivos++;
        if(num < minNum){
            minNum = num;
            minOrd = ingresados+1;
        }
        if(num%2==0){
            pares++;
        }
        if(num%7==0 && valorMul7 < num){
            valorMul7 = num;
            ordMul7 = ingresados+1;
        }
        ingresados++;
        printf("\nIngrese otro valor: ");
        scanf("%d",&num);
    }

    printf("a) La cantidad de valores positivos es de: %d\n", positivos);
    printf("b) El menor valor ingresado es el %d y su orden de llegada es de %d\n", minNum, minOrd);
    printf("c) El porcentaje de numeros pares ingresados es de %0.2f%%\n", 100.0 * pares/ingresados);
    printf("d) El maximo multiplo de 7 ingresado es de %d y su orden de llegada es de %d\n", valorMul7, ordMul7);
}