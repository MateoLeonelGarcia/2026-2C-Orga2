#include <stdio.h>
#include <stdint.h>
int main()
{
    uint32_t palabra1 = 0xF3A50000;
    uint32_t palabra2 = 0x0000000F;
    uint32_t mask1 = 0xE0000000;
    uint32_t mask2 = 0x00000007;
    palabra1 &= mask1; // 1110 0000 0000 0000 0000 0000 0000 0000
    printf("palabra1 enmascarada = %x\n", palabra1);
    palabra1 = palabra1 >> 29; // 0011 1000
    printf("palabra1 shofteada = %x\n", palabra1);
    palabra2 &= mask2;

    if (palabra1 == palabra2)
    {
        printf("Son iguales!\n");
    }
    else
    {
        printf("Son distintos =(\n");
    }
    return 0;
}
