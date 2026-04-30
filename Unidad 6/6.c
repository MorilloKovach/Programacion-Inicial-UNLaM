/*
. Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número
(entero, mayor a cero) que lo identifica. El ingreso finaliza con un número de participante
negativo.
 Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.
• No considerar disparos sobre los ejes, pero sí en el centro (si es sobre los ejes
las coordenadas deberán volver a ingresarse).
• Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos
coordenadas y retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un
tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que
representan la cantidad disparos en cada cuadrante y en el centro. La función debe retornar
el puntaje obtenido según la siguiente escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
*/

#include<stdio.h>
int valor_tiro(int x, int y);
int LeerDatos(int tiro);
int PUNTAJE(int cuad1, int cuad2, int cuad3, int cuad4, int centro);
int main(){
    int participante, cuadranteOCentro;
    int cuad1=0,cuad2=0,cuad3=0,cuad4=0,centro=0, centros=0;
    int mayorPuntaje = 0, puntaje_parc = 0;
    int id=0;
    printf("\nIngrese el numero de un participante: ");
    scanf("%d",&participante);
    while(participante >= 0){
        cuad1=cuad2=cuad3=cuad4=centro=0;
        for(int i = 1; i<=5; i++){
            cuadranteOCentro = LeerDatos(i);
            switch(cuadranteOCentro){
                case 1:
                    cuad1++;
                    break;
                case 2:
                    cuad2++;
                    break;
                case 3:
                    cuad3++;
                    break;
                case 4:
                    cuad4++;
                    break;
                default:
                    centro++;
                    centros++;
            }
        }
        puntaje_parc = PUNTAJE(cuad1,cuad2,cuad3,cuad4,centro);
        if(mayorPuntaje < puntaje_parc){
            mayorPuntaje = puntaje_parc;
            id = participante;
        }
        printf("\nEl puntaje del participante %d fue %d puntos",participante, PUNTAJE(cuad1,cuad2,cuad3,cuad4,centro));
        printf("\nIngrese otro participante: ");
        scanf("%d",&participante);
    }
    printf("\nEl ganador fue %d y su puntaje fue %d",id,mayorPuntaje);
    printf("\nLa cantidad de tiros en el centro fue: %d",centros);
}
int valor_tiro(int x, int y){
    if((x==0 && y != 0) || (x != 0 && y == 0)) return -1;
    if(x==0 && y==0) return 5;
    if(y>0 && x > 0) return 1;
    else if(y > 0) return 2;
    else if(y < 0 && x < 0) return 3;
    else return 4;
}

int LeerDatos(int tiro){
    int x,y, valorTiro;
    printf("\nIngrese el tiro %d: ",tiro);
    scanf("%d%d",&x,&y);
    valorTiro = valor_tiro(x,y);
    while(valorTiro == -1){
        printf("\nIngrese un tiro valido: ");
        scanf("%d%d",&x,&y);
        valorTiro = valor_tiro(x,y);
    }
    return valorTiro;
}

int PUNTAJE(int cuad1, int cuad2, int cuad3, int cuad4, int centro){
    return cuad1 * 50 + cuad2 * 50 + cuad3 * 40 + cuad4 * 40 + centro * 100;
}