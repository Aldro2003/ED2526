#ifndef primeraListaEnlazada // Evita la inclusión múltiple del archivo de encabezado
#define primeraListaEnlazada

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}; // Alias para la estructura

void iterar(struct Node *head);
void insertarCabeza(struct Node **ptrhead, int dato);
void insertarFinal(struct Node **ptrhead, int dato);
void eliminarHead(struct Node **ptrHead);
void eliminarFinal2(struct Node **ptrhead);
void eliminarDato(struct Node **ptrHead, int dato);
void destruir(struct Node **ptrHead);
void insertarEnPosicion(struct Node **ptrHead, int dato, int pos);

#endif