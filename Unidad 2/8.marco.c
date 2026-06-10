/*
    Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%.
Confeccionar un programa que recibiendo el precio original y un código que indica si es o no
con descuento (0 no aplica el descuento y 1 aplica el descuento). Informe con leyenda
aclaratoria el precio final
*/

# include "stdio.h"

int main() {
    int isDiscount = 0;
    float price;
    
    printf("Por favor ingrese el precio del artículo \n");
    scanf("%f",&price);
    
    printf("Por favor ingrese si es con descuendo (0 sin descuento 1 con descuento) \n");
    scanf("%d",&isDiscount);

    if (isDiscount == 1) {
        price = price - price/20;
    } else if (isDiscount != 0){
        printf("Value not valid \n");
    }

    printf("Final price is %.2f\n", price);
}
