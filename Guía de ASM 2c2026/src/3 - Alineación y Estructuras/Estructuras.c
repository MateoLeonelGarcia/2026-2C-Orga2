#include "Estructuras.h"

/* Pueden programar alguna rutina auxiliar acá */
// static uint32_t x[4];
// static double f[4];

// void shuffle(uint32_t max)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         x[i] = (uint32_t)rand() % max;
//         f[i] = ((float)rand() / (float)(RAND_MAX)) * max;
//     }
// }
// int main()
// {
//     nodo_t *array[4];
//     lista_t lista;
//     for (int i = 0; i < 100; i++)
//     {
//         shuffle(1000);

//         for (int j = 0; j < 4; j++)
//         {
//             array[j] = calloc(1, sizeof(nodo_t));
//             array[j]->longitud = x[j];
//         }

//         for (int j = 0; j < 4 - 1; j++)
//         {
//             array[j]->next = array[j + 1];
//         }

//         lista_t lista;
//         lista.head = array[0];
//     }

//     int i = 0;
//     nodo_t *nodotmp = lista.head;
//     while (nodotmp != NULL)
//     {
//         i++;
//         nodotmp = nodotmp->next;
//     }
//     return i;
// }