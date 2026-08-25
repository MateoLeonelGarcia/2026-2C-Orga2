#include <stdio.h>
#include <stdint.h>
int main()
{
    uint8_t a = 5;
    uint8_t b = 3;
    uint8_t c = 2;
    uint8_t d = 1;

    uint8_t op1 = a + b * c / d; // a + (b*c) / d -> a + ((b*c)/d)
    uint8_t op2 = a % b;         // 2
    uint8_t op3 = a == b;        // 0
    uint8_t op4 = a != b;        // 1 o basura
    uint8_t op5 = a & b;         // 1
    uint8_t op6 = a | b;         // 7
    uint8_t op7 = ~a;            // 2 en realidad 250 pues a = 0000 0101 entonces ~a = 1111 1010
    uint8_t op8 = a && b;        // true
    uint8_t op9 = a || b;        // true
    uint8_t op10 = a << 1;       // 0000 1010 = 10
    uint8_t op11 = a >> 1;       // 0000 0010 = 2
    uint8_t op12 = a += b;       // 8
    uint8_t op13 = a -= b;       // 2
    uint8_t op14 = a *= b;       // 15
    uint8_t op15 = a /= b;       //
    float op16 = a %= b;         // 2.0

    printf("op1 = %d\n", op1);
    printf("op2 = %d\n", op2);
    printf("op3 = %d\n", op3);
    printf("op4 = %d\n", op4);
    printf("op5 = %d\n", op5);
    printf("op6 = %d\n", op6);
    printf("op7 = %d\n", op7);

    printf("op8 = %d\n", op8);
    printf("op9 = %d\n", op9);
    printf("op10 = %d\n", op10);
    printf("op11 = %d\n", op11);
    printf("op12 = %d\n", op12);
    printf("op13 = %d\n", op13);
    printf("op14 = %d\n", op14);
    printf("a = %d \n", a);

    printf("b = %d \n", b);

    printf("res = %d \n", a / b);
    printf("op15 = %d\n", op15);
    printf("op16 = %f\n", op16);

    return 0;
}
