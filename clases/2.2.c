#include <stdio.h>

int main()
{
    int num1, num2, resu = 0;
    printf("Ingrese dos numeros: ");
    printf("\nIngrese num1: ");
    scanf("%d", &num1);
    printf("\nIngrese num2: ");
    scanf("%d", &num2);
    if (num1 >= num2)
    {
        if (num1 == num2)
        {
            resu = 1;
        }
    }
    else
    {
        resu = 2;
    }

    printf("Resultado: %d\n", resu);
}