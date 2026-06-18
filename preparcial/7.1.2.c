#include<stdio.h>

int IngrDatos(float[]);
int PuestoUno(float[], int);
int UltimoPuesto(float[],int);
int AutosPromedio(float[],int);
void NoParticipan(float[],int);

int main(){
    float tiempos[60];
    int cantidad,i;
    for(i=0;i<60;i++){
        tiempos[i] = 0;
    }
    cantidad = IngrDatos(tiempos);
    printf("\nEl codigo del primer puesto fue %d",PuestoUno(tiempos,cantidad));
    printf("\nEl auto de peor clasificacion fue: %d",UltimoPuesto(tiempos, cantidad));
    printf("\nLa cantidad de autos que superaron el promedio de clasificacion fue %d",AutosPromedio(tiempos,cantidad));
    printf("\nLos numeros de autos que no participan de la carrera son: ");
    NoParticipan(tiempos, cantidad);
}

int IngrDatos(float tiempos[]){
    int cantidad=0;
    float tiempo=0;
    do{
        printf("Ingrese el tiempo del auto %d: ",cantidad+1);
        scanf("%f",&tiempo);
        if(tiempo > 0){
            tiempos[cantidad] = tiempo;
            cantidad++;
        }
    }while(cantidad<60 && tiempo > 0);
    return cantidad;
}

int PuestoUno(float tiempos[], int cantidad){
    float minimo=0;
    int num_auto,i,PrimerValor=1;
    for(i=0;i<cantidad;i++){
        if(PrimerValor==1 || minimo > tiempos[i]){
            num_auto = i+1;
            PrimerValor = 0;
            minimo = tiempos[i];
        }
    }
    return num_auto;
}

int UltimoPuesto(float tiempos[], int cantidad){
    float maximo = 0;
    int num_auto,i;
    for(i=0;i<cantidad;i++){
        if(maximo < tiempos[i]){
            maximo = tiempos[i];
            num_auto = i+1;
        }
    }
    return num_auto;
}

int AutosPromedio(float tiempos[], int cantidad){
    float suma = 0;
    int i,cantidadPromedio=0;
    for(i=0;i<cantidad;i++){
        suma+=tiempos[i];
    }
    suma/=cantidad;
    for(i=0;i<cantidad;i++){
        if(tiempos[i] >= suma){
            cantidadPromedio++;
        }
    }
    return cantidadPromedio;
}


void NoParticipan(float tiempos[], int cantidad){
    int i;
    for(i=cantidad+1; i<=60; i++){
        printf("%d ",i);
    }
}