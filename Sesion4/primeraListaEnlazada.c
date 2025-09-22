#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "primeraListaEnlazada.h"

void iterar(struct Node *head)
{

  struct Node *ptrIter = head;

  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}

void insertarCabeza(struct Node **ptrhead, int dato)
{
  struct Node *nuevoPtr = (struct Node *)malloc(sizeof(struct Node));
  if (nuevoPtr == NULL)
  {
    printf("Error al asignar memoria\n");
    exit(-1);
  }

  nuevoPtr->data = dato;
  nuevoPtr->next = *ptrhead;
  *ptrhead = nuevoPtr;
}

void insertarFinal(struct Node **ptrhead, int dato)
{

  struct Node *nuevoPtr = (struct Node *)malloc(sizeof(struct Node));
  if (nuevoPtr == NULL)
  {
    printf("Error al asignar memoria\n");
    exit(-1);
  }

  nuevoPtr->data = dato;
  nuevoPtr->next = NULL;

  if (*ptrhead == NULL)
  {
    *ptrhead = nuevoPtr;
  }
  else
  {
    struct Node *ptrIter = *ptrhead;

    while (ptrIter->next != NULL)
    {
      ptrIter = ptrIter->next;
    }
    ptrIter->next = nuevoPtr;
  }
}

void eliminarHead(struct Node **ptrHead)
{
  if (*ptrHead == NULL)
  {
    printf("No hay nodos que eliminar");
    exit(-1);
  }
  else
  {
    struct Node *aux = *ptrHead;
    *ptrHead = aux->next;
    free(aux);
    aux = NULL;
  }
}

void eliminarFinal2(struct Node **ptrhead)
{
  if (*ptrhead == NULL)
  {
    printf("No hay nodos que eliminar");
    exit(-1);
  }
  else
  {
    struct Node *aux = *ptrhead;
    while (aux->next->next != NULL)
    {
      aux = aux->next;
    }
    free(aux->next);
    aux->next = NULL;
  }
}

void eliminarDato(struct Node **ptrHead, int dato)
{
  struct Node *act = *ptrHead;
  struct Node *ant = NULL;
  while (act != NULL && act->data != dato)
  {
    ant = act;
    act = act->next;
  }
  if (act != NULL)
  {
    if (act == *ptrHead)
    {
      *ptrHead = act->next;
    }
    else
    {
      ant->next = act->next;
    }
    free(act);
    act = NULL;
  }
  else
  {
    printf("El dato %d no se encuentra en la lista\n", dato);
  }
}

void destruir(struct Node **ptrHead)
{

  if (*ptrHead == NULL)
  {
    printf("La lista no existe");
    exit(-1);
  }
  while (*ptrHead != NULL)
  {
    struct Node *aux = *ptrHead;
    *ptrHead = aux->next;
    printf("Va a morir esto %d\n", aux->data);
    free(aux);
    aux = NULL;
  }
}

void insertarEnPosicion(struct Node **ptrHead, int dato, int pos)
{
  struct Node *nuevoNodo = (struct Node *)malloc(sizeof(struct Node));
  struct Node *act = *ptrHead;
  struct Node *ant = NULL;
  if (nuevoNodo == NULL)
  {
    printf("No se pudo asignar la memoria");
    exit(-1);
  }
  nuevoNodo->data = dato;
  if (pos == 0)
  {
    insertarCabeza(ptrHead, dato);
  }
  else
  {
    int i = 0;
    while (act != NULL && i <= pos - 1)
    {
      ant = act;
      act = act->next;
      i++;
    }
    if (i == pos)
    {
      ant->next = nuevoNodo;
      nuevoNodo->next = act;
    }
    else
    {
      printf("Error no se ha podido insertar en la posicion\n");
    }
  }
}
