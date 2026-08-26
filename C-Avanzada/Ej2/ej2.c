#include <stdio.h>
#include <stdint.h>

typedef struct
{
    char *nombre;
    uint8_t vida;
    double ataque;
    double defensa;

} moustro_t;

moustro_t evolution(moustro_t monster)
{
    moustro_t evolved = {monster.nombre, monster.vida, monster.ataque + 10, monster.defensa + 10};
    return evolved;
}

int main()
{
    moustro_t moustritos[3] = {[0] = {"Galgo", 15, 25, 25}, [1] = {"Killa", 15, 25, 26}, [2] = {"Tutu", 100, 2, 34}};
    for (size_t i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n", moustritos[i].nombre);
        printf("Vida: %d\n", moustritos[i].vida);
        printf("Ataque: %f\n", moustritos[i].ataque);
        printf("Defensa: %f\n", moustritos[i].defensa);
    }
    for (size_t i = 0; i < 3; i++)
    {
        moustro_t evolved = evolution(moustritos[i]);
        printf("Nombre: %s\n", evolved.nombre);
        printf("Vida: %d\n", evolved.vida);
        printf("Ataque: %f\n", evolved.ataque);
        printf("Defensa: %f\n", evolved.defensa);
    }
    for (size_t i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n", moustritos[i].nombre);
        printf("Vida: %d\n", moustritos[i].vida);
        printf("Ataque: %f\n", moustritos[i].ataque);
        printf("Defensa: %f\n", moustritos[i].defensa);
    }

    return 0;
}
