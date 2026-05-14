#include <stdio.h>

int obtenerCodigo(int);
void ponerCero(float[], int[], int[]);
void leerFacturas(float[], int[], int[]);
void total_dia(float[], int[]);
float noVendieron(int []);
int maximaVenta(int[], int[]);
float promedio(float[], int[]);
void escribirFacturas(float[], int[], int[]);
int main()
{
    float ventas[12];
    int codigo[12], cantidad[12]; 
    int dia, mes, anio;
    ponerCero(ventas, cantidad, codigo);
    printf("Ingrese la fecha: ");
    scanf("%d/%d/%d",&dia,&mes,&anio);

    leerFacturas(ventas, cantidad, codigo);
    printf("Venta del dia: %d/%d/%d\n",dia,mes,anio);
    escribirFacturas(ventas,cantidad,codigo);

    printf("No vendieron un %.2f%%\n",noVendieron(cantidad));
    printf("El que obtuvo la mayor cantidad de facturas fue: %d\n",maximaVenta(cantidad, codigo));
    printf("El promedio de ventas fue %.2f\n", promedio(ventas, cantidad));
}

void escribirFacturas(float ventas[], int cantidad[], int codigo[]){
    printf("Nro de vendedor. \t Importe vendido. \t Cantidad de facturas emitidas\n");
    for(int i = 0; i<12; i++){
        printf("%d\t %.2f\t %d\n", codigo[i], ventas[i], cantidad[i]);
    }
    printf("TOTAL: ");
    total_dia(ventas, cantidad);
}
float promedio(float ventas[], int cantidad[]){
    float res = 0;
    int NoSirven = 0;
    for(int i = 0; i<12; i++){
        res+=ventas[i];
        NoSirven += (cantidad[i] == 0);
    }
    return res/(12 - NoSirven);
}

int maximaVenta(int cantidad[], int codigos[]){
    float maxi = -1;
    int codigo = 101;
    for(int i = 0; i<12; i++){
        if(cantidad[i] > maxi){
            maxi = cantidad[i];
            codigo = codigos[i];
        }
    }
    return codigo;
}
float noVendieron(int cantidad[]){
    int suma = 0;
    for(int i = 0; i<12; i++){
        suma+=(cantidad[i] == 0);
    }
    return (float)suma/12 * 100.0;
}

void total_dia(float ventas[], int cantidad[]){
    float total = 0;
    int cantidad_total = 0;
    for(int i = 0; i<12; i++){
        total+=ventas[i];
        cantidad_total+=cantidad[i];
    }
    printf("\t %.2f \t %d\n",total, cantidad_total);
}

void leerFacturas(float ventas[], int cantidad[], int codigo[])
{
    int facturas, codigo_vendedor;
    float importe_ventas;
    printf("Ingrese el numero de la factura: ");
    scanf("%d", &facturas);
    while (facturas != 0)
    {
        while (facturas < 0)
        {
            printf("\nIngrese un valor valido de factura: ");
            scanf("%d", &facturas);
        }
        printf("\nIngrese un codigo de vendedor: ");
        scanf("%d", &codigo_vendedor);
        while (obtenerCodigo(codigo_vendedor) < 0 || obtenerCodigo(codigo_vendedor) > 11)
        {
            printf("\nIngrese un codigo de vendedor valido: ");
            scanf("%d", &codigo_vendedor);
        }
        printf("\nIngrese el importe de venta: ");
        scanf("%f", &importe_ventas);
        while (importe_ventas < 0)
        {
            printf("\nIngrese un valor valido de venta: ");
            scanf("%f", &importe_ventas);
        }
        ventas[obtenerCodigo(codigo_vendedor)]+=importe_ventas;
        cantidad[obtenerCodigo(codigo_vendedor)]++;
        printf("Ingrese el numero de la factura: ");
        scanf("%d", &facturas);
    }
}

void ponerCero(float ventas[], int cantidad[], int codigo[])
{
    for (int i = 0; i < 12; i++)
    {
        ventas[i] = 0;
        cantidad[i] = 0;
        codigo[i] = 101 + i;
    }
}
int obtenerCodigo(int codigo)
{
    return codigo - 101;
}
