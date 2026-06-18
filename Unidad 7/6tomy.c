/*7.1.6 Una fábrica produce 14 tipos de muebles de oficina con la mano de obra de 25 operarios
especializados. Al finalizar el mes se genera una planilla, donde cada registro indica:
* Día hábil del mes de fabricación (entero, de 1 a 22)
* Tipo de mueble que se fabricó (entero, de 1 a 14)
* Código del operario que fabricó el mueble (entero, de 1 a 25)
En la última información se ingresó un día hábil negativo. No hay orden alguno en los datos
ingresados y un mismo operario puede hacer más de un mueble (del mismo tipo o no, en el
mismo día o distintos días) durante el mes.
Determinar e informar:
a) La cantidad de cada tipo de mueble fabricado durante el mes.
b) Tipo de mueble del cual se ha fabricado la mayor cantidad. (puede haber más de
uno).
c) Listado de cantidad de muebles fabricados por operario (sin importar el tipo),
indicando:

Código de operario Cantidad de muebles fabricada
d) Día o días hábil/es en los cuales no hubo nada de producción.*/
void ingrdatos(int[], int[], int[]);
int maximo(int[]);
void listado(int[]);
void dia(int[]);

#include <stdio.h>

int main()
{
    int i, sumamuebles[14], sumaoperario[25], sumadias[22], max;
    for (i = 0; i < 22; i++)
    {
        sumadias[i] = 0;
    }
    for (i = 0; i < 14; i++)
    {
        sumamuebles[i] = 0;
    }
    for (i = 0; i < 25; i++)
    {
        sumaoperario[i] = 0;
    }

    ingrdatos(sumamuebles, sumaoperario, sumadias);
    max = maximo(sumamuebles);
    listado(sumaoperario);
    dia(sumadias);
    printf("el maximo fue: %d", max);
    return 0;
}
void ingrdatos(int sumamuebles[], int sumaoperario[], int sumadias[])
{
    int dia, codigo, mueble;
    do
    {
        printf("ingrese el dia habil del mes: ");
        scanf("%d", &dia);
        while (dia == 0 || dia > 22)
        {
            printf("ingrese el dia habil del mes: ");
            scanf("%d", &dia);
        }
        if (dia > 0)
        {
            printf("ingrese el tipo de mueble que se fabrico: ");
            scanf("%d", &mueble);
            while (mueble < 1 || mueble > 14)
            {
                printf("ingrese el tipo de mueble que se fabrico: ");
                scanf("%d", &mueble);
            }
            printf("ingrese el codigo del operario ");
            scanf("%d", &codigo);
            while (codigo < 1 || codigo > 25)
            {
                printf("ingrese el codigo del operario ");
                scanf("%d", &codigo);
            }
            sumaoperario[codigo - 1]++;
            sumadias[dia - 1]++;
            sumamuebles[mueble - 1]++;
        }
    } while (dia > 0);
}

int maximo(int sumamuebles[])
{
    int i, max = 0;
    max = sumamuebles[0];
    for (i = 0; i < 14; i++)
    {
        if (sumamuebles[i] > max)
        {
            max = sumamuebles[i];
        }
    }

    return max;
}
void listado(int sumaoperario[])
{
    int i;
    for (i = 0; i < 25; i++)
    {
        printf("\n el operario n%d ha fabricado %d muebles", i + 1, sumaoperario[i]);
    }
}
void dia(int sumadias[])
{
    int i;
    for (i = 0; i < 22; i++)
        if (sumadias[i] == 0)
        {
            printf("\nel dia %d no hubo ventas", i + 1);
        }
}