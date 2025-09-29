#include "colaEnlazada.h"
#include <stdio.h>

void datosCola(struct Node cola)
{
  printf("-----------------\n");
  printf("Tamaño de la cola %d\n", size(cola));
  printf("Está vacío: %s\n", (isEmpty(cola) ? "true" : "false"));
  display(cola);
}

void datosPrimero(struct Node *cola)
{
  struct Person *p = first(cola);
  printf("-----------------\n");
  printf("Persona (%s %d)", p->name, p->age);
}

int main(void)
{
  struct Node cola;
  createQueue(&cola);

  datosCola(cola);
  datosPrimero(cola);

  enqueue(&cola, createPerson("Joaquín", 42));
  datosCola(cola);
  datosPrimero(cola);

  enqueue(&cola, createPerson("Carlos", 19));
  enqueue(&cola, createPerson("Ana", 21));

  datosCola(cola);
  datosPrimero(cola);

  dequeue(&cola);

  dequeue(&cola);
  datosCola(cola);
  datosPrimero(cola);

  dequeue(&cola);
  datosCola(cola);
  datosPrimero(cola);

  return 0;
}