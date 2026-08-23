#include <stdio.h>
#include <stdint.h>
#define N 4
int main()
{
    uint8_t a[N] = {1, 2, 3, 4};
    uint8_t rotacion = 3;
    uint8_t aCopia[N] = {1, 2, 3, 4};
    // for (uint8_t i = 0; i < N; i++)
    // {
    //     aCopia[i] = a[i];
    // }

    for (uint8_t i = 0; i < N; i++)
    {
        uint8_t indice = 0;
        if (i < rotacion)
        {
            indice = N + i - rotacion;
        }
        else
        {
            indice = i - rotacion;
        }

        printf("indice = %d\n", indice);
        a[indice] = aCopia[i];
    }

    for (uint8_t i = 0; i < N; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
