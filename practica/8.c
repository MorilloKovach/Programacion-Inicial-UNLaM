#include<stdio.h>

void sumaFila(int mat[][4]);
void sumaColumna(int mat[][4]);

void RellenarDatos(int mat[][4]);

int main(){
    int mat[5][4];
    RellenarDatos(mat);
    sumaFila(mat);
    sumaColumna(mat);
}
void sumaFila(int mat[][4]){
    int sumaFilas[5];
    int i,j;
    for(i=0;i<5;i++){
        sumaFilas[i] = 0;
    }
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            sumaFilas[i]+=mat[i][j];
        }
    }
    for(i=0;i<5;i++){
        printf("\nEl valor de la suma de la fila %d es: %d",i+1, sumaFilas[i]);
    }
}

void sumaColumna(int mat[][4]){
    int i,j, sumaColumnas[4];
    for(j=0;j<4;j++){
        sumaColumnas[j] = 0;
    }
    for(j=0;j<4;j++){
        for(i=0;i<5;i++){
            sumaColumnas[j]+=mat[i][j];
        }
    }
    for(j=0;j<4;j++){
        printf("\nEl valor de la suma de la columna %d es: %d",j+1, sumaColumnas[j]);
    }
}
void RellenarDatos(int mat[][4]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("\nIngrese el valor de la posicion %d %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
}


/*
1   2  3  4 = 10
5   6  7  8 = 26
9  10 11 12 = 42
13 14 15 16 = 58
17 18 19 20 = 74

45
*/