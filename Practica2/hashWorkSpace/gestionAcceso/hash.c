#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @struct Node
 * @brief Nodo de la lista enlazada usada en cada posición del array de la tabla hash.
 */

/*
struct Node{
    struct Persona *persona;
    struct Node *next;
};
*/

/**
 * @struct Hash
 * @brief Estructura de la tabla hash.
 * - capacidad: número de posición del arrays.
 * - tamano: número de elementos almacenados.
 * - listaPersonas: array de listas (encadenamiento separado).
 */

/*
struct Hash
{
 unsigned capacidad;
 unsigned tamano;
 struct Node **listaPersonas;
};
*/

/**
 * @brief Crea una nueva tabla hash con la capacidad indicada.
 * @param capacidad Número de posición del arrays.
 * @return Puntero a la tabla hash creada, o NULL en caso de error.
 */
struct Hash *crearHashTable(unsigned capacidad)
{
  struct Hash *nuevoHash = (struct Hash *)malloc(sizeof(struct Hash));
  if (nuevoHash == NULL)
  {
    perror("No hay suficiente espacio.\n");
    exit(-1);
  }

  nuevoHash->capacidad = capacidad;
  nuevoHash->listaPersonas = (struct Node **)calloc(capacidad, sizeof(struct Node *));
  nuevoHash->tamano = 0;

  if (nuevoHash->listaPersonas == NULL)
  {
    printf("NO HAY MEMORIA PARA LISTAS.\n");
    free(nuevoHash);
    exit(-1);
  }

  return nuevoHash;
}

/**
 * @brief Calcula el índice hash para un id dado.
 * @param id Identificador entero sin signo.
 * @param capacidad Capacidad de la tabla (número de posición del arrays).
 * @return Índice hash en [0, capacidad).
 */
unsigned hashFunc(unsigned id, unsigned capacidad)
{
  return id % capacidad;
}

/**
 * @brief Inserta una Persona en la tabla hash, nos pasan ya la persona creada con memoria dinámica, no es necesario copiar. Si tienen el mismo ID, no se inserta y se devuelve false.
 * @param hash Puntero a la tabla hash.
 * @param persona Puntero a Persona a insertar.
 * @return true si se insertó correctamente; false en caso de error (tabla no inicializada o persona NULL).
 */

bool insertar(struct Hash *hash, struct Persona *persona)
{
  if (hash == NULL || persona == NULL) // No existe una o la otra
  {
    exit(-1);
  }

  int i = hashFunc(persona->id, hash->capacidad);
  struct Node *iter = hash->listaPersonas[i];

  while (iter != NULL)
  {
    if (iter->persona->id == persona->id)
    {
      return false;
    }
    iter = iter->next;
  }

  struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
  if (aux == NULL)
  {
    perror("No hay memoria para el nodo.\n");
    exit(-1);
  }

  aux->persona = persona;
  aux->next = NULL;

  if (hash->listaPersonas[i] == NULL)
  {
    hash->listaPersonas[i] = aux;
  }
  else
  {
    struct Node *nodo = hash->listaPersonas[i];
    while (nodo->next != NULL)
    {

      nodo = nodo->next;
    }

    nodo->next = aux;
  }
  hash->tamano++;
  return true;
}

/**
 * @brief Busca una Persona por id.
 * @param hash Puntero a la tabla hash.
 * @param id Identificador a buscar.
 * @return Puntero a Persona si se encuentra; NULL en caso contrario.
 */
const struct Persona *buscar(struct Hash *hash, unsigned id)
{
  int i = hashFunc(id, hash->capacidad);
  struct Node *aux = hash->listaPersonas[i];

  while (aux != NULL)
  {
    if (aux->persona->id == id)
    {
      return aux->persona;
    }
    aux = aux->next;
  }
  return NULL;
}

/**
 * @brief Elimina la Persona con el id indicado (si existe).
 * @param hash Puntero a la tabla hash.
 * @param id Identificador a eliminar.
 * @return true si se eliminó; false si no se encontró (o error).
 */
bool eliminar(struct Hash *hash, unsigned id)
{
  if (hash == NULL)
  {
    exit(-1);
  }

  int i = hashFunc(id, hash->capacidad);
  struct Node *aux = hash->listaPersonas[i];
  struct Node *ant = NULL;

  while (aux != NULL)
  {

    if (aux->persona->id == id)
    {

      if (ant == NULL)
      { // Primero de la lista
        hash->listaPersonas[i] = aux->next;
      }
      else
      {
        ant->next = aux->next;
      }
      hash->tamano--;
      free(aux);
      return;
    }
    ant = aux;
    aux = aux->next;
  }
  printf("ID no encontrado.\n");
}

/**
 * @brief Muestra el contenido de la tabla hash.
 * @param hash Puntero constante a la tabla hash (no se modifica).
 */
void mostrar(const struct Hash *hash)
{
  printf("Tabla Hash:\n");
  for (int i = 0; i < hash->capacidad; i++)
  {
    printf("Bucket %d: \n", i);
    struct Node *aux = hash->listaPersonas[i];
    while (aux != NULL)
    {
      mostrarPersona(aux->persona);
      aux = aux->next;
    }
    printf("\n");
  }
}

/**
 * @brief Libera toda la memoria de la tabla hash (nodos, array y estructura hash) y pone el puntero a NULL.
 * @param hash Doble puntero a la tabla hash.
 */
void liberarHash(struct Hash **hash)
{
  if (hash == NULL || *hash == NULL)
  {
    exit(-1);
  }

  for (int i = 0; i < (*hash)->capacidad; i++)
  {
    struct Node *aux = (*hash)->listaPersonas[i];
    struct Node *tmp;
    while (aux != NULL)
    {
      tmp = aux;
      liberarPersona(&aux->persona); // OJO CON ESTO ALEJANDRO!!!
      aux = aux->next;
      free(tmp);
    }
  }
  free((*hash)->listaPersonas);
  free(*hash);
  *hash = NULL;
}