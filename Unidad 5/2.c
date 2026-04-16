/*
 Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite
un ‘*’. Se desea obtener e informar cuantos caracteres ingresados son numéricos y cuantos
alfabéticos. Estos últimos tienen que mostrarse separados por mayúsculas y minúsculas.
También informar la cantidad de otros símbolos que no sean ni letras ni números
*/

#include<stdio.h>

int main(){
    char ing = 'a';
    int nums=0, alfaMay=0,alfaMin=0;
    scanf(" %c",&ing);
    while(ing != '*'){
        if(ing >= '0' && ing <= '9') nums++;
        else if((ing >= 'A' && ing <= 'Z')) alfaMay++;
        else if((ing >= 'a' && ing <= 'z')) alfaMin++;
        getchar();
        scanf(" %c",&ing);
    }
    printf("Se han ingresado %d numeros. \n",nums);
    printf("Se han ingresado %d letras minusculas\n",alfaMin);
    printf("Se han ingresado %d letras mayusculas. \n",alfaMay);
}