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
  return 0;
}