#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colaCircular.h"
#include <string.h>

struct Person *createPerson(char *name, int age)
{
  struct Person *nuevaPersona = (struct Person *)malloc(sizeof(struct Person));
  if (nuevaPersona != NULL)
  {
    nuevaPersona->age = age;
    strcpy(nuevaPersona->name, name);
  }

  return nuevaPersona;
}
void createQueue(struct Node **ptrqueue)
{
  *ptrqueue = NULL;
}
bool isEmpty(struct Node *queue)
{
  return (queue == NULL) ? true : false;
}
int size(struct Node *queue)
{
  int tam = 0;
  if (queue != NULL)
  {
    struct Node *ultimo = queue;
    do
    {
      tam++;
      queue = queue->next;
    } while (queue != ultimo);
  }
  return tam;
}
void enqueue(struct Node **ptrqueue, struct Person *person)
{
  struct Node *nuevoNodo = malloc(sizeof(struct Node));
  if (nuevoNodo == NULL)
  {
    printf("No se pudo crear un nuevo nodo\n");
    exit(-1);
  }
  nuevoNodo->person = person;
  if (*ptrqueue == NULL)
  {
    *ptrqueue = nuevoNodo;
    nuevoNodo->next = *ptrqueue;
  }
  else
  {
    struct Node *ultimo = *ptrqueue;
    *ptrqueue = nuevoNodo;
    nuevoNodo->next = ultimo->next;
    ultimo->next = nuevoNodo;
  }
}
void dequeue(struct Node **ptrqueue)
{
  struct Node *ultimo = *ptrqueue;
  struct Node *primero = ultimo->next;
  if (*ptrqueue == NULL)
  {
    printf("La cola esta vacia no puedes desencolar\n");
    exit(-1);
  }
  else if (ultimo == primero)
  {
    free(*ptrqueue);
    *ptrqueue = NULL;
  }
  else
  {
    ultimo->next = primero->next;
    free(primero);
    primero = NULL;
  }
}

// Si no asignas persona a NULL da un segmentation fault
struct Person *first(struct Node *queue)
{
  struct Person *primera = NULL;
  if (queue != NULL)
  {
    primera = queue->next->person;
  }
  return primera;
}
void clear(struct Node **ptrqueue)
{
  struct Node *act = *ptrqueue;
  struct Node *siguiente = act->next;
  if (*ptrqueue != NULL)
  {
    do
    {
      act = siguiente;
      siguiente = siguiente->next;
      free(act);
    } while (siguiente != *ptrqueue);
    free(*ptrqueue);
    *ptrqueue = NULL;
  }
  else
  {
    printf("La lista no existe\n");
  }
}
void display(struct Node *queue)
{
  struct Node *primero = queue->next;
  queue = queue->next;
  do
  {
    printf("%s -> %d\n", queue->person->name, queue->person->age);
    queue = queue->next;
  } while (queue != primero);
}