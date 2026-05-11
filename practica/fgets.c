#include<stdio.h>
#include<strings.h>
#include<string.h>
int main(){
    char test[50], test2[50];
    printf("Ingrese un texto: ");
    fgets(test, 50, stdin);
    fgets(test2, 50, stdin);
    int bandera = 1;
    for(int i = 0; i<50; i++){
        if(test[i] == '\n' || test2[i] == '\n'){
            printf("Salto de linea\n");
            break;
        }
        if(test[i] != test2[i]){
            printf("Son distintos");
            bandera = 0;
            break;
        }
    }
    if(bandera){
        printf("Son iguales\n");
    }
}