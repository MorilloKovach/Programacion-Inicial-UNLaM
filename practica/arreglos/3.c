/*
50 empleados
Nos pide los empleados de maximo sueldo
El fin se da con legajo = 0
los legajos tienen 4 cifras. No tienen que haber repetido
*/

#include<stdio.h>

int IngrDatos(int legajo[], float sueldos[], int fin);
float MaximoSueldo(float sueldos[], int cantidad);
void EmpleadosMaximoSueldo(float sueldos[], int legajo[], float MaximoSueldo, int cantidad);
int ExisteEmpleado(int legajos[], int legajo, int cantidad);

int main(){
    int legajos[50], cantidad_empleados;
    float sueldos[50], maximo_sueldo;
    cantidad_empleados = IngrDatos(legajos, sueldos, 0);
    maximo_sueldo = MaximoSueldo(sueldos, cantidad_empleados);
    EmpleadosMaximoSueldo(sueldos, legajos, maximo_sueldo, cantidad_empleados);
}

int IngrDatos(int legajo[], float sueldos[], int fin){
    int cantidad=0, legajo_empleado;
    float sueldo_empleado;
    do{
        printf("Ingrese el legajo del empleado: ");
        scanf("%d",&legajo_empleado);
        while((legajo_empleado != 0) && ((legajo_empleado < 1000 || legajo_empleado > 9999) || ExisteEmpleado(legajo, legajo_empleado, cantidad))){
            printf("Ingrese el legajo del empleado: ");
            scanf("%d",&legajo_empleado);
        }
        if(legajo_empleado != 0){
            printf("\nIngrese el sueldo del empleado: ");
            scanf("%f",&sueldo_empleado);
            while(sueldo_empleado <= 0){
                printf("\nIngrese el sueldo del empleado: ");
                scanf("%f",&sueldo_empleado);
            }
            legajo[cantidad] = legajo_empleado;
            sueldos[cantidad] = sueldo_empleado;
            cantidad++;
        }
    }while(legajo_empleado != 0 && cantidad < 50);
    return cantidad;
}

float MaximoSueldo(float sueldos[], int cantidad){
    float sueldo_maximo = 0.0;
    int i;
    for(i=0;i<cantidad;i++){
        if(sueldo_maximo < sueldos[i]){
            sueldo_maximo = sueldos[i];
        }
    }
    return sueldo_maximo;
}

void EmpleadosMaximoSueldo(float sueldos[], int legajo[], float maximoSueldo, int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        if(sueldos[i] == maximoSueldo){
            printf("\nEl empleado con legajo %d tiene el maximo sueldo. ",legajo[i]);
        }
    }
}

int ExisteEmpleado(int legajos[], int legajo, int cantidad){
    int Existir = 0, i=0;
    while(i < cantidad && Existir==0){
        if(legajos[i] == legajo){
            Existir = 1;
        }
        i++;
    }
    return Existir;
}