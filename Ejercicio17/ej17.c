#include <stdio.h>
#define FELIZ 0
#define TRISTE 1

int estado = TRISTE;
void ser_feliz();
void print_estado();

int main(void)
{
    ser_feliz(estado);
    print_estado(estado);
}

void ser_feliz()
{
    estado = FELIZ;
}

void print_estado()
{
    printf("Estoy %s\n", estado == FELIZ ? "feliz" : "triste");
}
