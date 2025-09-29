#include "primeraListaEnlazada.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // Declara una solo variable de tipo struct Node llamada head.
  struct Node *head = NULL;

  insertarFinal(&head, 50);
  insertarFinal(&head, 900);
  insertarCabeza(&head, 60);
  insertarCabeza(&head, 70);
  insertarCabeza(&head, 80);
  eliminarDato(&head, 900);
  eliminarDato(&head, 80);
  eliminarDato(&head, 70);
  eliminarDato(&head, 90);
  insertarEnPosicion(&head, 20, 2);
  iterar(head);

  // Pide memoria para tres nodos y enlaza cada una de ellas para tener el valor 3->7->9->NULL.
  return 0;
}