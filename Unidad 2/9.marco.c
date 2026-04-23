// Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena e
// informarlos con mensaje aclaratorio.
# include "stdio.h"

int main() {
    int num_3_cifras;
    printf("Ingrese un número de 3 cifras\n");
    scanf("%d",&num_3_cifras);

    
    printf("Unidad: %d\n", num_3_cifras);
    printf("Decena: %d\n", num_3_cifras/10);
    printf("Centena: %d\n", num_3_cifras/100);
}