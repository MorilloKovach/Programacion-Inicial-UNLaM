/*
60 autos
del 1 al 60 como codigos
necesitamos determinar quien gano
quien fue el peor en tiempo
quienes superaron (es decir, fueron los que estan en tabla baja) en tiempos de llegada
que autos NO participaron
*/

#include <stdio.h>

int IngrDatos(float[], int);
int MejorTiempo(float[], int);
int PeorTiempo(float[], int);
void PeoresTiempos(float[], int);
void NoParticiparon(int,int);

int main()
{
    float tiempos[60];
    int total=60,cant;
    cant = IngrDatos(tiempos, total);
    printf("\nEl auto que mejor tiempo tuvo fue %d ", MejorTiempo(tiempos, cant));
    printf("\nEl auto que peor tiempo tuvo fue %d ", PeorTiempo(tiempos, cant));
    PeoresTiempos(tiempos, cant);
    NoParticiparon(cant, total);
}

int IngrDatos(float tiempos[], int cant)
{
    int i = 0, autos;
    float tiempo;
    do
    {
        do
        {
            printf("\nIngrese el numero del auto: ");
            scanf("%d", &autos);
        } while (autos > 60);
        if (autos >= 0)
        {
            do
            {
                printf("\nIngrese el tiempo del auto: ");
                scanf("%f", &tiempo);
            } while (tiempo <= 0);
            tiempos[i] = tiempo;
            i++;
        }
    } while (autos >= 0 && i < cant);
    return i;
}

int MejorTiempo(float tiempos[], int cant){
    float min=0,band=1;
    int autoDefinido=0;
    int i;
    for(i=0;i<cant;i++){
        if(min > tiempos[i] || band==1){
            band = 0;
            min = tiempos[i];
            autoDefinido = i+1;
        }
    }
    return autoDefinido;
}

int PeorTiempo(float tiempos[], int cant){
    float max=0;
    int autoDefinido=0,i;
    for(i=0;i<cant;i++){
        if(max < tiempos[i]){
            max = tiempos[i];
            autoDefinido = i+1;
        }
    }
    return autoDefinido;
}

void PeoresTiempos(float tiempos[], int cant){
    float sumaPromedio=0;
    int i;
    for(i=0;i<cant;i++){
        sumaPromedio+=tiempos[i];
    }
    sumaPromedio/=cant;
    for(i=0;i<cant;i++){
        if(tiempos[i] > sumaPromedio){
            printf("\nEl auto %d tardo mas que el promedio ",i+1);
        }
    }
}

void NoParticiparon(int cant, int total){
    int i;
    for(i=cant+1;i<=total;i++){
        printf("\nEl auto %d no participa.",i);
    }
}