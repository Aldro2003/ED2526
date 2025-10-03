#include "gestionAcceso/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HASH_SIZE 7

static void imprimir_hash_idx(const char *etiqueta, int id, unsigned idx)
{
    printf("%s (id=%d) -> hash %u\n", etiqueta, id, idx);
}

int main(void)
{
    struct Hash *tablaHash = crearHashTable(HASH_SIZE);
    assert(tablaHash != NULL);
    assert(tablaHash->capacidad == HASH_SIZE);

    // Personas base
    struct Persona *persona1 = crearPersona(1, "John", "Doe", "jonny@uma.es");
    struct Persona *persona2 = crearPersona(2, "Jane", "Smith", "janes@uma.es");
    struct Persona *persona3 = crearPersona(3, "Alice", "Johnson", "aljoh@uma.es");
    struct Persona *persona4 = crearPersona(4, "Bob", "Brown", "boby@uma.es");
    struct Persona *persona5 = crearPersona(5, "Charlie", "Davis", "chard@uma.es");
    struct Persona *persona6 = crearPersona(6, "Diana", "Evans", "diev@uma.es");
    struct Persona *persona7 = crearPersona(7, "Frank", "Green", "frankg@uma.es");
    struct Persona *persona8 = crearPersona(8, "Henry", "Irvine", "hentyi@uma.es");

    // Claves diseñadas para colisionar con HASH_SIZE=7 (7,14,21,28 => misma posición del array)
    struct Persona *persona13 = crearPersona(13, "Nina", "Moore", "nimo@uma.es");
    struct Persona *persona14 = crearPersona(14, "Oscar", "Perez", "oscarp@uma.es");
    struct Persona *persona21 = crearPersona(21, "Grace", "Hall", "graceh@uma.es");
    struct Persona *persona28 = crearPersona(28, "Irene", "Quinn", "ireneq@uma.es");

    // Inserciones base
    imprimir_hash_idx("Hash persona 1", persona1->id, hashFunc(persona1->id, tablaHash->capacidad));
    insertar(tablaHash, persona1);
    imprimir_hash_idx("Hash persona 2", persona2->id, hashFunc(persona2->id, tablaHash->capacidad));
    insertar(tablaHash, persona2);
    imprimir_hash_idx("Hash persona 3", persona3->id, hashFunc(persona3->id, tablaHash->capacidad));
    insertar(tablaHash, persona3);
    imprimir_hash_idx("Hash persona 4", persona4->id, hashFunc(persona4->id, tablaHash->capacidad));
    insertar(tablaHash, persona4);
    imprimir_hash_idx("Hash persona 5", persona5->id, hashFunc(persona5->id, tablaHash->capacidad));
    insertar(tablaHash, persona5);
    imprimir_hash_idx("Hash persona 6", persona6->id, hashFunc(persona6->id, tablaHash->capacidad));
    insertar(tablaHash, persona6);
    imprimir_hash_idx("Hash persona 7", persona7->id, hashFunc(persona7->id, tablaHash->capacidad));
    insertar(tablaHash, persona7);
    imprimir_hash_idx("Hash persona 8", persona8->id, hashFunc(persona8->id, tablaHash->capacidad));
    insertar(tablaHash, persona8);

    puts("\n--- Estado tras inserciones base ---");
    mostrar(tablaHash);

    // Colisiones intencionadas
    imprimir_hash_idx("Hash persona 13", persona13->id, hashFunc(persona13->id, tablaHash->capacidad));
    insertar(tablaHash, persona13);
    imprimir_hash_idx("Hash persona 14", persona14->id, hashFunc(persona14->id, tablaHash->capacidad));
    insertar(tablaHash, persona14);
    imprimir_hash_idx("Hash persona 21", persona21->id, hashFunc(persona21->id, tablaHash->capacidad));
    insertar(tablaHash, persona21);
    imprimir_hash_idx("Hash persona 28", persona28->id, hashFunc(persona28->id, tablaHash->capacidad));
    insertar(tablaHash, persona28);

    puts("\n--- Estado tras insertar colisiones (7,14,21,28 comparten posición del array) ---");
    mostrar(tablaHash);

    // Búsquedas: inexistente y existentes en distintas posiciones
    const struct Persona *buscada = buscar(tablaHash, 22);
    assert(buscada == NULL);
    printf("\nBúsqueda id=22: %s\n", buscada == NULL ? "NO encontrada (OK)" : "ERROR");

    buscada = buscar(tablaHash, 7); // debería existir (en la posición del array con colisiones)
    assert(buscada != NULL && buscada->id == 7);
    printf("Búsqueda id=7: encontrada -> ");
    mostrarPersona(buscada);

    buscada = buscar(tablaHash, 21); // cadena de colisión, posición intermedia
    assert(buscada != NULL && buscada->id == 21);
    printf("Búsqueda id=21: encontrada -> ");
    mostrarPersona(buscada);

    buscada = buscar(tablaHash, 1); // elemento en otra posición del array
    assert(buscada != NULL && buscada->id == 1);
    printf("Búsqueda id=1: encontrada -> ");
    mostrarPersona(buscada);

    // Eliminaciones:
    // 1) Eliminar un elemento en medio de una lista enlazada de colisiones (p. ej., 21)
    puts("\n--- Eliminando id=21 (nodo intermedio en la lista de colisión) ---");
    eliminar(tablaHash, 21);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 21) == NULL);
    assert(buscar(tablaHash, 7) != NULL);
    assert(buscar(tablaHash, 14) != NULL);
    assert(buscar(tablaHash, 28) != NULL);

    // 2) Eliminar un elemento al principio de una lista enlazada (depende del orden de inserción)
    puts("\n--- Eliminando id=7 (posible cabeza de la lista de colisión) ---");
    eliminar(tablaHash, 7);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 7) == NULL);

    // 3) Eliminar un elemento al final de la lista de colisión (p. ej., 28)
    puts("\n--- Eliminando id=28 (posible cola de la lista de colisión) ---");
    eliminar(tablaHash, 28);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 28) == NULL);

    // 4) Eliminar un elemento que está solo en su posición del array (p. ej., 1)
    puts("\n--- Eliminando id=4 (elemento único en su posición del array) ---");
    eliminar(tablaHash, 4);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 4) == NULL);

    // 5) Eliminar un id inexistente (no debe fallar ni alterar otros)
    puts("\n--- Eliminando id=999 (no existe) ---");
    eliminar(tablaHash, 999);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 2) != NULL); // comprobación de que no se dañó la tabla

    // 6) Comprobar que otras claves siguen accesibles
    assert(buscar(tablaHash, 1) != NULL);
    assert(buscar(tablaHash, 2) != NULL);
    assert(buscar(tablaHash, 3) != NULL);
    assert(buscar(tablaHash, 5) != NULL);
    assert(buscar(tablaHash, 6) != NULL);
    assert(buscar(tablaHash, 8) != NULL);
    assert(buscar(tablaHash, 13) != NULL);
    assert(buscar(tablaHash, 14) != NULL);

    // Eliminación adicional: borrar cabeza restante de esa posición del array (14)
    puts("\n--- Eliminando id=14 (último que quedaba en la posición del array de colisión) ---");
    eliminar(tablaHash, 14);
    mostrar(tablaHash);
    assert(buscar(tablaHash, 14) == NULL);

    // Limpieza final
    puts("\n--- Liberando tabla hash completa ---");
    liberarHash(&tablaHash);
    assert(tablaHash == NULL);
    puts("Tabla hash liberada correctamente.");

    return 0;
}
