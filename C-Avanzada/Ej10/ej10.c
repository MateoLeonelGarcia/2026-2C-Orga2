#include <stdio.h>
#include <string.h>

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
    char str1[] = "hola";
    char str2[] = "como";
    // STRCPY
    strcpy(str1, str2);
    printearString(str1);
    // STRCAT
    strcat(str1, "como");
    printearString(str1);
    // STRLEN
    size_t length = strlen(str2);
    printf("length: %lu\n", length);
    // STRCMP
    int iguales = strcmp("str1", "str1");
    printf("Iguales?: %i", iguales);
    return 0;
}
