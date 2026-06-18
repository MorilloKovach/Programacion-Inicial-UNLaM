/*
10001 a 10010
Tenemos que garantizar que ese codigo no exista ya.
*/

/*
Codigos[i] = codigo-especifico
Pedidos[i] = pedidos-para-ese-codigo-especifico
Precio[i] = precio para cada producto de forma unitaria
*/

#include<stdio.h>

int ExisteProducto(int[], int, int);
int EstaDentroDelRango(int, int, int);
void IngrDatosProductos(int[], float[], int);
void IngrDatosPedidos(int[], int[], int);
void ListadoProducto(int[], int[], float[], int);
float Porcentaje(int[], int);
int MenorImporte(int[], float[], int[], int);

int main()
{
    int cantidad = 10;
    int Codigos[10], Pedidos[10];
    float Precios[10];
    int i;
    for (i = 0; i < cantidad; i++)
    {
        Pedidos[i] = 0;
    }
    IngrDatosProductos(Codigos, Precios, cantidad);
    IngrDatosPedidos(Codigos, Pedidos, cantidad);
    ListadoProducto(Codigos, Pedidos, Precios, cantidad);
    printf("\nEl porcentaje de los productos vendidos en mas de 1000 unidades es: %.2f", Porcentaje(Pedidos, cantidad));
    printf("\nEl producto que menos vendio fue: %d", MenorImporte(Codigos, Precios, Pedidos, cantidad));
}

int ExisteProducto(int Codigos[], int cantidad, int codigo)
{
    int i = 0, posicion = -1;
    while (i < cantidad && posicion == -1)
    {
        if (Codigos[i] == codigo)
        {
            posicion = i;
        }
        i++;
    }
    return posicion;
}
int EstaDentroDelRango(int limite_inferior, int limite_superior, int numero)
{
    int PerteneceAlRango = 0;
    if (limite_inferior <= numero && numero <= limite_superior)
    {
        PerteneceAlRango = 1;
    }
    return PerteneceAlRango;
}

void IngrDatosProductos(int Codigos[], float Precios[], int cantidad)
{
    int i, codigo;
    float precio;
    for (i = 0; i < cantidad; i++)
    {
        printf("\nIngrese el codigo del producto: ");
        scanf("%d", &codigo);
        while (!EstaDentroDelRango(10001, 10010, codigo) || ExisteProducto(Codigos, cantidad, codigo) != -1)
        {
            printf("\nError. Ingrese un codigo valido: ");
            scanf("%d", &codigo);
        }
        printf("\nIngrese el precio del producto: ");
        scanf("%f", &precio);
        while (precio <= 0)
        {
            printf("\nError. Ingrese un precio valido: ");
            scanf("%f", &precio);
        }
        Precios[i] = precio;
        Codigos[i] = codigo;
    }
}

void IngrDatosPedidos(int Codigos[], int Pedidos[], int cantidad)
{
    int codigo, pedido, posicion;
    do
    {
        printf("\nIngrese un codigo: ");
        scanf("%d", &codigo);
        posicion = ExisteProducto(Codigos, cantidad, codigo);
        while (posicion == -1 && codigo != 0)
        {
            printf("\nError. Ingrese un codigo valido: ");
            scanf("%d", &codigo);
            posicion = ExisteProducto(Codigos, cantidad, codigo);
        }
        if (codigo != 0)
        {
            printf("\nIngrese la cantidad de unidades solicitadas: ");
            scanf("%d", &pedido);
            Pedidos[posicion] += pedido;
        }
    } while (codigo != 0);
}

void ListadoProducto(int Codigos[], int Pedidos[], float Precio[], int cantidad)
{
    int i, j, auxEnteros;
    float auxFlotante;
    for (i = 0; i < cantidad; i++)
    {
        for (j = i + 1; j < cantidad; j++)
        {
            if (Pedidos[i] < Pedidos[j])
            {
                auxEnteros = Pedidos[i];
                Pedidos[i] = Pedidos[j];
                Pedidos[j] = auxEnteros;

                auxEnteros = Codigos[i];
                Codigos[i] = Codigos[j];
                Codigos[j] = auxEnteros;

                auxFlotante = Precio[i];
                Precio[i] = Precio[j];
                Precio[j] = auxFlotante;
            }
        }
    }
    printf("\nCodigo\tUnidades Vendidas\t Precio unitario");
    for(i=0;i<cantidad;i++){
        printf("\n%d\t%d\t%.2f",Codigos[i], Pedidos[i], Precio[i]);
    }
}

float Porcentaje(int Pedidos[], int cantidad){
    int sumaMayoresA1000 = 0,i=0;
    for(i=0;i<cantidad;i++){
        if(Pedidos[i] >= 1000){
            sumaMayoresA1000++;
        }
    }
    return (float)sumaMayoresA1000/cantidad * 100.0;
}

int MenorImporte(int Codigos[], float Precios[], int Pedidos[], int cantidad){
    float minimo=0;
    int i, bandera=1, pos=0;
    for(i=0;i<cantidad;i++){
        if(bandera==1 || minimo > Precios[i] * Pedidos[i]){
            minimo = Precios[i] * Pedidos[i];
            bandera = 0;
            pos = i;
        }
    }
    return Codigos[pos];
}

/*
10001 100
10002 200
10003 300
10004 400
10005 500
10006 600
10007 700
10008 800
10009 900
10010 1000
10001 100
10002 50
10003 300
10004 1500
*/