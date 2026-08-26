#include <stdio.h>
#include <stdint.h>
#include <string.h>

void pasarAMayus(char str[])
{
    size_t n = strlen(str);
    size_t i = 0;
    while (i < n)
    {
        if (*(str + i) >= 'a' && *(str + i) <= 'z')
        {
            *(str + i) -= 32;
        }
        i++;
    }
}

void printearString(char *str)
{
    size_t n = strlen(str);
    for (size_t i = 0; i < n; i++)
    {
        printf("%c", *(str + i));
    }
    printf("\n");
}

int main()
{
    char str[] = "hola";
    pasarAMayus(str);
    printearString(str);
    return 0;
}
