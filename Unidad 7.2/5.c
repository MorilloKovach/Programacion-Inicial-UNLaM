#include <stdio.h>

void IngrDatos(int[], float[]);

void IngrDatosParcial(int[], float[15][27]);

void kmRealizados(int[], float[15][27]);

void ImportePorConductor(float[15][27], float[]);

void MayoresesKilometros(int[], float[15][27]);

int ExisteCamion(int[], int);

int main()
{
    int camiones[15],i,j;
    float kilometros[15], CamiConductores[15][27];
    for(i=0;i<15;i++){
        camiones[i] = kilometros[i] = 0;
        for(j=0;j<27;j++){
            CamiConductores[i][j] = 0;
        }
    }
    IngrDatos(camiones, kilometros);
    IngrDatosParcial(camiones, CamiConductores);
    kmRealizados(camiones, CamiConductores);
    ImportePorConductor(CamiConductores, kilometros);
    MayoresesKilometros(camiones, CamiConductores);

    return 0;
}

void IngrDatos(int camiones[], float kilometros[])
{
    int cami, i = 0;
    float kilo;
    for (i; i < 15; i++)
    {
        printf("\nIngrese el codigo del camion: ");
        scanf("%d", &cami);
        while (cami < 1000 || cami > 9999 || ExisteCamion(camiones, cami) != -1)
        {
            printf("\nIngrese el codigo del camion: ");
            scanf("%d", &cami);
        }
        printf("\nIngrese el importe por km: ");
        scanf("%f", &kilo);
        while (kilo < 0)
        {
            printf("\nIngrese el importe por km: ");
            scanf("%f", &kilo);
        }
        camiones[i] = cami;
        kilometros[i] = kilo;
    }
}
int ExisteCamion(int camiones[], int codigo){
    int i = 0, posAuto = -1;
    while(i<15 && posAuto == -1){
        if(camiones[i] == codigo){
            posAuto = i;
        }
        i++;
    }
    return posAuto;
}
void IngrDatosParcial(int codigos[], float CamiConduc[15][27])
{
    int codi, codiAuto, posAuto;
    float cantKm;
    do
    {
        printf("\nIngrese el codigo del conductor: ");
        scanf("%d", &codi);
        while ((codi < 1 || codi > 27) && codi != 100)
        {
            printf("\nIngrese el codigo del conductor: ");
            scanf("%d", &codi);
        }
        if (codi != 100)
        {
            printf("\nIngrese el codigo del camion: ");
            scanf("%d", &codiAuto);
            posAuto = ExisteCamion(codigos, codiAuto);
            while (posAuto == -1)
            {
                printf("\nIngrese el codigo del camion: ");
                scanf("%d", &codiAuto);
                posAuto = ExisteCamion(codigos, codiAuto);
            }
            printf("\nIngrese la cantidad de kilometros recorridos: ");
            scanf("%f",&cantKm);
            CamiConduc[posAuto][codi-1] += cantKm;
        }
    } while (codi != 100);
}

void kmRealizados(int camiones[], float CamionesConductores[15][27]){
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<27;j++){
            printf("\nEl camion %d con el conductor %d recorrio %.2f kilometros.",camiones[i],j+1,CamionesConductores[i][j]);
        }
    }
}

void ImportePorConductor(float CamionesConductores[15][27], float ImportePorKm[]){
    float TotalConductores[27], aux;
    int i, j, conductor[27], auxConductor;
    for(i=0;i<27;i++){
        TotalConductores[i] = 0;
        conductor[i] = i + 1;
    }
    for(i=0;i<27;i++){
        for(j=0;j<15;j++){
            TotalConductores[i]+=CamionesConductores[j][i] * ImportePorKm[j];
        }
    }
    for(i=0;i<27;i++){
        for(j=i+1;j<27;j++){
            if(TotalConductores[i] < TotalConductores[j]){
                aux = TotalConductores[i];
                TotalConductores[i] = TotalConductores[j];
                TotalConductores[j] = aux;

                auxConductor = conductor[i];
                conductor[i] = conductor[j];
                conductor[j] = auxConductor;
            }
        }
    }
    printf("\nNumero del conductor\t Importe");
    for(i=0;i<27;i++){
        printf("\n%d\t%.2f",conductor[i], TotalConductores[i]);
    }
}
void MayoresesKilometros(int codigos[], float conductoresCamiones[15][27]){
    int i,j;
    float camiones[15], maximoKm=0;
    for(i=0;i<15;i++){
        camiones[i] = 0;
    }
    for(i=0;i<15;i++){
        for(j=0;j<27;j++){
            camiones[i] += conductoresCamiones[i][j];
        }
    }

    for(i=0;i<15;i++){
        if(maximoKm < camiones[i]){
            maximoKm = camiones[i];
        }
    }

    for(i=0;i<15;i++){
        if(maximoKm == camiones[i]){
            printf("\nEl camion %d recorrio %.2f kilometros, acumulando el maximo.",codigos[i], maximoKm);
        }
    }
}
