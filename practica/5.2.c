#include <stdio.h>

int EstaDentroDelRango(int, int, int);
int LeerYValidar(int, int);

int main()
{
    int numero_obtenido, cantidad_100_500 = 0, cantidad_500_1200 = 0;
    int cantidad_1200_2000=0, suma_1200_2000=0;
    float promedio=0;
    do
    {
        numero_obtenido = LeerYValidar(100, 2000);
        cantidad_100_500 += EstaDentroDelRango(100,500,numero_obtenido);
        if(EstaDentroDelRango(500,1200,numero_obtenido) && numero_obtenido%2==0){
            cantidad_500_1200++;
        }
        if(EstaDentroDelRango(1200,2000,numero_obtenido)){
            cantidad_1200_2000++;
            suma_1200_2000+=numero_obtenido;
        }
    } while (numero_obtenido != 99);

    printf("\nLa cantidad de numeros ingresados entre 100 y 500 fue de: %d",cantidad_100_500);
    printf("\nLa cantidad de numeros pares entre 500 y 1200 es de: %d",cantidad_500_1200);
    if(cantidad_1200_2000 > 0)
        promedio = (float)suma_1200_2000/cantidad_1200_2000;
    printf("\nEl promedio de los ingresados entre 1200 y 2000 es de: %.2f",promedio);
}

/*
100 2000 x
*/

int EstaDentroDelRango(int linf, int lsup, int num)
{
    if (linf <= num && num <= lsup)
        return 1;
    return 0;
}

int LeerYValidar(int linf, int lsup)
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d",&numero);
    while(!EstaDentroDelRango(linf, lsup, numero) && numero != 99){
        printf("\nError. No ingreso un numero valido, ingrese de vuelta: ");
        scanf("%d",&numero);
    }
    return numero;
}