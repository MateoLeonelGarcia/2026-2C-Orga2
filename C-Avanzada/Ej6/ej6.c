#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t memoria[2] = {1, 2};
    uint8_t *x = (uint8_t *)&memoria[0];
    int8_t *y = (int8_t *)&memoria[1];

    printf("Direccion de x: %p Valor: %d\n", (void *)x, *x);
    printf("Direccion de y: %p Valor: %d\n", (void *)y, *y);
    return 0;
}
