#include<stdio.h>

int main(){
    int mat[3][3];
    int i,j, num,k=5;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("\nIngrese un numero para la posicion %d %d: ",i,j);
            scanf("%d",&num);
            mat[i][j] = num * k;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }
}