/*
    Una empresa de aviación vende pasajes en clase turista y en primera clase cuyo costo es un 30% más caro qye clase turista. Se pide al usuario ingresar el importe de cada pasaje de clase turista, la cantidad de pasajes vendidos de clase turista y la canntidad vebdida de primera clase, Informar la recaudación total del vuelo. Incluir mensajes aclaratorios
*/

# include "stdio.h"

int main() {
    // error de ejecucion son los errores en runtime, y los errores de programación son cometidos directamente por el programador
    int pasaje_turista;
    
    printf("Ingresar el monto del peaje turista\n");
    scanf("%d", &pasaje_turista);
    
    int pasaje_primera_clase = pasaje_turista + ((pasaje_turista/100)*3);
    
    int cantidad_pasajeros;
    printf("Cuantos pasajes furon vendios?\n");
    scanf("%d", &cantidad_pasajeros);

    int cantidad_pasajeros_primera_clase;
    printf("Cuantos pasajes de primera clase fueron vendios?\n");
    scanf("%d", &cantidad_pasajeros_primera_clase);

    printf("Todo lo recaudado en el vuelo son %d", pasaje_turista * cantidad_pasajeros + pasaje_primera_clase * cantidad_pasajeros_primera_clase);
}