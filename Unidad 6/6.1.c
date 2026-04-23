#include<stdio.h>
int EstaDentroDelRango(int num1, int num2, int num3){
    return num1 <= num2 && num2 <= num3;
}

int LeerYValidar(int lim, int sup){
    int num;
    printf("\nIngrese el valor: ");
    scanf("%d",&num);
    while(!EstaDentroDelRango(lim, num, sup) && num != 99){
        printf("\nIngrese el numero en el rango valido: ");
        scanf("%d",&num);
    }
    return num;
}

int main(){
    int cant_100_500=0,cant_par_500_1200=0, num,s = 0, cont = 0;
    num = LeerYValidar(100, 2000);
    while(num != 99){
        if(EstaDentroDelRango(100, num, 500)) cant_100_500++;
        if(EstaDentroDelRango(500, num, 1200) && num%2==0) cant_par_500_1200++;
        if(EstaDentroDelRango(1200, num, 2000)){
            s+=num;
            cont++;
        }
        num = LeerYValidar(100, 2000);
    }
    printf("\nLa cantidad de numeros ingresados entre 100 y 500 son: %d",cant_100_500);
    printf("\nLa cantidad de pares entre 500 y 1200 es de %d",cant_par_500_1200);
    printf("\nEl promedio de numeros ingresados entre 1200 y 2000 es %d",s/cont);
}