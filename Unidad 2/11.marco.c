/*
    Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y
    pueda calcular e informar la suma de sus dígitos hasta llegar a una sola cifra. Ejemplo: 9929
    → 2
*/
# include "stdio.h"

int main() {
    int Z;
    printf("Porfavor ingrese un número entero\n");
    scanf("%d", &Z);

    int cifra_1 = Z/1000;
    printf("Cifra 1 %d\n",cifra_1);
    
    int cifra_2 = Z/100 - cifra_1 * 10; 
    printf("Cifra 2 %d\n",cifra_2);

    int cifra_3 = Z/10 - (cifra_1 * 100 + cifra_2 * 10); 
    printf("Cifra 3 %d\n",cifra_3);
    
    // lógica de reduce end
    int cifra_4 = Z - (Z/10 * 10);
    printf("Cifra 4 %d\n",cifra_4);
    
    printf("la suma de todos son %d", cifra_1 + cifra_2 + cifra_3 + cifra_4);
    return 0;
}