#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
int main(void)
{
    srand(time(NULL));
    uint32_t valoresDado[6] = {0};
    for (uint32_t i = 0; i != 60000000; i++)
    {
        uint32_t x = 7;
        while (x > 6)
        {
            x = 1 + rand() / ((RAND_MAX + 1u) / 6);
            // printf("%d ", x);
            valoresDado[x - 1]++;
        }
    }
    for (uint32_t i = 0; i < 6; i++)
    {
        printf("%d ", valoresDado[i]);
    }
}
