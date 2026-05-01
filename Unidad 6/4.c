/*
Realizar un programa que al comienzo solicite el ingreso de dos números enteros y luego
muestre por pantalla el siguiente menú (las xx de los números deben ser reemplazadas con
los valores correspondientes):
Menú de Opciones
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos Números
6) Salir
Ingrese su opción:
Si se ingresa el número de la opción del 1 al 4, se realiza la operación y muestra el resultado
hasta que se presione una tecla. Luego vuelve a mostrar el menú para poder realizar otra
operación con los mismos números. La opción 5 pide el ingreso de dos nuevos números de
trabajo mientras que la opción 6 sale y cierra el programa.
El ingreso de la opción debe estar validado y en caso de ingresarse un número no válido
debe solicitarlo nuevamente.
Usar una función para mostrar el menú y retornar el valor elegido.
*/

#include<stdio.h>
#include<stdlib.h>
int mostrarMenu();
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
float dividir(int a, int b);

int main(){
    int a,b;
    printf("\nIngrese dos valores: ");
    scanf("%d%d",&a,&b);
    int s = mostrarMenu();
    while(s < 1 || s > 6){
        printf("\nDigite un valor valido: ");
        s = mostrarMenu();
    }
    while(s != 6){
        switch(s){
            case 1:
                printf("La suma es: %d",sumar(a,b));
                break;
            case 2:
                printf("La resta es: %d",restar(a,b));
                break;
            case 3:
                printf("La multiplicacion es: %d",multiplicar(a,b));
                break;
            case 4:
                printf("La division es: %.2f",dividir(a,b));
                break;
            case 5:
                printf("Ingrese dos valores: ");
                scanf("%d%d",&a,&b);
            case 6:
                printf("Rompiendo programa");
                break;
            default:
                while(s < 1 || s > 6){
                    printf("Ingrese un valor valido: ");
                    scanf("%d",&s);
                }
        }
        printf("\nIngrese otra opcion: ");
        s = mostrarMenu();
    }
}

int mostrarMenu(){
    int operacion;
    printf("\n----Menu de opciones-----\n");
    printf("\n1.- Sumar");
    printf("\n2.- Restar");
    printf("\n3.- Multiplicar");
    printf("\n4.- Dividir");
    printf("\n5.- Ingresar Nuevos Numeros");
    printf("\n6.- Salir");
    printf("\nIngrese la opcion: ");
    scanf("%d",&operacion);
    return operacion;
}
int sumar(int a, int b){
    return a+b;
}
int restar(int a, int b){
    return a-b;
}
int multiplicar(int a, int b){
    return a*b;
}
float dividir(int a, int b){
    if(b==0) return 0.0;
    return (float)a/b;
}
