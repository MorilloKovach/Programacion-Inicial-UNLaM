#include<stdio.h>

void cargarDatos(int[], int[], int[]);
int bajarIndice(int,int);
void mostrarMueblesEnElMes(int[]);
int mayorFabricado(int[]);
void escribirMayoresFabricados(int, int[]);
void mostrarFabricadosPorOperario(int[]);
void noSeFabrico(int[]);
void setearTodoACero(int[], int[], int[]);
int main(){
    int dia_habiles[22], tipos_muebles[14], codigos_operarios[25];
    int mayores_fabricados;
    setearTodoACero(dia_habiles, tipos_muebles, codigos_operarios);
    cargarDatos(dia_habiles, tipos_muebles, codigos_operarios);
    mostrarMueblesEnElMes(tipos_muebles);
    mayores_fabricados = mayorFabricado(tipos_muebles);
    escribirMayoresFabricados(mayores_fabricados, tipos_muebles);
    mostrarFabricadosPorOperario(codigos_operarios);
    noSeFabrico(dia_habiles);
}
void setearTodoACero(int dia_habiles[], int tipos_muebles[], int codigos_operarios[]){
    int i;
    for(i = 0; i<22; i++){
        dia_habiles[i] = 0;
    }
    for(i = 0; i<14; i++){
        tipos_muebles[i] = 0;
    }
    for(i = 0; i<25; i++){
        codigos_operarios[i] = 0;
    }
}
void mostrarMueblesEnElMes(int tipos_muebles[]){
    int i;
    for(i = 0; i<14; i++){
        printf("La cantidad de muebles de %d en el mes fue: %d\n",i+1, tipos_muebles[i]);
    }
}

int mayorFabricado(int tipos_muebles[]){
    int cant = 0,i;
    for(i = 0; i<14; i++){
        if(cant < tipos_muebles[i]){
            cant = tipos_muebles[i];
        }
    }
    return cant;
}
void escribirMayoresFabricados(int mayor, int tipos_muebles[]){
    int i;
    for(i = 0; i<14; i++){
        if(tipos_muebles[i] == mayor){
            printf("%d\n", i+1);
        }
    }
}

void mostrarFabricadosPorOperario(int codigos_operarios[]){
    int i;
    printf("Codigo operario \t Cantidad de muebles fabricada\n");
    for(i = 0; i<25; i++){
        printf("%d\t%d\n",i+1,codigos_operarios[i]);
    }
}

void noSeFabrico(int dia_habiles[]){
    int i;
    for(i = 0; i<22; i++){
        if(dia_habiles[i]==0){
            printf("No se fabrico en el dia %d\n",i+1);
        }
    }
}

int bajarIndice(int indice, int bajo){
    return indice-bajo;
}

void cargarDatos(int dia_habiles[], int tipos_muebles[], int codigos_operarios[]){
    int dia,tipo_mueble,codigo_operario;
    printf("\nIngrese el dia habil: ");
    scanf("%d",&dia);
    while(dia == 0 || dia > 22){
        printf("\nIngrese un dia habil: ");
        scanf("%d",&dia);
    }
    while(dia > 0){
        dia_habiles[bajarIndice(dia, 1)]++;
        printf("\nIngrese el tipo de mueble: ");
        scanf("%d",&tipo_mueble);
        while(tipo_mueble < 0 || tipo_mueble > 14){
            printf("\nIngrese un tipo de mueble valido: ");
            scanf("%d",&tipo_mueble);
        }
        tipos_muebles[bajarIndice(tipo_mueble, 1)]++;
        printf("\nIngrese el operario: ");
        scanf("%d",&codigo_operario);
        while(codigo_operario < 0 || codigo_operario > 25){
            printf("\nIngrese el codigo operario: ");
            scanf("%d",&codigo_operario);
        }
        codigos_operarios[bajarIndice(codigo_operario, 1)]++;
        printf("\nIngrese el dia habil: ");
        scanf("%d",&dia);
        while(dia == 0 || dia > 22){
            printf("\nIngrese un dia habil valido: ");
            scanf("%d",&dia);
        }
    }
}