#include "lista_enlazada_doble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SONG_LENGTH 30

/*
struct Node {
    char data[MAX_SONG_LENGTH];
    struct Node* prev;
    struct Node* next;
};

struct PlayList {
    struct Node *currentsong;
    struct Node *head;
};
*/

/**
 * @brief Initializes an empty playlist
 * @param myPlayList Pointer to the PlayList structure to be initialized
 */
void PlayList_create(struct PlayList *myPlayList)
{
  if (myPlayList == NULL)
  {
    printf("my PlayList es NULL.\n");
    exit(-1);
  }

  myPlayList->currentsong = NULL;
  myPlayList->head = NULL;
}

/**
 * @brief Creates a new node with the given value
 * @param value The string to be stored in the node
 * @return Pointer to the newly created node, or NULL if creation fails
 */
struct Node *createNode(const char *value)
{

  if (value == NULL || strlen(value) > MAX_SONG_LENGTH)
  {
    printf("value no es válido.\n");
    return NULL;
  }

  struct Node *newSong = (struct Node *)malloc(sizeof(struct Node));

  if (newSong == NULL)
  {
    printf("No se ha podido usar memoria para crear el puntero.\n");
    return NULL;
  }

  strcpy(newSong->data, value);
  newSong->next = NULL;
  newSong->prev = NULL;

  return newSong;
}

/**
 * @brief Inserts a new node at the front of the playlist
 * @param myPlayList Pointer to the PlayList structure
 * @param value The string to be inserted
 * @return 0 if successful, -1 if failed
 */
int PlayList_insertAtFront(struct PlayList *myPlayList, const char *value)
{ // COMPROBAR QUE NO SE REPITE LA CANCION

  if (myPlayList == NULL || value == NULL || strlen(value) > MAX_SONG_LENGTH)
  {
    return -1;
  }

  struct Node *iter = myPlayList->head;
  while (iter != NULL)
  {
    if (strcmp(iter->data, value) == 0)
    {
      return -1;
    }

    iter = iter->next;
  }

  struct Node *nuevoNodo = createNode(value);

  if (myPlayList->head == NULL)
  { // PlayList está vacía
    myPlayList->currentsong = nuevoNodo;

    myPlayList->head = nuevoNodo;
  }
  else
  { // REVISAR
    nuevoNodo->next = myPlayList->head;
    myPlayList->head->prev = nuevoNodo;
    myPlayList->head = nuevoNodo;
    myPlayList->currentsong = nuevoNodo;
  }

  return 0;
}

/**
 * @brief Inserts a new node in the playlist in alphabetical order
 * @param myPlayList Pointer to the PlayList structure
 * @param valor The string to be inserted
 * @return 0 if successful, -1 if failed
 */
int PlayList_insertInOrder(struct PlayList *myPlayList, const char *valor)
{ // COMPROBAR QUE NO SE REPITE LA CANCION

  if (myPlayList == NULL || valor == NULL || strlen(valor) > MAX_SONG_LENGTH)
  {
    return -1;
  }

  struct Node *iter = myPlayList->head;
  while (iter != NULL)
  {
    if (strcmp(iter->data, valor) == 0)
    {
      return -1;
    }

    iter = iter->next;
  }

  struct Node *nuevoNodo = createNode(valor);

  if (myPlayList->head == NULL)
  { // PlayList está vacía
    myPlayList->currentsong = nuevoNodo;

    myPlayList->head = nuevoNodo;
    return 0;
  }
  iter = myPlayList->head;
  struct Node *ant = NULL;

  while (iter && strcmp(iter->data, valor) < 0)
  {
    ant = iter;
    iter = iter->next;
  }

  if (!ant) // Insertar al inicio
  {
    nuevoNodo->next = myPlayList->head;
    myPlayList->head->prev = nuevoNodo;
    myPlayList->head = nuevoNodo;
  }
  else // Insertar en medio o final
  {
    nuevoNodo->prev = ant;
    nuevoNodo->next = iter;
    ant->next = nuevoNodo;
    if (iter)
      iter->prev = nuevoNodo;
  }

  myPlayList->currentsong = nuevoNodo;
  return 0;
}

/**
 * @brief Inserts a new node at the end of the playlist
 * @param myPlayList Pointer to the PlayList structure
 * @param value The string to be inserted
 * @return 0 if successful, -1 if failed
 */
int PlayList_insertAtEnd(struct PlayList *myPlayList, const char *value)
{
  if (myPlayList == NULL || value == NULL || strlen(value) > MAX_SONG_LENGTH)
  {
    return -1;
  }

  struct Node *iter = myPlayList->head;
  while (iter != NULL)
  {
    if (strcmp(iter->data, value) == 0)
    {
      return -1;
    }

    iter = iter->next;
  }

  struct Node *nuevoNodo = createNode(value);

  if (myPlayList->head == NULL)
  { // PlayList está vacía
    myPlayList->currentsong = nuevoNodo;

    myPlayList->head = nuevoNodo;
  }
  else
  { // PlayList ya tiene un head
    iter = myPlayList->head;
    while (iter->next)
      iter = iter->next;
    iter->next = nuevoNodo;
    nuevoNodo->prev = iter;
  }

  return 0;
}

/**
 * @brief Inserts a new node after a specified node in the playlist
 * @param myPlayList Pointer to the PlayList structure
 * @param cancion The string to search for in the playlist
 * @param value The string to be inserted
 * @return 0 if successful, -1 if failed
 */

int PlayList_insertAfter(struct PlayList *myPlayList, const char *cancion, const char *value)
{
  if (myPlayList == NULL || value == NULL || cancion == NULL || strlen(value) > MAX_SONG_LENGTH)
  {
    return -1;
  }

  struct Node *iter = myPlayList->head;
  while (iter != NULL)
  {
    if (strcmp(iter->data, value) == 0)
    {
      return -1;
    }

    iter = iter->next;
  }

  struct Node *nuevoNodo = createNode(value);

  iter = myPlayList->head;
  while (iter && strcmp(iter->data, cancion) != 0)
    iter = iter->next;

  if (!iter) // Canción base no encontrada
    return -1;

  nuevoNodo->next = iter->next;
  nuevoNodo->prev = iter;
  if (iter->next)
    iter->next->prev = nuevoNodo;
  iter->next = nuevoNodo;

  myPlayList->currentsong = nuevoNodo;
  return 0;
}

/**
 * @brief Inserts a new node before a specified node in the playlist
 * @param myPlayList Pointer to the PlayList structure
 * @param cancion The string to search for in the playlist
 * @param value The string to be inserted
 * @return 0 if successful, -1 if failed
 */

int PlayList_insertBefore(struct PlayList *myPlayList, const char *cancion, const char *value)
{
  if (myPlayList == NULL || value == NULL || cancion == NULL || strlen(value) > MAX_SONG_LENGTH)
  {
    return -1;
  }

  struct Node *iter = myPlayList->head;
  while (iter != NULL)
  {
    if (strcmp(iter->data, value) == 0)
    {
      return -1;
    }

    iter = iter->next;
  }

  struct Node *nuevoNodo = createNode(value);

  iter = myPlayList->head;
  while (iter && strcmp(iter->data, cancion) != 0)
    iter = iter->next;

  if (!iter) // Canción base no encontrada
    return -1;

  nuevoNodo->next = iter;
  nuevoNodo->prev = iter->prev;

  if (iter->prev)
    iter->prev->next = nuevoNodo;
  else
    myPlayList->head = nuevoNodo; // Nuevo nodo se convierte en cabeza

  iter->prev = nuevoNodo;
  myPlayList->currentsong = nuevoNodo;

  return 0;
}

/**
 * @brief Deletes the first node from the playlist
 * @param myPlayList Pointer to the PlayList structure
 */
void PlayList_deleteFromFront(struct PlayList *myPlayList)
{

  if (myPlayList == NULL || myPlayList->head == NULL)
  {
    return;
  }

  struct Node *aux = myPlayList->head;
  myPlayList->head = aux->next;

  if (myPlayList->head != NULL)
  {
    myPlayList->head->prev = NULL;
  }

  if (myPlayList->currentsong == aux)
  {
    myPlayList->currentsong = myPlayList->head;
  }

  free(aux);
}

/**
 * @brief Deletes a node with the given value from the playlist
 * @param myPlayList Pointer to the PlayList structure
 * @param value The string to be deleted
 * @return 1 if the node was found and deleted, 0 otherwise
 */
int PlayList_deleteSong(struct PlayList *myPlayList, const char *value)
{
  if (myPlayList == NULL || myPlayList->head == NULL || value == NULL)
  {
    return 0;
  }
  struct Node *iter = myPlayList->head;

  while (iter && strcmp(iter->data, value) != 0)
    iter = iter->next;

  if (!iter) // No encontrado
    return 0;

  // Reconectar nodos vecinos
  if (iter->prev)
    iter->prev->next = iter->next;
  else
    myPlayList->head = iter->next; // Eliminando la cabeza

  if (iter->next)
    iter->next->prev = iter->prev;

  if (myPlayList->currentsong == iter)
    myPlayList->currentsong = iter->next ? iter->next : iter->prev;

  free(iter);
  return 1;
}

/**
 * @brief Prints the contents of the playlist
 * @param myPlayList The PlayList structure to be printed
 */
void PlayList_print(struct PlayList myPlayList)
{
  if (myPlayList.head != NULL)
  {
    myPlayList.currentsong = myPlayList.head;
    while (myPlayList.currentsong != NULL)
    {
      printf("Canción: %s \n", myPlayList.currentsong->data);

      myPlayList.currentsong = myPlayList.currentsong->next;
    }
  }
}

/**
 * @brief Sorts the playlist in alphabetical order using bubble sort
 * @param myPlayList Pointer to the PlayList structure
 */

void PlayList_order(struct PlayList *myPlayList) // NI BORRACHO LO HAGO
{
  if (myPlayList == NULL || myPlayList->head == NULL)
  {
    return; // lista vacía
  }

  int swapped;
  struct Node *ptr;
  struct Node *last = NULL;
  char temp[MAX_SONG_LENGTH];

  do
  {
    swapped = 0;
    ptr = myPlayList->head;

    while (ptr->next != last)
    {
      if (strcmp(ptr->data, ptr->next->data) > 0)
      {
        // intercambiar strings
        strcpy(temp, ptr->data);
        strcpy(ptr->data, ptr->next->data);
        strcpy(ptr->next->data, temp);
        swapped = 1;
      }
      ptr = ptr->next;
    }
    last = ptr; // ya está ordenado el último
  } while (swapped);
}

/**
 * @brief Deletes all nodes from the playlist
 * @param myPlayList Pointer to the PlayList structure
 */

void PlayList_deleteAll(struct PlayList *myPlayList)
{
  if (!myPlayList)
    return;

  struct Node *iter = myPlayList->head;
  while (iter)
  {
    struct Node *next = iter->next;
    free(iter);
    iter = next;
  }

  myPlayList->head = NULL;
  myPlayList->currentsong = NULL;
}

/**
 * @brief Return current song
 *
 * @param myPlayList PlayList structure
 * @return * char* with de current song
 */
char *PlayList_currentSong(struct PlayList myPlayList)
{
  if (myPlayList.currentsong == NULL)
  {
    return NULL;
  }
  return myPlayList.currentsong->data;
}

/**
 * @brief Shift current song to the next. No action if last
 *
 * @param myPlayList Pointer to the PlayList structure
 */

void PlayList_forwardSong(struct PlayList *myPlayList)
{
  if (myPlayList != NULL && myPlayList->currentsong != NULL && myPlayList->currentsong->next != NULL)
  {
    myPlayList->currentsong = myPlayList->currentsong->next;
  }
}

/**
 * @brief shift current song to the previous. No action if first
 *
 * @param myPlayList Pointer to the PlayList structure
 */
void PlayList_backwardSong(struct PlayList *myPlayList)
{
  if (myPlayList != NULL && myPlayList->currentsong != NULL && myPlayList->currentsong->prev != NULL)
  {
    myPlayList->currentsong = myPlayList->currentsong->prev;
  }
}
