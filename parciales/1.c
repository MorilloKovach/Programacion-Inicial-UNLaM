#include<stdio.h>

int EstaDentroDelRango(int, int, int);
void ImporteMenuYMozo(float[10][50]);
int NumeroMenu(float[10][50]);
void MozosSinVentas(float[10][50]);
int IngrDatos(float[10][50]); //Sabemos que existe una cantidad fija de ventas.
//Por lo tanto, podemos ir contando las ventas que hay hasta que terminemos.
//De esta manera, resolveremos el 4 en el mismo punto.

int main(){
    float Importe[10][50]; //10 mozos, 50 menus.
    int i,j,cant,NumeroMenuMayor;
    for(i=0;i<10;i++){
        for(j=0;j<50;j++){
            Importe[i][j] = 0;
        }
    }
    cant = IngrDatos(Importe);
    printf("\nLa cantidad de ventas en el mes fue de %d ventas.",cant);
    ImporteMenuYMozo(Importe);
    NumeroMenuMayor = NumeroMenu(Importe);
    printf("\nEl numero de menu que obtuvo la mayor facturacion fue el %d.",NumeroMenuMayor);
    MozosSinVentas(Importe); 
}

int EstaDentroDelRango(int linf, int lsup, int valor){
    int band = 0;
    if(linf <= valor && valor <= lsup)
    {
        band = 1;
    }
    return band;
}

int IngrDatos(float Importe[10][50]){
    int cant=0, mozo, menu;
    float importe;
    do{
        printf("\nIngrese el valor del menu: ");
        scanf("%d",&menu);
        while(!EstaDentroDelRango(101,150,menu) && menu != 0)
        {
            printf("\nIngrese el valor del menu: ");
            scanf("%d",&menu);
        }
        if(menu != 0){
            printf("\nIngrese el numero del mozo: ");
            scanf("%d",&mozo);
            while(!EstaDentroDelRango(1,10,mozo)){
                printf("\nIngrese el numero del mozo: ");
                scanf("%d",&mozo);
            }
            printf("\nIngrese el valor del importe: ");
            scanf("%f",&importe);
            while(importe <= 0){
                printf("\nIngrese el valor del importe: ");
                scanf("%f",&importe);
            }
            Importe[mozo-1][menu-101]+=importe;
            cant++;
        }
    }while(menu != 0);
    return cant;
}

void ImporteMenuYMozo(float Importe[10][50]){
    float ImporteMozo[10], ImporteMenu[50];
    int i,j;
    for(i=0;i<10;i++){
        ImporteMozo[i] = 0;
    }
    for(i=0;i<50;i++){
        ImporteMenu[i] = 0;
    }
    for(i=0;i<10;i++){
        for(j=0;j<50;j++){
            ImporteMozo[i] += Importe[i][j];
            ImporteMenu[j] += Importe[i][j];
        }
    }
    printf("\nImportes por mozos: ");
    for(i=0;i<10;i++){
        printf("\nMozo %d\t Importe: %.2f",i+1,ImporteMozo[i]);
    }
    printf("\nImporte por Menu: ");
    for(i=0;i<50;i++){
        printf("\nMenu %d\t Importe: %.2f", i+101, ImporteMenu[i]);
    }
}
int NumeroMenu(float Importe[10][50])
{
    int i,j,menu=0;
    float maximo=0,suma=0;
    for(i=0;i<50;i++){
        suma = 0;
        for(j=0;j<10;j++){
            suma+=Importe[j][i];
        }
        if(suma > maximo){
            maximo = suma;
            menu = i+101;
        }
    }
    return menu;
}

void MozosSinVentas(float importe[10][50]){
    float suma=0;
    int i,j;
    for(i=0;i<10;i++){
        suma=0;
        for(j=0;j<50;j++){
            suma+=importe[i][j];
        }
        if(suma==0){
            printf("\nEl mozo %d no vendio nada en el mes.",i+1);
        }
    }
}