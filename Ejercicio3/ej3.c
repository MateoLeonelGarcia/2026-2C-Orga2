#include <stdio.h>

int main()
{
    char c = -128;
    unsigned char2 = -100;
    short s = -8712;
    unsigned short2 = 14;
    int i = -25;
    unsigned ui = 16516;
    long l = 123456789;
    unsigned long ul = 651656565;

    printf("char(%lu): %d \n", sizeof(c), c);
    printf("unsigned char(%lu): %d \n", sizeof(char2), char2);
    printf("short(%lu): %d \n", sizeof(s), s);
    printf("unsigned short(%lu): %d \n", sizeof(short2), short2);
    printf("int(%lu): %d \n", sizeof(i), i);
    printf("unsigned int(%lu): %d \n", sizeof(ui), ui);
    printf("long(%lu): %lu \n", sizeof(l), l);
    printf("unsigned long(%lu): %lu \n", sizeof(ul), ul);
    return 0;
}