// #include <stdio.h>
// #include "list.h"
// int main()
// {
//     list_t *l = listNew(TypeFAT32);
//     fat32_t *f1 = new_fat32();
//     fat32_t *f2 = new_fat32();
//     listAddFirst(l, f1);
//     listAddFirst(l, f2);
//     // Imprimimos el contenido para verificar el correcto funcionamiento
//     printf("Elemento 0: %u\n", *(fat32_t *)listGet(l, 0));
//     printf("Elemento 1: %u\n", *(fat32_t *)listGet(l, 1));
//     listDelete(l);
//     rm_fat32(f1);
//     rm_fat32(f2);
//     return 0;
// }
#include <stdio.h>
#include "list.h"

// Función auxiliar para imprimir la lista y verificar el orden
void printList(list_t *l)
{
    node_t *curr = l->first;
    printf("[ ");
    while (curr)
    {
        printf("%u ", *(fat32_t *)(curr->data));
        curr = curr->next;
    }
    printf("]\n");
}

int main()
{
    printf("=== TEST DE FUNCIONALIDAD LISTA Y SWAP ===\n\n");

    list_t *l = listNew(TypeFAT32);

    // Creamos y agregamos 5 elementos con valores 10, 20, 30, 40, 50
    // Como listAddFirst inserta al principio, insertamos en orden inverso
    for (int v = 50; v >= 10; v -= 10)
    {
        fat32_t *f = new_fat32();
        *f = v;
        listAddFirst(l, f);
        rm_fat32(f); // listAddFirst hace copia interna, liberamos la variable temporal
    }

    printf("Estado Inicial de la Lista:\n");
    printList(l); // Esperado: [ 10 20 30 40 50 ]
    printf("\n");

    // -------------------------------------------------------------
    // TEST 1: Swap no adyacente en el medio (índices 1 y 3)
    // -------------------------------------------------------------
    printf("Test 1: Swap(1, 3) - Intercambia 20 y 40\n");
    swap(l, 1, 3);
    printList(l); // Esperado: [ 10 40 30 20 50 ]
    printf("\n");

    // -------------------------------------------------------------
    // TEST 2: Swap involucrando la Cabeza/Inicio (índices 0 y 4)
    // -------------------------------------------------------------
    printf("Test 2: Swap(0, 4) - Intercambia 10 y 50\n");
    swap(l, 0, 4);
    printList(l); // Esperado: [ 50 40 30 20 10 ]
    printf("\n");

    // -------------------------------------------------------------
    // TEST 3: Swap de elementos adyacentes (índices 1 y 2)
    // -------------------------------------------------------------
    printf("Test 3: Swap(1, 2) - Intercambia 40 y 30 (adyacentes)\n");
    swap(l, 1, 2);
    printList(l); // Esperado: [ 50 30 40 20 10 ]
    printf("\n");

    // -------------------------------------------------------------
    // TEST 4: Swap de adyacentes en la cabeza (índices 0 y 1)
    // -------------------------------------------------------------
    printf("Test 4: Swap(0, 1) - Intercambia 50 y 30 (adyacentes al inicio)\n");
    swap(l, 0, 1);
    printList(l); // Esperado: [ 30 50 40 20 10 ]
    printf("\n");

    // -------------------------------------------------------------
    // TEST 5: Casos borde (mismo índice / fuera de rango)
    // -------------------------------------------------------------
    printf("Test 5: Casos Borde (no deben modificar la lista)\n");
    swap(l, 2, 2);  // Mismo índice
    swap(l, 0, 10); // Índice fuera de límite
    printList(l);   // Esperado: [ 30 50 40 20 10 ]
    printf("\n");

    // Liberación de memoria
    listDelete(l);
    printf("Memoria liberada correctamente.\n");

    return 0;
}