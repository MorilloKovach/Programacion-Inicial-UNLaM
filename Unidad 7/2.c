#include<stdio.h>

int main(){
    int contador = 0, contador_prom=0;
    int autos[60], tiempo[60];
    int promedio = 0, cant_superior=0;
    int clasificar=0, minimo,maximo, minimoId, maximoId;
    printf("Digite el numero del auto: ");
    scanf("%d",&autos[contador]);
    while(contador < 60 && autos[contador] >= 0){
        printf("Digite el tiempo de clasificacion: ");
        scanf("%d",&tiempo[contador]);
        if(tiempo[contador] != 0){
            promedio+=tiempo[contador];
            contador_prom++;
        }
        contador++;
        if(contador < 60){
            printf("Digite el numero del auto: ");
            scanf("%d",&autos[contador]);
        }
    }
    if(contador){
        minimo = maximo = tiempo[0];
        minimoId = maximoId = autos[0];
        promedio/=contador_prom;
        for(int i = 0; i<contador; i++){
            if(minimo > tiempo[i]){
                minimo = tiempo[i];
                minimoId = autos[i];
            }
            if(maximo < tiempo[i]){
                maximo = tiempo[i];
                maximoId = autos[i];
            }
            if(tiempo[i] > promedio){
                cant_superior++;
            }
        }
        printf("El auto que ingreso en primer lugar fue %d\n",minimoId);
        printf("El auto que obtuvo el peor numero fue %d\n",maximoId);
        printf("La cantidad de autos que superaron el promedio fue %d\n",cant_superior);
        printf("Los autos que no participaron fueron: ");
        for(int i = 0; i<contador; i++){
            if(tiempo[i]==0){
                printf("%d ",autos[i]);
            }
        }
        printf("\n");
    }
}