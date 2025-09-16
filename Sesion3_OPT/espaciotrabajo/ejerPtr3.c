#include <stdio.h>

void sumarNumeros(int *a, int b)
{
  *a = *a + b; // se modifica el valor de 'a' (por referencia)
}

int main()
{
  int x = 5;
  int y = 7;

  sumarNumeros(&x, y); // Modifica el primero de ellos para deovlver la suma (paso por referencia)

  printf("x: %d, y: %d", x, y);

  return 0;
}