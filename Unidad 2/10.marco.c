/*
    Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide
    transformarlo a un número con formato (aammdd) e informar el número original y el
    resultante con leyenda aclaratoria
*/
# include "stdio.h"

int main() {
    int day;
    int month;
    int year;
    printf("Ingrese el día mes y año\n");
    scanf("%d%d%d",&day, &month, &year);

    printf("El formato original del día es %d/%d/%d\n", day,month,year);
    printf("En formato aammdd %d/%d/%d\n", year, month,day);

}