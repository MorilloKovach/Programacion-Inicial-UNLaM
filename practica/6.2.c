#include <stdio.h>

int main()
{
    int numero = 2, numero_divisor = 2, band = 1, N;

    printf("\nIngrese la cantidad de numeros primos que esta buscando: ");
    scanf("%d", &N);

    while (N > 0)
    {
        numero_divisor = 2;
        band = 1;
        while(numero_divisor <= numero/2 && band == 1){
            if(numero%numero_divisor==0){
                band = 0;
            }
            numero_divisor++;
        }
        printf("\nMe faltan encontrar %d primos y por ahora estoy en %d",N, numero);
        if(band==1){
            N--;
        }
        numero++;
    }
}