#include <stdio.h>

void IngrDatos(float[], int[], int);
void IngrDatosTours(int[][12], float[], int[], int);
int ExisteTour(int[], int, int);
void TotalVendido(int[][12], float[], int[], int, int);
float Porcentaje(int[][12], int[], int, int);
int EstaEnRango(int, int, int);
void VendidoPorMes(int[][12], int[], int, int);

int main()
{
    int cantidad = 10, meses = 12; // Aseguro la cantidad y meses.
    float Precios[cantidad];
    int Codigos[cantidad];
    int Vendidos[cantidad][12];
    int i, j;
    for (i = 0; i < cantidad; i++)
    {
        Precios[i] = Codigos[i] = 0;
        for (j = 0; j < meses; j++)
        {
            Vendidos[i][j] = 0;
        }
    }
    IngrDatos(Precios, Codigos, cantidad);
    IngrDatosTours(Vendidos, Precios, Codigos, cantidad);
    TotalVendido(Vendidos, Precios, Codigos, cantidad, meses);
    VendidoPorMes(Vendidos, Codigos, cantidad, meses);
    printf("\nEl porcentaje de los tours que vendieron en menos de 4 meses fue %.2f%%",Porcentaje(Vendidos, Codigos, cantidad, meses));
    return 0;
}

float Porcentaje(int Vendidos[][12], int Codigos[], int cant, int meses)
{
    int i, j;
    int ProdTotal[cant];
    float calc=0;

    for (i = 0; i < cant; i++)
    {
        ProdTotal[i] = 0;
    }
    for (i = 0; i < cant; i++)
    {
        for (j = 0; j < meses; j++)
        { 
            ProdTotal[i] += (Vendidos[i][j] > 0);
        }
    }
    for (i = 0; i < cant; i++)
    {
        if(ProdTotal[i] > 0 && ProdTotal[i] < 4){
            calc++;
            printf("\n%d vendio en menos de 4 meses",Codigos[i]);
        }
    }
    return calc/cant * 100.0;
}

void VendidoPorMes(int Vendidos[][12], int Codigos[], int cant, int meses)
{
    int i, j;
    for (i = 0; i < meses; i++)
    {
        printf("\n\n\nLa cantidad de tours vendidos en el mes %d:\n ", i + 1);
        for (j = 0; j < cant; j++)
        {
            printf("\n%d: %d", Codigos[j], Vendidos[j][i]);
        }
    }
}

void TotalVendido(int Vendidos[][12], float Precios[], int Codigos[], int cant, int meses)
{
    int i, j;
    float ImporteTotal[cant];
    int TotalVendido[cant];
    for (i = 0; i < cant; i++)
    {
        ImporteTotal[i] = TotalVendido[i] = 0;
    }
    for (i = 0; i < cant; i++)
    {
        for (j = 0; j < meses; j++)
        {
            ImporteTotal[i] += Precios[i] * Vendidos[i][j];
            TotalVendido[i] += Vendidos[i][j];
        }
    }
    printf("\nCodigo de tour \t Cantidad vendida \t Importe Vendido");
    for (i = 0; i < cant; i++)
    {
        printf("\n%d\t%d\t%.2f", Codigos[i], TotalVendido[i], ImporteTotal[i]);
    }
}

int ExisteTour(int Codigos[], int cant, int codigo)
{
    int i = 0, pos = -1;
    while (i < cant && pos == -1)
    {
        if (Codigos[i] == codigo)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

void IngrDatosTours(int Vendidos[][12], float Precios[], int Codigos[], int cant)
{
    int codigo, mes, cliente, cantidad, pos;
    do
    {
        printf("\nIngrese el numero del cliente: ");
        scanf("%d", &cliente);
        while (cliente < 0)
        {
            printf("\nIngrese el numero del cliente: ");
            scanf("%d", &cliente);
        }
        if (cliente != 0)
        {
            printf("\nIngrese el codigo del tour: ");
            scanf("%d", &codigo);
            pos = ExisteTour(Codigos, cant, codigo);

            printf("\nIngrese el mes a realizar el tour: ");
            scanf("%d", &mes);
            while (mes < 1 || mes > 12)
            {
                printf("\nIngrese el mes a realizar el tour: ");
                scanf("%d", &mes);
            }
            printf("\nIngrese la cantidad vendida: ");
            scanf("%d", &cantidad);
            while (cantidad <= 0)
            {
                printf("\nIngrese la cantidad vendida: ");
                scanf("%d", &cantidad);
            }
            if (pos == -1)
            {
                printf("\nTOUR INVALIDO");
            }
            else
            {
                Vendidos[pos][mes - 1] += cantidad;
            }
        }

    } while (cliente != 0);
}

int EstaEnRango(int linf, int lsup, int na)
{
    return linf <= na && na <= lsup;
}

void IngrDatos(float Precios[], int Codigos[], int cant)
{
    int i;
    for (i = 0; i < cant; i++)
    {
        printf("\nIngrese el codigo del tour %d: ", i + 1);
        scanf("%d", &Codigos[i]);
        while (!EstaEnRango(1000, 9999, Codigos[i]))
        {
            printf("\nIngrese un codigo de 4 cifras: ");
            scanf("%d", &Codigos[i]);
        }
        printf("\nIngrese el precio del tour %d: ", Codigos[i]);
        scanf("%f", &Precios[i]);
        while (Precios[i] <= 0)
        {
            printf("\nIngrese un valor positivo de precio: ");
            scanf("%f", &Precios[i]);
        }
    }
}
