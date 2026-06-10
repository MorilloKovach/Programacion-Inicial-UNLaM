#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int mat[5][8],i,j,valor,maximo=0, posX[40], posY[40], rep=0;
    for(i=0;i<5;i++){
        for(j=0;j<8;j++){
            valor = (int)rand()%100;
            while(valor < 10){
                valor = rand()%100;
            }
            mat[i][j] = valor;
            if(mat[i][j] > maximo){
                maximo = mat[i][j];
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<8;j++){
            if(mat[i][j] == maximo){
                posX[rep] = i;
                posY[rep] = j;
                rep++;
            }
        }
    }

    printf("El maximo se repite %d veces y su valor fue %d",rep,maximo);
    for(int i = 0; i<rep; i++){
        printf("\nSe repite en la pos: %d %d",posX[i], posY[i]);
    }
}