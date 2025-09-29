#include "Scheduler.h"
#include "Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct Node
{
  struct Task *task;   // Task to be executed
  struct Node *p_next; // Pointer to next node in circular list
};
*/

struct Node *Scheduler_new(void)
{

  struct Node *newSch = (struct Node *)malloc(sizeof(struct Node));
  newSch = NULL;
  return newSch;

} // Initialize an empty scheduler

/**
 * @brief Devuelve el número de tareas en el planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Cantidad de tareas encoladas.
 */
size_t Scheduler_size(const struct Node *p_last)
{
  const struct Node *ult = p_last;
  const struct Node *act = p_last->p_next;
  int size = 0;

  while (act != ult)
  {
    act = act->p_next;
    size++;
  }

  return size;
}

/**
 * @brief Elimina todas las tareas del planificador y lo deja vacío.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        se pone a NULL al finalizar.
 */
void Scheduler_clear(struct Node **p_p_last)
{
  if (p_p_last == NULL)
  {
    exit(-1);
  }
  else
  {
    while ((*p_p_last != NULL))
    {
      Scheduler_dequeue(&(*p_p_last));
    }
  }
}

/**
 * @brief Obtiene una copia en memoria dinámica de la primera tarea del planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Puntero a una copia de la primera Task, o NULL si la cola está vacía.
 * @note El llamador es responsable de liberar la Task devuelta.
 */
struct Task *Scheduler_first(const struct Node *p_last)
{
  return Task_copyOf(p_last->p_next->task);
}

/**
 * @brief Encola al final una copia de la tarea dada.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        puede actualizarse si la cola estaba vacía.
 * @param p_task Puntero a la tarea origen a copiar (no se modifica).
 * @return true en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_enqueue(struct Node **p_p_last, const struct Task *p_task)
{

  struct Node *aux = (struct Node *)malloc(sizeof(struct Node));

  if (aux == NULL)
  {
    exit(-1);
  }

  if ((*p_p_last) == NULL)
  {
    aux->task = Task_copyOf(p_task);
    aux->p_next = aux;
  }
  else
  {
    aux->task = Task_copyOf(p_task);
    aux->p_next = (*p_p_last)->p_next;
    (*p_p_last)->p_next = aux;
  }
  *p_p_last = aux;
}

/**
 * @brief Desencola la primera tarea del planificador.
 * @param p_p_last Dirección de memoria donde está el puntero al último nodo de la cola;
 *        puede actualizarse y quedar en NULL si se vacía.
 * @note Si la cola está vacía, no hace nada.
 * @return True en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_dequeue(struct Node **p_p_last)
{
  if ((*p_p_last) == NULL)
  {
    exit(-1);
  }

  if ((*p_p_last) == ((*p_p_last)->p_next))
  {
    free(*p_p_last);
    *p_p_last = NULL;
  }
  else
  {
    struct Node *aux = (*p_p_last)->p_next;
    (*p_p_last)->p_next = aux->p_next;
    free(aux);
  }
}

/**
 * @brief Imprime todas las tareas del planificador.
 * @param p_last Puntero al último nodo de la cola.
 */
void Scheduler_print(const struct Node *p_last)
{

  if (p_last == NULL)
  {
    printf("Lista vacía.\n");
  }
  else
  {
    struct Node *aux = p_last->p_next;
    while (aux != p_last)
    {
      Task_print(aux->task);
      aux = aux->p_next;
    }
    printf("\n");
  }

} // Print all tasks in the scheduler