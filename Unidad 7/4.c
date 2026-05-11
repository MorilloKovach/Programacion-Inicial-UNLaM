#include <stdio.h>

void cargarDatos(float[]);
int obtenerCodigo(int);
void realizarPedidos(int pedido[]);
void ponerCero(int pedido[], int codigo[]);
void ordenarProductos(float precio[], int pedido[], int codigo[]);
int main()
{

    int codigo[10], pedido[10], cantidadMayor1000 = 0;
    float precio[10];
    float minimoPrecio = 999999999;
    ponerCero(pedido, codigo);
    cargarDatos(precio);
    realizarPedidos(pedido);
    ordenarProductos(precio, pedido, codigo);
    for (int i = 0; i < 10; i++)
    {
        printf("El total de unidades solicitadas para el producto %d fue: %d y su importe total fue %.2f\n", codigo[i], pedido[i], 1.0 * pedido[i] * precio[i]);
        if (pedido[i] >= 1000)
        {
            cantidadMayor1000++;
        }
        if (precio[i] * pedido[i] > 0 && precio[i] * pedido[i] < minimoPrecio)
        {
            minimoPrecio = precio[i] * pedido[i];
        }
    }
    printf("El porcentaje de unidades mayores a 1000 son: %.2f", (float)cantidadMayor1000 / 10 * 100);
    printf("Los codigos con minimos importes son: ");
    for (int i = 0; i < 10; i++)
    {
        if (precio[i] * pedido[i] == minimoPrecio)
        {
            printf("%d ", i + 10001);
        }
    }
}

void ordenarProductos(float precio[], int pedido[], int codigo[])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (1.0 * precio[i] * pedido[i] > precio[j] * pedido[j])
            {
                int aux = pedido[i];
                float aux2 = precio[i];
                int aux3 = codigo[i];
                pedido[i] = pedido[j];
                precio[i] = precio[j];
                codigo[i] = codigo[j];
                codigo[j] = aux3;
                pedido[j] = aux;
                precio[j] = aux2;
            }
        }
    }
}
void cargarDatos(float precio[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Digite el precio del producto: ");
        scanf("%f", &precio[i]);
        while (precio[i] < 0)
        {
            printf("Digite un precio valido: ");
            scanf("%f", &precio[i]);
        }
    }
}
int obtenerCodigo(int codigo)
{
    return (codigo - 10001);
}

void realizarPedidos(int pedido[])
{
    int codigo, cantidad;
    printf("Ingrese el codigo: ");
    scanf("%d", &codigo);
    while ((codigo != 0) && (obtenerCodigo(codigo) < 0 || obtenerCodigo(codigo) > 9))
    {
        printf("Ingrese un buen codigo: ");
        scanf("%d", &codigo);
    }
    while (codigo != 0)
    {
        printf("\nIngrese la cantidad: ");
        scanf("%d", &cantidad);
        while (cantidad < 0)
        {
            printf("Ingrese una cantidad valida: ");
            scanf("%d", &cantidad);
        }
        pedido[obtenerCodigo(codigo)] += cantidad;
        printf("\nIngrese un codigo: ");
        scanf("%d", &codigo);
        while (codigo != 0 && obtenerCodigo(codigo) < 0 || obtenerCodigo(codigo) > 9)
        {
            printf("\nIngrese un codigo valido: ");
            scanf("%d", &codigo);
        }
    }
}

void ponerCero(int pedido[], int codigo[])
{
    for (int i = 0; i < 10; i++)
    {
        codigo[i] = i + 10001;
        pedido[i] = 0;
    }
}