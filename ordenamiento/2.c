#include <stdio.h>

int main()
{
    int v[] = {1,2,3,4,5};
    int v2[] = {50,300,750,250,150};
    int i, j, aux;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n");
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (v2[j] > v2[i])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;

                aux = v2[i];
                v2[i] = v2[j];
                v2[j] = aux;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n");
}