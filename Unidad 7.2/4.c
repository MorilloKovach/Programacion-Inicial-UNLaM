#include <stdio.h>

void IngrDato(int[5][12]);
void CantidadPorSucursalYRubro(int[5][12]);
void PedidoPorSucursal(int[5][12]);
void PedidoPorRubro(int[5][12]);
int RubroMayorPedido(int[5][12]);
int CantidadPedidosRubro7(int[5][12]);
int MinimoCantidadTotal(int[5][12]);
int RubrosSinPedidos(int[5][12]);

int main()
{
    int mat[5][12], i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            mat[i][j] = 0;
        }
    }
    IngrDato(mat);
    CantidadPorSucursalYRubro(mat);
    PedidoPorSucursal(mat);
    PedidoPorRubro(mat);
    printf("El rubro con mayor pedido fue %d.\n", RubroMayorPedido(mat));
    printf("La cantidad de pedidos en el rubro 7 fue: %d.\n", CantidadPedidosRubro7(mat));
    printf("La sucursal que pidio la menor cantidad total fue: %d.\n", MinimoCantidadTotal(mat));
    printf("La cantidad de rubros sin pedidos fue: %d.\n", RubrosSinPedidos(mat));
}

void IngrDato(int mat[5][12])
{
    int sucursal, rubro, cantidad_pedido;
    do
    {
        do
        {
            printf("\nIngrese el numero de la sucursal: ");
            scanf("%d", &sucursal);
        } while (sucursal < 0 || sucursal > 5);
        if (sucursal != 0)
        {
            do
            {
                printf("\nIngrese el codigo del rubro: ");
                scanf("%d", &rubro);
            } while (rubro <= 0 || rubro > 12);
            do
            {
                printf("\nIngrese la cantidad de pedidos: ");
                scanf("%d", &cantidad_pedido);
            } while (cantidad_pedido <= 0);
            mat[sucursal - 1][rubro - 1] += cantidad_pedido;
        }
    } while (sucursal != 0);
}

void CantidadPorSucursalYRubro(int mat[5][12])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            printf("La cantidad de pedidos en la sucursal %d y rubro %d fue: %d\n", i + 1, j + 1, mat[i][j]);
        }
    }
}

void PedidoPorSucursal(int mat[5][12])
{
    int i, j, sucursal[5];
    for (i = 0; i < 5; i++)
    {
        sucursal[i] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            sucursal[i] += mat[i][j];
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("La cantidad de pedidos en la sucursal %d es: %d\n", i + 1, sucursal[i]);
    }
}

void PedidoPorRubro(int mat[5][12])
{
    int i, j, rubros[12];
    for (i = 0; i < 12; i++)
    {
        rubros[i] = 0;
    }
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 5; j++)
        {
            rubros[i] += mat[j][i];
        }
    }
    for (i = 0; i < 12; i++)
    {
        printf("La cantidad de pedidos por rubro %d es: %d\n", i + 1, rubros[i]);
    }
}

int RubroMayorPedido(int mat[5][12])
{
    int suma = 0, maximo = 0, maxiRubro = -1, i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 5; j++)
        {
            suma += mat[j][i];
        }
        if (suma > maximo)
        {
            maximo = suma;
            maxiRubro = i + 1;
        }
        suma = 0;
    }
    return maxiRubro;
}

int CantidadPedidosRubro7(int mat[5][12])
{
    int j, cantidad_pedidos = 0;
    for (j = 0; j < 5; j++)
    {
        cantidad_pedidos += mat[j][6];
    }
    return cantidad_pedidos;
}

int MinimoCantidadTotal(int mat[5][12])
{
    int minimo, bandera = 1, tot_suma = 0, min_sucursal = 0, i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            tot_suma += mat[i][j];
        }
        if (bandera || tot_suma < minimo)
        {
            bandera = 0;
            minimo = tot_suma;
            min_sucursal = i + 1;
        }
        tot_suma = 0;
    }
    return min_sucursal;
}

int RubrosSinPedidos(int mat[5][12])
{
    int suma = 0, i, j, cant = 0;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 5; j++)
        {
            suma += mat[j][i];
        }
        if (suma == 0)
        {
            cant++;
        }
        suma = 0;
    }
    return cant;
}