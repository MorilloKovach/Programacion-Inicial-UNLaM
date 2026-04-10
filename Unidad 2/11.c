/*
Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y
pueda calcular e informar la suma de sus dígitos hasta llegar a una sola cifra. Ejemplo: 9929
→ 2
*/

#include<stdio.h>

int main()
{

    int numero;
    printf("Ingrese el numero: ");
    scanf("%d", &numero);

    /*
    Ahora tenemos que pensar en cuantas partes vamos a dividir este problema...
    Vamos directo al caso mas grande.
    9999
    9+9+9+9 = 36
    3+6 = 9
    A lo mucho, en teoria, con dos casos ya estariamos... No?
    NO. Existen otros valores. Por ejemplo, y si llegamos a un 29?

    9+9+9+2 = 29
    2+9 = 11
    1+1 = 2

    Entonces... Vamos a directamente agarrar ese caso particular mas alto.
    */

    int suma_num = numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero;
    /*
    Ahora vamos a reemplazar num por lo que acabamos de hacer.. Y suma num queda vacio
    */
    numero = suma_num;
    suma_num = 0;
    suma_num = numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero;
    numero = suma_num;
    suma_num = 0;
    suma_num = numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero % 10;
    numero /= 10;
    suma_num = suma_num + numero;

    printf("El numero es: %d\n",suma_num);
}