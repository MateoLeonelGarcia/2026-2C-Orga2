#include "Memoria.h"

/* Pueden programar alguna rutina auxiliar acá */

// Compara dos strings en orden lexicográfico. Ver https://es.wikipedia.org/wiki/Orden_lexicografico.
// Debe retornar:
// 0 si son iguales
// 1 si a < b
//-1 si a > b
// int32_t strCmp(char *a, char *b)
// {
//     while (*a != '\0' && *a == *b)
//     {
//         a++;
//         b++;
//     }

//     unsigned char ca = (unsigned char)*a;
//     unsigned char cb = (unsigned char)*b;

//     if (ca == cb)
//         return 0;
//     if (ca < cb)
//         return 1;
//     return -1;
//}

// // Retorna la cantidad de caracteres distintos de cero del \emph{string} pasado por parámetro.
// uint32_t strLen(char *a)
// {
//     uint32_t len = 0;
//     while (*a != '\0')
//     {
//         len++;
//     }
//     return len;
// }

// Genera una copia del string pasado por parámetro. El puntero pasado siempre es válido
// aunque podría corresponderse a la cadena vacía.
// char *strClone(char *a)
// {
//     uint32_t strlen = strLen(a);
//     char *clone = malloc((strlen + 1)* sizeof(char));
//     char *dst = clone;
//     for (size_t i = 0; i <= strlen; i++)
//     {
//         *dst = *a;
//         dst++;
//         a++;
//     }

//     return clone;
// }
