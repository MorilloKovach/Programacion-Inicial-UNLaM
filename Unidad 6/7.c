#include <stdio.h>

/*
31 dias: 1,3,5,7,8,10,12
30 dias: 4,6,9,11
28 dias: 2
*/

int comprobarMes31(int mes)
{
    int band = 0;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        band = 1;
    return band;
}

int comprobarMes30(int mes)
{
    int band = 0;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        band = 1;
    return band;
}

int validar_fecha(int dia, int mes, int anio)
{
    int band = 0;
    if (comprobarMes31(mes) && dia <= 31) band = 1;
    if ((comprobarMes30(mes) && dia <= 30)) band = 1;
    if ((mes == 2 && dia <= 28) || (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)) && dia <= 29)
        band = 1;
    return band;
}

void retroceder_dia(int dia, int mes, int anio, int cant)
{
    for (int i = 0; i < cant && validar_fecha(dia, mes, anio); i++)
    {
        if (dia == 1 && mes == 1)
        {
            dia = 31;
            anio--;
            mes = 12;
        }
        else
        {
            if (dia == 1)
            {
                mes--;
                if (comprobarMes31(mes))
                    dia = 31;
                else
                {
                    if (comprobarMes30(mes))
                        dia = 30;

                    else
                    {
                        if (mes == 2)
                        {
                            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
                                dia = 29;
                            else
                                dia = 28;
                        }
                    }
                }
            }
            else
            {
                dia--;
            }
        }
    }
    printf("\n%d/%d/%d", dia, mes, anio);
}


void avanzar_dia(int dia, int mes, int anio, int cant)
{
    for (int i = 0; i < cant && validar_fecha(dia, mes, anio); i++)
    {
        if (dia == 31 && mes == 12)
        {
            anio++;
            dia = mes = 1;
        }
        else
        {
            if (dia == 30 && comprobarMes30(mes))
            {
                mes++;
                dia = 1;
            }
            else
            {
                if (dia == 31 && comprobarMes31(mes))
                {
                    dia = 1;
                    mes++;
                }
                else
                {
                    if (((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) && mes == 2)
                    {
                        if (dia == 29)
                        {
                            dia = 1;
                            mes++;
                        }
                        else
                        {
                            dia++;
                        }
                    }
                    else
                    {
                        if (mes == 2 && dia == 28)
                        {
                            dia = 1;
                            mes++;
                        }
                        else
                        {
                            dia++;
                        }
                    }
                }
            }
        }
    }
    printf("\n%d/%d/%d", dia, mes, anio);
}
int main()
{
    int dia, mes, anio, N;
    printf("\nIngrese la fecha: ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    while (!validar_fecha(dia, mes, anio))
    {
        printf("\nIngrese una fecha valida: ");
        scanf("%d/%d/%d", &dia, &mes, &anio);
    }
    printf("\nLa fecha de ayer fue: ");
    retroceder_dia(dia, mes, anio, 1);
    printf("\nY la de maniana sera: ");
    avanzar_dia(dia, mes, anio, 1);
    printf("\nIngrese N: ");
    scanf("%d", &N);
    printf("\nEl resultado de volver %d dias es: ", N);
    retroceder_dia(dia, mes, anio, N);
    printf("\nY el resultado de ir %d dias adelante es: ", N);
    avanzar_dia(dia, mes, anio, N);
}