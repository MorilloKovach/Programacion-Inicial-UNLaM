#include<stdio.h>

int main(){
    int coste_vuelo;
    printf("Digite el importe del pasaje de clase turista: \n");
    scanf("%d",&coste_vuelo);

    int cantidad_pasajesT, cantidad_pasajesP;
    printf("Digite la cantidad de vuelos vendidos en clase turista: \n");
    scanf("%d",&cantidad_pasajesT);
    printf("Digite la cantidad de vuelos vendidos en primera clase: \n");
    scanf("%d",&cantidad_pasajesP);

    int coste_total = cantidad_pasajesT*coste_vuelo + cantidad_pasajesP*(coste_vuelo*1.3);
    printf("El coste total de los pasajes es: %d\n",coste_total);

    return 0;
}