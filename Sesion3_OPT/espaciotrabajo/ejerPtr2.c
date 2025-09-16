#include <stdio.h>

int main()
{
  int *ptrInt;
  char *ptrChar;
  float *ptrFloat;

  int x = 10;
  char y = 'y';
  float z = 3.14;

  ptrInt = &x;
  ptrChar = &y;
  ptrFloat = &z;

  printf("Valor del entero x: %d, Direccion de memoria de x: %p, Tamaño ocupado en bytes: %d\n", *ptrInt, &x, sizeof(ptrInt));
  printf("Valor del char y: %c, Direccion de memoria de y: %p, Tamaño ocupado en bytes: %d\n", *ptrChar, &y, sizeof(ptrChar));
  printf("Valor del float z: %.2f, Direccion de memoria de z: %p, Tamaño ocupado en bytes: %d\n", *ptrFloat, &z, sizeof(ptrFloat));

  return 0;
}