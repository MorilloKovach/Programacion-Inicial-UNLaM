#include<stdio.h>

void SumarColumnas(int[5][4]);
void SumarFilas(int[5][4]);
int main(){
    int mat[5][4],i,j;
    for(i = 0; i<5; i++){
        for(j=0;j<4;j++){
            printf("\nIngrese el valor de la fila %d y columna %d\n: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    SumarColumnas(mat);
    SumarFilas(mat);
}

void SumarColumnas(int mat[5][4]){
    int suma_columnas[4], i,j;
    for(i=0;i<4;i++){
        suma_columnas[i] = 0;
    }
    for(i = 0; i<4; i++){
        for(j=0;j<5;j++){
            suma_columnas[i] += mat[j][i];
        }
    }
    for(i = 0; i<4; i++){
        printf("La suma de la columna %d es: %d\n",i+1,suma_columnas[i]);
    }
}

void SumarFilas(int mat[5][4]){
    int sumaFilas[5],i,j;
    for(i=0;i<5;i++){
        sumaFilas[i] = 0;
    }
    for(i=0;i<5;i++){
        for(j = 0; j<4; j++){
            sumaFilas[i] += mat[i][j]; 
        }
    }
    for(i=0;i<5;i++){
        printf("La suma de la fila %d es: %d\n", i+1,sumaFilas[i]);
    }
}