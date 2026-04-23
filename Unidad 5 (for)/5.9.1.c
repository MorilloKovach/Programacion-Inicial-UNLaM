/*
Dado a que este problema tiene dos formas de resolverse, voy a resolver repitiendo ternas en este contexto, y en el 5.9.2.c lo voy a resolver de la otra forma :)
*/

#include<stdio.h>

int main(){
    int a,b,c,neg=0,num,i;
    a=b=c=-99999;
    for(i = 0; i<18; i++){
        printf("\nIngrese el numero: ");
        scanf("%d",&num);
        if(a==-99999){
            a=num;
        }
        else if(b==-99999){
            b=num;
        }
        else if(c==-99999){
            c=num;
            if(a<0 && b < 0 && c < 0) neg++;
        }
        else{
            a=b;
            b=c;
            c=num;
            if(a<0 && b < 0 && c < 0) neg++;
        }
    }
    printf("La cantidad de ternas negativas es: %d",neg);


}