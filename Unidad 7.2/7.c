#include <stdio.h>

float DineroTotalRecaudado(float[][6]);
void IngrDatos(float[][6], float);
void DepartamentosDeudores(float[][6]);
int EstaDentroDelRango(int, int, int);

int main()
{
    int mes, anio;
    float m2, Departamentos[15][6];
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 6; j++)
        {
            Departamentos[i][j] = 0;
        }
    }
    printf("\nIngrese el mes: ");
    scanf("%d", &mes);
    while (!EstaDentroDelRango(1, 12, mes))
    {
        printf("\nIngrese el mes: ");
        scanf("%d", &mes);
    }
    printf("\nIngrese el anio: ");
    scanf("%d", &anio);
    while (anio <= 2025)
    {
        printf("\nIngrese el anio: ");
        scanf("%d", &anio);
    }
    printf("\nIngrese precio por m2: ");
    scanf("%f", &m2);
    while (m2 < 0)
    {
        printf("\nIngrese precio por m2: ");
        scanf("%f", &m2);
    }
    IngrDatos(Departamentos, m2);
    printf("\nEl total recaudado fue: $%.2f", DineroTotalRecaudado(Departamentos));
    DepartamentosDeudores(Departamentos);
    printf("\n");
    return 0;
}

int EstaDentroDelRango(int linf, int lsup, int numero)
{
    int EstaEnRango = 1;
    if (linf > numero || lsup < numero)
    {
        EstaEnRango = 0;
    }
    /*
    int EstaEnRango=0;
    if(linf <= numero && numero <= lsup){
        EstaEnRango = 1;
    }
    */
    return EstaEnRango;
}

void IngrDatos(float Departamentos[][6], float m2)
{
    int piso, depto;
    float m2dpto;
    do
    {
        printf("\nIngrese el piso: ");
        scanf("%d", &piso);
        while (!EstaDentroDelRango(1, 15, piso) && piso != 99)
        {
            printf("\nIngrese el piso: ");
            scanf("%d", &piso);
        }
        if (piso != 99)
        {
            printf("\nIngrese el numero del departamento: ");
            scanf("%d", &depto);
            while (!EstaDentroDelRango(1, 6, depto))
            {
                printf("\nIngrese el numero del departamento: ");
                scanf("%d", &depto);
            }
            if (Departamentos[piso - 1][depto - 1] != 0)
            {
                printf("\nEse departamento ya pagó!!!!!!!!!!!!!!!");
            }
            else
            {
                printf("\nIngrese la cantidad de metros cuadrados: ");
                scanf("%f", &m2dpto);
                while (m2dpto < 0)
                {
                    printf("\nIngrese la cantidad de metros cuadrados: ");
                    scanf("%f", &m2dpto);
                }
                Departamentos[piso - 1][depto - 1] = m2dpto * m2;
            }
        }
    } while (piso != 99);
}

float DineroTotalRecaudado(float Departamentos[][6])
{
    float suma = 0;
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 6; j++)
        {
            suma += Departamentos[i][j];
        }
    }
    return suma;
}

void DepartamentosDeudores(float Departamentos[][6])
{
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (Departamentos[i][j] == 0)
            {
                printf(" X ");
            }
            else
            {
                printf(" 1 ");
            }
        }
        printf("\n");
    }
}