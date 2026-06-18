#include <stdio.h>

void IngrDatos(char[][9], int[], int, int);
void Reservas(char[][9], int, int);
void MostrarMatriz(char[][9], int, int);
void FilasVacias(char[][9], int, int);
void EspectadoresMaximos(char[][9], int, int);
void ListarButacas(char[][9], int[], int, int);
void ordenar(int[], int[], int);
int SePuedeReservar(char[], int[], int, int, int);
int EstaDentroDelRango(int, int, int);
int ButacaInicial(int[], int, int);
void ModificarMatriz(char[], int[], int, int, int);
int HabilitadosConsecutivos(char[], int[], int, int, int);
int main()
{
    char Cine[12][9];
    int butaca[9];
    int filas = 12, butacas = 9, i, j, butak = 8;
    for (i = 0; i < 4; i++)
    {
        butaca[i] = butak;
        butak -= 2;
    }
    butak = 1;
    for (i = 4; i < 9; i++)
    {
        butaca[i] = butak;
        butak += 2;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d ", butaca[i]);
    }
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < butacas; j++)
        {
            Cine[i][j] = 'D';
        }
    }
    MostrarMatriz(Cine, filas, butacas);
    IngrDatos(Cine, butaca, filas, butacas);
    Reservas(Cine, filas, butacas);
    FilasVacias(Cine, filas, butacas);
    EspectadoresMaximos(Cine, filas, butacas);
    ListarButacas(Cine, butaca, filas, butacas);
    return 0;
}
void MostrarMatriz(char mat[][9], int filas, int butacas)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < butacas; j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ButacaInicial(int butaca[], int num_butaca, int butacas)
{
    int i = 0, pos = -1;
    while (i < butacas && pos == -1)
    {
        if (butaca[i] == num_butaca)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int SePuedeReservar(char fila[], int butaca[], int butacas, int num_butaca, int espacios)
{
    int i = 0, cant = 0, posible = 1;
    i = ButacaInicial(butaca, num_butaca, butacas);
    while (i < butacas && cant < espacios && posible == 1)
    {
        if (fila[i] == 'R')
        {
            posible = 0;
        }
        i++;
        cant++;
    }
    if (cant < espacios)
    {
        posible = 0;
    }
    return posible;
}

int EstaDentroDelRango(int linf, int lsup, int num)
{
    int band = 0;
    if (linf <= num && num <= lsup)
    {
        band = 1;
    }
    return band;
}

void ModificarMatriz(char fila[], int butaca[], int num_butaca, int butacas, int espacios)
{
    int pos = ButacaInicial(butaca, num_butaca, butacas), i;
    for (i = pos; i < pos + espacios; i++)
    {
        fila[i] = 'R';
    }
}
int HabilitadosConsecutivos(char fila[], int butacas[], int num_butaca, int butacasEspacios, int butaca)
{
    int i, max = 0, sum = 0;
    for (i = 0; i < butaca; i++)
    {
        if (fila[i] == 'R')
        {
            sum = 0;
        }
        else
        {
            sum++;
        }
        if (max < sum)
        {
            max = sum;
        }
    }
    return max;
}
void IngrDatos(char mat[][9], int butaca[], int filas, int butacas)
{
    int fila, butacaEspacios, numeroButaca;
    do
    {
        printf("\nIngrese la fila: ");
        scanf("%d", &fila);
        while (!EstaDentroDelRango(1, 12, fila) && fila >= 0)
        {
            printf("\nError. Ingrese un numero de fila valido: ");
            scanf("%d", &fila);
        }
        if (fila > 0)
        {
            printf("\nIngrese la cantidad de butacas a reservar: ");
            scanf("%d", &butacaEspacios);
            while (!EstaDentroDelRango(1, 9, butacaEspacios))
            {
                printf("\nError, no puso una cantidad valida de butacas: ");
                scanf("%d", &butacaEspacios);
            }
            printf("\nIngrese el numero del cual desea arrancar a reservar butaca: ");
            scanf("%d", &numeroButaca);
            while (!EstaDentroDelRango(1, 9, numeroButaca) || 
            (mat[fila - 1][ButacaInicial(butaca, numeroButaca, butacas)] == 'R' && 
            HabilitadosConsecutivos(mat[fila - 1], butaca, numeroButaca, butacaEspacios, butacas) - butacaEspacios >= 0))
            {
                printf("\nError. Ingrese un numero valido: ");
                scanf("%d", &numeroButaca);
            }

            if (SePuedeReservar(mat[fila - 1], butaca, butacas, numeroButaca, butacaEspacios))
            {
                ModificarMatriz(mat[fila - 1], butaca, numeroButaca, butacas, butacaEspacios);
            }
            else
            {
                printf("\nError.");
            }
        }
        MostrarMatriz(mat, filas, butacas);
    } while (fila >= 0);
}

void Reservas(char mat[][9], int filas, int butacas)
{
    int reservado = 0, noreservado = 0, i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < butacas; j++)
        {
            reservado += (mat[i][j] == 'R');
            noreservado += (mat[i][j] == 'D');
        }
    }
    printf("\nExisten %d asientos disponibles y %d asientos reservados", noreservado, reservado);
}

void FilasVacias(char mat[][9], int filas, int butacas)
{
    int i, j, suma = 0;
    for (i = 0; i < filas; i++)
    {
        suma = 0;
        for (j = 0; j < butacas; j++)
        {
            suma += (mat[i][j] == 'D');
        }
        if (suma == 9)
        {
            printf("\nLa fila %d totalmente vacia. ", i + 1);
        }
    }
}

void EspectadoresMaximos(char mat[][9], int filas, int butacas)
{
    int i, j, suma = 0, max = 0;
    for (i = 0; i < filas; i++)
    {
        suma = 0;
        for (j = 0; j < butacas; j++)
        {
            suma += (mat[i][j] == 'R');
        }
        if (max < suma)
        {
            max = suma;
        }
    }
    for (i = 0; i < filas; i++)
    {
        suma = 0;
        for (j = 0; j < butacas; j++)
        {
            suma += (mat[i][j] == 'R');
        }
        if (max == suma)
        {
            printf("\nLa fila %d tuvo la mayor cantidad de espectadores: ", i + 1);
        }
    }
}

void ListarButacas(char mat[][9], int butacasOrd[], int filas, int butacas)
{
    int i, j, cantidadButacas[9], butacasOrd2[9];
    for(i=0;i<butacas;i++){
        butacasOrd2[i] = butacasOrd[i]-1;
        printf("%d ",butacasOrd2[i]);
    }
    for (i = 0; i < butacas; i++)
    {
        cantidadButacas[i] = 0;
    }
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < butacas; j++)
        {
            if (mat[i][j] == 'R')
            {
                cantidadButacas[butacasOrd2[j]]++;
            }
        }
    }
    ordenar(butacasOrd2, cantidadButacas, butacas);

    printf("\nButaca\tCantidad.");
    for (i = 0; i < butacas; i++)
    {
        printf("\n%d\t%d", butacasOrd2[i]+1, cantidadButacas[i]);
    }
}

void ordenar(int butacasOrd[], int cantidadButacas[], int butacas)
{
    int i, j, aux, miniIndice;
    for (i = 0; i < butacas; i++)
    {
        miniIndice = i;
        for (j = i + 1; j < butacas; j++)
        {
            if (cantidadButacas[j] > cantidadButacas[miniIndice])
            {
                miniIndice = j;
            }
        }
        if (miniIndice != i)
        {
            aux = cantidadButacas[i];
            cantidadButacas[i] = cantidadButacas[miniIndice];
            cantidadButacas[miniIndice] = aux;

            aux = butacasOrd[i];
            butacasOrd[i] = butacasOrd[miniIndice];
            butacasOrd[miniIndice] = aux;
        }
    }
}