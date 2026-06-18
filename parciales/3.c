/*
Un canal de streaming proyectará durante doce semanas las películas más significativas “del
siglo XX” que sus suscriptores voten on line, para lo cual se suministra un listado con los
siguientes datos de las 100 películas clásicas que dispone, según el siguiente diseño:
• Código de la película (entero, mayor a cero)
• Año de estreno (entero, de 1901 a 2000)
A continuación, se registra cada voto por película y semana obteniéndose un segundo lote de
datos, que no se encuentra ordenado. Los datos de cada uno de los votos son:
• Código de película
• Número de semana (entero, de 1 a 12)
Si el código ingresado no pertenece a una de las películas ofrecidas, no contabilizar ese voto
e informar la leyenda “CÓDIGO ERRÓNEO”, junto con el código ingresado. El fin de la
información se realiza con un número de semana igual a cero.
Confeccionar un programa para determinar e informar con los títulos correspondientes:
a) Un listado con las películas y el total de votos por semana, con el siguiente diseño:
Código de la película semana 1 semana 2 semana 3 .... semana 12
b) Una lista con los códigos de las películas que no han tenido ningún voto en las doce
semanas.
c) Código de las películas más votadas en cada semana, informando código, cantidad
de votos y año de estreno (puede haber más de una).
*/

#include <stdio.h>

void IngrDatosCompleto(int[], int[], int);
void IngrDatosVotos(int[][12], int[], int);
int EstaEnRango(int, int, int);
int ExistePelicula(int[], int, int);
void ListarPeliculas(int[][12], int[], int, int);
void ListarPeliculasSinVotos(int[][12], int[], int, int);
void ListarPeliculasMasVotadas(int[][12], int[], int[], int, int);

int main()
{
    int cantidad = 10, semanas = 12;
    int Codigos[10], AnioEstreno[10];
    int Votados[10][12];
    int i, j;
    for (i = 0; i < cantidad; i++)
    {
        Codigos[i] = AnioEstreno[i] = 0;
        for (j = 0; j < semanas; j++)
        {
            Votados[i][j] = 0;
        }
    }
    IngrDatosCompleto(Codigos, AnioEstreno, cantidad);
    IngrDatosVotos(Votados, Codigos, cantidad);
    ListarPeliculas(Votados, Codigos, cantidad, semanas);
    ListarPeliculasSinVotos(Votados, Codigos, cantidad, semanas);
    ListarPeliculasMasVotadas(Votados, Codigos, AnioEstreno, cantidad, semanas);
    return 0;
}

int EstaEnRango(int linf, int lsup, int num)
{
    int band = 0;
    if (linf <= num && num <= lsup)
    {
        band = 1;
    }
    return band;
}

void IngrDatosCompleto(int Codigos[], int AnioEstreno[], int cantidad)
{
    int i;
    for (i = 0; i < cantidad; i++)
    {
        do
        {
            printf("\nIngrese el codigo de la pelicula (mayor a 0) %d: ", i + 1);
            scanf("%d", &Codigos[i]);
        } while (Codigos[i] <= 0);
        do
        {
            printf("\nIngrese el anio de estreno de la pelicula (1901-2000): ");
            scanf("%d", &AnioEstreno[i]);
        } while (!EstaEnRango(1901, 2000, AnioEstreno[i]));
    }
}

int ExistePelicula(int Codigos[], int cantidad, int codigo)
{
    int i = 0, pos = -1;
    while (i < cantidad && pos == -1)
    {
        if (Codigos[i] == codigo)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

void IngrDatosVotos(int Votados[][12], int Codigos[], int cantidad)
{
    int codigo, num_sem, pos;
    do
    {
        printf("\nIngrese el codigo: ");
        scanf("%d", &codigo);
        pos = ExistePelicula(Codigos, cantidad, codigo);
        do
        {
            printf("\nIngrese el numero de la semana: ");
            scanf("%d", &num_sem);
        } while (!EstaEnRango(0, 12, num_sem));
        if (num_sem != 0){
            if(pos == -1){
                printf("\nCODIGO ERRONEO %d.",codigo);
            }
            else{
                Votados[pos][num_sem-1]++;
            }
        }
    } while (num_sem != 0);
}

void ListarPeliculas(int Votados[][12], int Codigos[], int cantidad, int semanas)
{
    int i, j;
    printf("Codigo de la pelicula ");
    for (i = 0; i < semanas; i++)
    {
        printf("Semana %d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < cantidad; i++)
    {
        printf("%d ", Codigos[i]);
        for (j = 0; j < semanas; j++)
        {
            printf("%d ", Votados[i][j]);
        }
        printf("\n");
    }
}

void ListarPeliculasSinVotos(int Votados[][12], int Codigos[], int cantidad, int semanas)
{
    int i, j, VotosPorPelicula[cantidad];
    for (i = 0; i < cantidad; i++)
    {
        VotosPorPelicula[i] = 0;
    }
    for (i = 0; i < cantidad; i++)
    {
        for (j = 0; j < semanas; j++)
        {
            VotosPorPelicula[i] += Votados[i][j];
        }
        if (VotosPorPelicula[i] == 0)
        {
            printf("\nLa pelicula %d no ha tenido ningun voto.", Codigos[i]);
        }
    }
}

void ListarPeliculasMasVotadas(int Votados[][12], int Codigos[], int AnioEstreno[], int cantidad, int semanas)
{
    int i, j, max;
    for (i = 0; i < semanas; i++)
    {
        max = 0;
        for (j = 0; j < cantidad; j++)
        {
            if (Votados[j][i] > max)
            {
                max = Votados[j][i];
            }
        }
        printf("\nCodigos, Cantidad de Votos y Anio de estreno de las peliculas mas votadas en la semana %d: ", i + 1);
        for (j = 0; j < cantidad; j++)
        {
            if (Votados[j][i] == max)
            {
                printf("\n%d\t%d\t%d", Codigos[j], Votados[j][i], AnioEstreno[j]);
            }
        }
    }
}