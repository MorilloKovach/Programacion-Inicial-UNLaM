#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int arrA[10], arrB[10], arrC[10], arrD[10];
    int suma=0, N, cant=0;
    srand(time(NULL));
    for(int i = 0; i<10; i++){
        arrA[i] = rand()%10;
    }
    for(int i = 0; i<10; i++){
        arrB[i] = arrA[i];
    }
    for(int i = 0; i<10; i++){
        arrC[i] = arrA[i] + arrB[i];
    }
    for(int i = 0; i<10; i++){
        arrD[i] = arrA[9-i];
    }
    printf("Arr1 \t Arr2 \t Arr3 \t Arr4\n");
    for(int i = 0; i<10; i++){
        printf("%d \t %d \t %d \t %d\n", arrA[i], arrB[i], arrC[i], arrD[i]);
    }
    for(int i = 0; i<10; i++){
        if(arrA[i]%2==0){
            printf("En la pos %d hay un par\n",i+1);
        }
        else{
            printf("En la pos %d hay un impar\n",i+1);
        }
    }
    for(int i = 0; i<10; i++){
        suma+=arrA[i];
    }
    printf("La suma del arreglo A fue de %d\n",suma);
    printf("El valor promedio del arreglo A es: %d\n",suma/10);
    printf("Ingrese un valor: ");
    scanf("%d",&N);
    for(int i = 0; i<10; i++){
        if(N==arrA[i]){
            cant++;
        }
    }
    printf("La cantidad de elementos iguales a %d fue %d\n",N,cant);
}

/*

if(num >= 1){

}
else
{
    if(num >= 2)
    {
    }
    else
    {
        if(num>=3)
        {
        }
        else
        {
            if(num>=4)
            {
            }
            else
            {
                if(num>=5)
                {
                }
                else
                {
                }
            }
        }
    }
}

if(num>=1){
}
else if(num>=2){

}
else if(num>=3){

}

*/