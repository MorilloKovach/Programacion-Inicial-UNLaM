/*
    COnfeccionba un programa que ingrese una medida de 'pieas y la exhiba convertida a yardas, pulgadas , centrimetros y metros. Informar con mensajes aclaratorios. NOTA: 1 pie = 10 pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.
*/
# include "stdio.h"

int main () {
    int pies;

    // int getPercentage(char key) {
    //     int values = {
    //         pulgada = 12,
    //         yarda = 3,
    //         centimero = 2.54
    //     }
    //     return (pies*100)/values[char]
    // }

    printf("Ingrese la cantidad de pies\n");
    scanf("%d", &pies);
    int pulgadas = pies * 12;
    printf("las pulgadas son %d \n", pulgadas);
    
    int yarda = pies/3;
    printf("las yarda son %d \n", yarda);
    
    int centimetros = pulgadas * 2.54;
    printf("las centimetros son %d \n", centimetros);
}