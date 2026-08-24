#include <stdio.h>
#include <stdint.h>

int factorial(int n);

int main(void)
{
    int n;
    printf("Ingrese un numero: \n");
    scanf("%d", &n);
    printf("El factorial es: %i \n", factorial(n));
}

int factorial(int n)
{
    int res = n;
    n--;
    while (n > 0)
    {
        res = res * n;
        n--;
    }

    return res;
}
