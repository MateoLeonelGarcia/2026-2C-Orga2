#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t i8 = 16;
    uint8_t ui8 = 198;
    int16_t i16 = 16516;
    uint16_t ui16 = 5984;
    int32_t i32 = 65654654;
    uint32_t ui32 = 69498498;
    int64_t i64 = 516165619;
    uint64_t ui64 = 123125124123;

    printf("int8(%lu): %d \n", sizeof(i8), i8);
    printf("uint8(%lu): %d \n", sizeof(ui8), ui8);
    printf("int16(%lu): %d \n", sizeof(i16), i16);
    printf("uint16(%lu): %d \n", sizeof(ui16), ui16);
    printf("int32(%lu): %d \n", sizeof(i32), i32);
    printf("uint32(%lu): %d \n", sizeof(ui32), ui32);
    printf("int64(%lu): %lu \n", sizeof(i64), i64);
    printf("uint64(%lu): %lu \n", sizeof(ui64), ui64);
    return 0;
}