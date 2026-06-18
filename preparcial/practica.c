#include <stdio.h>

void IngrDatos(int[], float[]);
void IngresoDatos2(int[], float[], int[]);
void SueldoAscendente(float[], int[]);
void MayoresSueldos(int[], float[]);
void PromedioSeccion(float[], int[]);
int ExisteEmpleado(int[], int);
int main()
{
    int legajos_empleados[350], seccion[350];
    float sueldo_hora[350];
    int i;
    for (i = 0; i < 350; i++)
    {
        legajos_empleados[i] = seccion[i] = sueldo_hora[i] = 0;
    }
    IngrDatos(legajos_empleados,sueldo_hora);
    IngresoDatos2(legajos_empleados, sueldo_hora, seccion);
    PromedioSeccion(sueldo_hora, seccion);
    MayoresSueldos(legajos_empleados, sueldo_hora);
    SueldoAscendente(sueldo_hora, seccion);
}

void IngrDatos(int legajos[], float sueldos[])
{
    int cantidad = 0, legajo;
    float sueldo_hora;
    do
    {
        printf("\nIngrese el legajo del empleado %d: ", cantidad + 1);
        scanf("%d", &legajo);
        while ((legajo < 1000 || legajo > 9999 || ExisteEmpleado(legajos, legajo) != -1) && legajo != 0)
        {
            printf("\nIngrese el legajo del empleado %d: ", cantidad + 1);
            scanf("%d", &legajo);
        }
        if (legajo != 0)
        {
            printf("\nDigite su sueldo: ");
            scanf("%f", &sueldo_hora);
            while (sueldo_hora <= 0)
            {
                printf("\nDigite su sueldo: ");
                scanf("%f", &sueldo_hora);
            }
            legajos[cantidad] = legajo;
            sueldos[cantidad] = sueldo_hora;
            cantidad++;
        }
    } while (cantidad < 350 && legajo != 0);
}
int ExisteEmpleado(int legajos[], int legajo)
{
    int i = 0, indice = -1;
    while (i < 350 && indice == -1)
    {
        if (legajos[i] == legajo)
        {
            indice = i;
        }
        i++;
    }
    return indice;
}
void IngresoDatos2(int legajos[], float sueldos[], int seccion[])
{
    int legajo, horas, seccion_trabajador, indice,pos;
    do
    {
        printf("\nIngrese un legajo: ");
        scanf("%d", &legajo);
        indice = ExisteEmpleado(legajos,legajo);
        while ((legajo != 0 && indice == -1) || (indice != -1 && seccion[indice] != 0))
        {
            printf("\nIngrese un legajo valido: ");
            scanf("%d", &legajo);
            indice = ExisteEmpleado(legajos,legajo);
        }
        if (legajo != 0)
        {
            printf("\nIngrese la cantidad de horas a trabajar: ");
            scanf("%d", &horas);
            while (horas < 0 || horas > 14)
            {
                printf("\nIngrese una cantidad de horas de trabajo validas: ");
                scanf("%d", &horas);
            }
            sueldos[indice] = sueldos[indice] * horas * 20;
            printf("\nIngrese la seccion del empleado: ");
            scanf("%d", &seccion_trabajador);
            while (seccion_trabajador < 101 || seccion_trabajador > 108)
            {
                printf("\nIngrese la seccion del empleado: ");
                scanf("%d", &seccion_trabajador);
            }
            seccion[indice] = seccion_trabajador;
        }
    } while (legajo != 0);
}

void MayoresSueldos(int legajos[], float sueldos[])
{
    float maximo = 0;
    int i;
    for (i = 0; i < 350; i++)
    {
        if (sueldos[i] > maximo)
        {
            maximo = sueldos[i];
        }
    }
    for (i = 0; i < 350; i++)
    {
        if (sueldos[i] == maximo)
        {
            printf("\nEl empleado cuyo legajo es %d tiene el maximo sueldo", legajos[i]);
        }
    }
}

void PromedioSeccion(float sueldos[], int seccion[])
{
    float TotalSueldo[8];
    int EmpleadosPorSeccion[8];
    int i, pos;
    for (i = 0; i < 8; i++)
    {
        TotalSueldo[i] = EmpleadosPorSeccion[i] = 0;
    }
    for (i = 0; i < 350; i++)
    {
        pos = seccion[i] - 101;
        if(pos>=0){
            EmpleadosPorSeccion[pos]++;
            TotalSueldo[pos]+=sueldos[i];
        }
    }
    for(i=0;i<8;i++){
        TotalSueldo[pos]/=EmpleadosPorSeccion[pos];
        printf("\nEl sueldo promedio de la seccion %d es %.2f",i+101, TotalSueldo[i]);
    }
}

void SueldoAscendente(float sueldos[], int seccion[]){
    float TotalSueldo[8];
    int PosSeccion[8];
    int i,j, pos;
    for (i = 0; i < 8; i++)
    {
        TotalSueldo[i] = 0;
        PosSeccion[i] = 101+i;
    }
    for (i = 0; i < 350; i++)
    {
        pos = seccion[i] - 101;
        if(pos>=0){
            TotalSueldo[pos]+=sueldos[i];
        }
    }
    for(i = 0; i<8; i++){
        for(j=i+1;j<8;j++){
            if(TotalSueldo[i] < TotalSueldo[j]){
                pos = TotalSueldo[i];
                TotalSueldo[i] = TotalSueldo[j];
                TotalSueldo[j] = pos;

                pos = PosSeccion[i];
                PosSeccion[i] = PosSeccion[j];
                PosSeccion[j] = pos;
            }
        }
    }
    printf("\nSueldos pagados por seccion al dia %d/%d/%d: ",11,6,2026);
    for(i=0;i<8;i++){
        printf("\nSeccion %d\t%.2f\n",PosSeccion[i], TotalSueldo[i]);
    }
}

/*
1000
200
2000
300
4000
500
8000
900
9000
1000
1500
300
0
1000
8
101
2000
8
102
2000
4000
8
102
9000
7
103
0


*/