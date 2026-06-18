#include <stdio.h>

void ordenar(int[]);

int main()
{
    int v[] = {9, 1, 2, 7, 3, 4, 5, 10, 3, 2, 5, 8, 1};
    int i;
    ordenar(v);
    for (i = 0; i < 13; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ordenar(int vector[])
{
    int i, j, aux, indiceMinimo;
    for (i = 0; i < 13; i++)
    {
        indiceMinimo = i;
        for (j = i + 1; j < 13; j++)
        {
            if (vector[j] < vector[indiceMinimo])
            {
                indiceMinimo = j;
            }
        }
        if (indiceMinimo != i)
        {
            aux = vector[i];
            vector[i] = vector[indiceMinimo];
            vector[indiceMinimo] = aux;
        }
    }
}