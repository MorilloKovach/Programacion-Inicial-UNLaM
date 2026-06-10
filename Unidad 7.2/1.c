#include<stdio.h>

int main(){
    int vec[3][3],i,j, valor,k;
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            printf("\nIngrese el valor de la pos %d %d: ",i+1,j+1);
            scanf("%d",&valor);
            vec[i][j] = valor;
        }
    }
    printf("\nIngrese el valor de la constante: ");
    scanf("%d",&k);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            vec[i][j]*=k;
            printf("%d ",vec[i][j]);
        }
        printf("\n");
    }
}