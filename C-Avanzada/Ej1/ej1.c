#include <stdio.h>
#include <stdint.h>

typedef struct
{
    char *nombre;
    uint8_t vida;
    double ataque;
    double defensa;

} moustro_t;
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

    return 0;
}
