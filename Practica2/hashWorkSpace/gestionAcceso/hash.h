/**
 * @file hash.h
 * @brief Cabecera para operaciones de tabla hash de Personas.
 */

#ifndef HASH_H
#define HASH_H

#include "./persona.h"
#include <stdbool.h>

/**
 * @struct Node
 * @brief Nodo de la lista enlazada usada en cada posición del array de la tabla hash.
 */
struct Node{
    struct Persona *persona;
    struct Node *next;
};

/**
 * @struct Hash
 * @brief Estructura de la tabla hash.
 * - capacidad: número de posición del arrays.
 * - tamano: número de elementos almacenados.
 * - listaPersonas: array de listas (encadenamiento separado).
 */
struct Hash{
    unsigned capacidad;
    unsigned tamano;
    struct Node **listaPersonas;
};

/**
 * @brief Crea una nueva tabla hash con la capacidad indicada.
 * @param capacidad Número de posición del arrays.
 * @return Puntero a la tabla hash creada, o NULL en caso de error.
 */
struct Hash * crearHashTable(unsigned capacidad);

/**
 * @brief Calcula el índice hash para un id dado.
 * @param id Identificador entero sin signo.
 * @param capacidad Capacidad de la tabla (número de posición del arrays).
 * @return Índice hash en [0, capacidad).
 */
unsigned hashFunc(unsigned id, unsigned capacidad);

/**
 * @brief Inserta una Persona en la tabla hash, nos pasan ya la persona creada con memoria dinámica, no es necesario copiar. Si tienen el mismo ID, no se inserta y se devuelve false.
 * @param hash Puntero a la tabla hash.
 * @param persona Puntero a Persona a insertar.
 * @return true si se insertó correctamente; false en caso de error (tabla no inicializada o persona NULL).
 */

bool insertar(struct Hash *hash, struct Persona *persona);

/**
 * @brief Busca una Persona por id.
 * @param hash Puntero a la tabla hash.
 * @param id Identificador a buscar.
 * @return Puntero a Persona si se encuentra; NULL en caso contrario.
 */
const struct Persona * buscar(struct Hash *hash, unsigned id);

/**
 * @brief Elimina la Persona con el id indicado (si existe).
 * @param hash Puntero a la tabla hash.
 * @param id Identificador a eliminar.
 * @return true si se eliminó; false si no se encontró (o error).
 */
bool eliminar(struct Hash *hash, unsigned id);

/**
 * @brief Muestra el contenido de la tabla hash.
 * @param hash Puntero constante a la tabla hash (no se modifica).
 */
void mostrar(const struct Hash *hash);

/**
 * @brief Libera toda la memoria de la tabla hash (nodos, array y estructura hash) y pone el puntero a NULL.
 * @param hash Doble puntero a la tabla hash.
 */
void liberarHash(struct Hash **hash);

#endif // HASH_H
