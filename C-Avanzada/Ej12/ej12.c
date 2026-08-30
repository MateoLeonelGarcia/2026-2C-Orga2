#include <stdio.h>
#include <string.h>
#include <stdint.h>
typedef struct
{
    char *nombre;
    uint8_t edad;

} persona_t;

persona_t *crearPersona(char nombre[], uint8_t edad)
{
    persona_t *persona1 = malloc(sizeof(persona_t));
    if (persona1 == NULL)
    {
        return NULL;
    }
    persona1->nombre = nombre;
    persona1->edad = edad;
    return persona1;
};

int main()
{
    persona_t *p1 = crearPersona("Mateo", 29);
    if (p1 == NULL)
    {
        return 1;
    }

    return 0;
}
