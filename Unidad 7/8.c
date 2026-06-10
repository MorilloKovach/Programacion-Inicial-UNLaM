#include<stdio.h>

int CargaEmpleados(int[], int[], float[]);
void CuentaPorSector(int[], int);
float importeAPagar(float[], int);
int existeEmpleado(int, int, int[]);
int comprobarRango(int, int, int);
int main(){
    int dni_empleados[100], codigo_sector[100],n;
    float sueldos[100], total;
    for(int i = 0; i<100; i++){
        codigo_sector[i] = dni_empleados[i] = sueldos[i] = 0;
    }
    n = CargaEmpleados(dni_empleados, codigo_sector, sueldos);
    CuentaPorSector(codigo_sector, n);
    total = importeAPagar(sueldos, n);
    printf("\nEl total a pagar es: %.2f$",total);   
}

int existeEmpleado(int n, int dni, int dni_empleados[100]){
    int i=0, existe=0;
    while(i<=n && !existe){
        if(dni_empleados[i] == dni){
            existe = 1;
        }
        i++;
    }
    return existe;
}

float importeAPagar(float salarios[], int n){
    float total = 0;
    int i;
    for(i=0;i<n;i++){
        total+=salarios[i];
    }
    return total;
}

int comprobarRango(int valor, int minimo, int maximo){
    return valor >= minimo && valor <= maximo;
}
void CuentaPorSector(int sectores[], int n){
    int c_sectores[5], i;
    for(int i = 0; i<5; i++){
        c_sectores[i] = 0;
    }
    for(i=0;i<n;i++){
        c_sectores[sectores[i]-1]++;
    }
    for(int i = 0; i<5; i++){
        printf("\nLa cantidad de empleados en el sector %d es: %d ",i+1, c_sectores[i]);
    }

}
int CargaEmpleados(int dni_empleados[100], int codigo_sector[100], float sueldos[100]){
    int pedirDni = 0, cont = 0, codigoS = 0;
    float salario=0;
    printf("\nIngrese el dni del empleado: ");
    scanf("%d",&pedirDni);
    while(!comprobarRango(pedirDni, 1000000, 99999999) && pedirDni != 99){
        printf("\nIngrese un DNI valido: ");
        scanf("%d",&pedirDni);
    }
    while(cont<100 && pedirDni != 99){
        dni_empleados[cont] = pedirDni;
        printf("\nIngrese el codigo del sector: ");
        scanf("%d",&codigoS);
        while(!comprobarRango(codigoS, 1, 5)){
            printf("\nIngrese un sector valido: ");
            scanf("%d",&codigoS);
        }
        codigo_sector[cont] = codigoS;
        printf("\nIngrese el salario: ");
        scanf("%f", &salario);
        while(!comprobarRango(salario, 0, 99999999)){
            printf("\nIngrese un valor valido: ");
            scanf("%f",&salario);
        }
        sueldos[cont] = salario;
        if(cont < 99){
            printf("\nIngrese el DNI del empleado: ");
            scanf("%d",&pedirDni);
            while((!comprobarRango(pedirDni, 1000000, 99999999) || existeEmpleado(cont,pedirDni,dni_empleados)) && pedirDni != 99){
                printf("\nIngrese un DNI valido: ");
                scanf("%d",&pedirDni);
            }
        }
        cont++;
    }
    return cont;
}