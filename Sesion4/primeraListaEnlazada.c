#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int data;
  struct Node *next;
}; // Alias para la estructura

void iterar(struct Node *head)
{
  int i = 0;
  while (head != NULL)
  {
    printf("Data: %i  | Posicion: %i\n", head->data, i);
    head = head->next;
    i++;
  }
}

void append(int x, struct Node *head)
{
  while (head->next != NULL)
  {
    head = head->next;
  }
  head->next = malloc(sizeof(struct Node));
  head->next->data = x;
  head->next->next = NULL;
}

void insertar_cabeza(struct Node **ptrhead, int data)
{
  struct Node *aux = malloc(sizeof(struct Node));
  if (aux == NULL)
  {
    exit(-1);
  }
  aux->data = data;
  aux->next = *ptrhead;
  *ptrhead = aux;
}

void insertar_alfinal(struct Node **ptrhead, int data)
{
  struct Node *aux = malloc(sizeof(struct Node));
  if (aux == NULL)
  {
    exit(-1);
  }
  aux->data = data;
  aux->next = NULL;

  if (*ptrhead == NULL)
  {
    *ptrhead = aux;
  }
  else
  {

    struct Node *rotar = NULL;
    rotar = *ptrhead;

    while (rotar->next != NULL)
    {
      rotar = rotar->next;
    }

    rotar->next = aux;
  }
}

bool eliminar(struct Node **ptrhead, int data)
{
}

int main(void)
{
  // Declara una solo variable de tipo struct Node llamada head.
  // Pide memoria para tres nodos y enlaza cada una de ellas para tener el valor 3->7->9->NULL.
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));

  head->data = 3;
  head->next = malloc(sizeof(struct Node));
  head->next->data = 7;
  head->next->next = malloc(sizeof(struct Node));
  head->next->next->data = 9;
  head->next->next->next = NULL;

  iterar(head);
  insertar_alfinal(&head, 7);
  iterar(head);
  return 0;
}