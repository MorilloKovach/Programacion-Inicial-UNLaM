/*
    Confeccionar un programa que ingrese el valor exoresado en Kibibyte y lo informe exoresadi eb TiB, GiB, MiB, con leyendas aclaratorias, NOTA:: 1MiB = 1024 KiB; 1 GiB = 1024 MiB; 1TiB = 1024 GiB
*/
# include "stdio.h"

int main() {
    float kb;
    printf("Porfavor, ingrese la cantidad de Kilobytes\n");
    scanf("%f",&kb);

    float mb = kb / 1024;
    float gb = mb/ 1024;
    float tb = gb/ 1024;

    printf("El kilobyte ingresado es %f\n ", kb);
    printf("El megabyte ingresado es %f\n ", mb);
    printf("El gigabyte ingresado es %f\n ", gb);
    printf("El terabyte ingresado es %f\n ", tb);

}