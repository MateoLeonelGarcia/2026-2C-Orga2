#include <stdio.h>
#include <stdint.h>

uint8_t global = 10;
int main(void)
{
    uint16_t global = 25;

    // printf("%i\n ", local);
    printf("%i\n", global);
}
