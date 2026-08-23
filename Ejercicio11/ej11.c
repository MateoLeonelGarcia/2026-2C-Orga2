#include <stdio.h>
#include <stdint.h>
int main()
{
    uint8_t a[4] = {1, 2, 3, 4};
    uint8_t first = a[0];
    for (uint8_t i = 0; i < 3; i++)
    {
        a[i] = a[i + 1];
    }
    a[3] = first;
    for (uint8_t i = 0; i < 4; i++)
    {

        printf("%d\n", a[i]);
    }

    return 0;
}
