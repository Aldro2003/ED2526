#include <stdio.h>

int main()
{
  int *ptr;
  int x = 10;
  ptr = &x;

  printf("Valor del entero x: %d, Direccion de memoria de x: %p", *ptr, &x);

  // ¿Por qué le valor de &x y de &ptr son diferentes? ¿No deberían ser el mismo?
  // No son iguales porque &x es la dirección de la variable x y &ptr es la dirección del puntero mismo.
  // Lo que sí es cierto es que ptr == &x.

  return 0;
}