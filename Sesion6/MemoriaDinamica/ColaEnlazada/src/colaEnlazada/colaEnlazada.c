#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "colaEnlazada.h"

struct Person *createPerson(char *name, int age)
{
  struct Person *persona = malloc(sizeof(struct Person));

  if (persona == NULL)
  {
    printf("No se pudo asignar memoria\n");
    exit(-1);
  }
  persona->age = age;
  strcpy(persona->name, name);

  return persona;
}
void createQueue(struct Node **ptrqueue)
{
  *ptrqueue = NULL;
}
bool isEmpty(struct Node *queue)
{
  return queue == NULL;
}
int size(struct Node *queue)
{
  int tam = 0;
  if (queue != NULL)
  {
    struct Node *principio = queue;
    do
    {
      tam++;
      queue = queue->next;
    } while (queue != NULL);
  }
  return tam;
}
void enqueue(struct Node **ptrqueue, struct Person *person)
{

  struct Node *nuevoNodo = malloc(sizeof(struct Node));
  if (nuevoNodo == NULL)
  {
    printf("No se pudo asignar memoria\n");
    exit(-1);
  }

  nuevoNodo->person = person;
  nuevoNodo->next = NULL;

  if (*ptrqueue == NULL)
  {
    *ptrqueue = nuevoNodo;
  }
  else
  {
    struct Node *aux = *ptrqueue;
    while (aux->next != NULL)
    {
      aux = aux->next;
    }
    aux->next = nuevoNodo;
  }
}
void dequeue(struct Node **ptrqueue)
{
  if (*ptrqueue != NULL)
  {
    struct Node *aux = *ptrqueue;
    *ptrqueue = aux->next;
    free(aux);
    aux = NULL;
  }
  else
  {
    printf("No se puede desencolar, la lista esta vacia\n");
    exit(-1);
  }
}
struct Person *first(struct Node *queue)
{
  struct Person *primera = NULL;
  if (queue != NULL)
  {
    primera = queue->person;
  }
  return primera;
}
void clear(struct Node **ptrqueue)
{
  struct Node *act = *ptrqueue;
  struct Node *ant = NULL;

  while (act != NULL)
  {
    ant = act;
    act = act->next;
    free(ant);
    ant = NULL;
  }
  *ptrqueue = NULL;
}

void display(struct Node *queue)
{
  struct Node *aux = queue;
  while (aux != NULL)
  {
    printf("%s -> %d\n", aux->person->name, aux->person->age);
    aux = aux->next;
  }
}