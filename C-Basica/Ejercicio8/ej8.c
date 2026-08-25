#include <stdio.h>
#include <stdint.h>
int main()
{
    uint8_t i = 0;
    uint16_t j = 0;
    uint8_t op1 = i++; // a + (b*c) / d -> a + ((b*c)/d)
    uint8_t op2 = ++j; // 2

    printf("op1 = %d\n", op1);
    printf("i = %d\n", i);
    printf("op2 = %d\n", op2);
    printf("j = %d\n", j);

    return 0;
}
