#include <stdio.h>

/*
31 dias: 1,3,5,7,8,10,12
30 dias: 4,6,9,11
28 dias: 2
*/

int validar_fecha(int dia, int mes, int anio)
{
    if (dia < 0 || mes < 0 || anio < 0)
        return 0;
    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia <= 31)
        return 1;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia <= 30)
        return 1;
    if ((mes == 2 && dia <= 28) || (mes == 2 && anio % 4 == 0 && dia <= 29))
        return 1;
    return 0;
}

void retroceder_dia(int *d, int *m, int *a)
{
    int dia = *d;
    int mes = *m;
    int anio = *a;
    if (dia == 1 && mes == 1)
    {
        dia = 31;
        anio--;
        mes = 12;
    }
    else{
        if (dia == 1)
        {
            mes--;
            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                dia = 31;
            else
                if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                    dia = 30;
                else 
                    if (mes == 2){
                        if (anio % 4 == 0)
                            dia = 29;
                        else
                            dia = 28;
                    }
        }
        else{
            dia--;
        }
    }
    *d = dia;
    *m = mes;
    *a = anio;
}

int main()
{
    int dia, mes, anio;
    printf("Dia ");
    scanf("%d", &dia);
    printf(" Mes ");
    scanf("%d", &mes);
    printf(" Año ");
    scanf("%d", &anio);

    while (!validar_fecha(dia, mes, anio))
    {
        printf("\nIngrese una fecha valida: ");
        scanf("%d", &dia);
        printf("/");
        scanf("%d", &mes);
        printf("/");
        scanf("%d", &anio);
    }
    retroceder_dia(&dia,&mes,&anio);
    printf("%d/%d/%d",dia,mes,anio);
}