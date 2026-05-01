/*
Realizar un programa que ingrese la fecha actual y la fecha de nacimiento de una persona y
calcule su edad. Las fechas deben ser validadas con una función. Para el cálculo de la edad
realizar una función que reciba las dos fechas y retorne la edad de la persona.
*/

#include <stdio.h>

int validarMes31(int mes)
{
    int band = 0;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        band = 1;
    return band;
}

int validarMes30(int mes)
{
    int band = 0;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        band = 1;
    return band;
}

int validar_fecha(int dia, int mes, int anio)
{
    int band = 0;
    if (validarMes31(mes) && dia <= 31 && anio > 0 && dia > 0)
        band = 1;
    if (validarMes30(mes) && dia <= 30 && anio > 0 && dia > 0)
        band = 1;
    if (mes == 2 && dia == 29 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) && anio > 0)
    {
        band = 1;
    }
    if (mes == 2 && anio > 0 && dia <= 28 && dia > 0)
    {
        band = 1;
    }
    return band;
}

int compararFecha(int anio_nac, int anio_hoy, int mes_nac, int mes_hoy, int dia_nac, int dia_hoy)
{
    int band = 1;
    if (anio_nac > anio_hoy)
        band = 0;
    if (anio_nac == anio_hoy && mes_nac > mes_hoy)
        band = 0;
    if (anio_nac == anio_hoy && mes_nac == mes_hoy && dia_nac > dia_hoy)
        band = 0;
    return band;
}

int main()
{
    int dia_nac, mes_nac, anio_nac, dia_hoy, mes_hoy, anio_hoy;
    do
    {
        printf("\nIngrese la fecha de nacimiento: ");
        scanf("%d/%d/%d", &dia_nac, &mes_nac, &anio_nac);
        while (!validar_fecha(dia_nac, mes_nac, anio_nac))
        {
            printf("\nIngrese una fecha valida: ");
            scanf("%d/%d/%d", &dia_nac, &mes_nac, &anio_nac);
        }
        printf("\nIngrese la fecha de hoy: ");
        scanf("%d/%d/%d", &dia_hoy, &mes_hoy, &anio_hoy);
        while (!validar_fecha(dia_hoy, mes_hoy, anio_hoy))
        {
            printf("\nIngrese una fecha valida: ");
            scanf("%d/%d/%d", &dia_hoy, mes_hoy, anio_hoy);
        }
    } while (!compararFecha(anio_nac, anio_hoy, mes_nac, mes_hoy, dia_nac, dia_hoy));

    int edad = anio_hoy - anio_nac;
    if (mes_nac == mes_hoy)
    {
        if (dia_nac > dia_hoy)
            edad--;
    }
    else{
        if(mes_nac > mes_hoy) edad--;
    }
    printf("\nTiene %d anios\n",edad);

    return 0;
}