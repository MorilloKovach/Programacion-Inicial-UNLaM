#include<stdio.h>

void saludo();
int EstaDentroDelRango(int, int, int); //a,b, numero
int main(){
    int numero1,numero2;
    printf("\nIngrese el primer numero: ");
    scanf("%d",&numero1);

    if(EstaDentroDelRango(100,500,numero1)){
        printf("El numero esta en el rango de 100 a 500");
    }
    if(EstaDentroDelRango(500,1200,numero1) && numero1%2==0){
        printf("El numero esta en el rango y ademas es par");
    }
}
// numero1 >= a
// numero1 <= b

int EstaDentroDelRango(int a, int b, int numero){
    int PerteneceAlRango = 0;
    if(numero >= a && numero <= b){ 
        PerteneceAlRango = 1;
    }
    return PerteneceAlRango;
}

void saludo(){
    printf("Hola!\n");
    printf("Buchu mastodonte\n");

    return; //valor
}