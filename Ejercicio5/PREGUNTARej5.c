#include <stdio.h>
#include <stdint.h>

int main()
{
    float f = 0.1;
    double d = 0.1;

    printf("float: %f\n", f);
    printf("double: %f \n", d);

    int fint = (int)f;
    int dint = (int)d;

    printf("floatCasteado: %d\n", fint);
    printf("doubleCasteado: %d \n", dint);

    return 0;
}