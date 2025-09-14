#include <stdio.h>

int main()
{

  double arr1[3][3] = {{3, 2, 1},
                       {6, 5, 4},
                       {8, 9, 7}};

  double arr2[3][3] = {{8, 9, 7},
                       {3, 2, 1},
                       {6, 5, 4}};

  printf("Las matrices son:\n");

  printf("Matriz 1:\n");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%.0f ", arr1[i][j]);
    }
    printf("\n");
  }

  printf("Matriz 2:\n");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%.0f ", arr2[i][j]);
    }
    printf("\n");
  }

  printf("Suma de ambas matrices es:\n");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%.0f ", arr1[i][j] + arr2[i][j]);
    }
    printf("\n");
  }

  return 0;
}

// OJO!
// Tu programa en C intenta imprimir dos matrices 3×3 y su suma.
// Sin embargo, hay un problema de tipo: tus matrices son double, pero estás usando %d en printf, que es para enteros (int).
// Esto puede causar comportamiento indefinido.
// Debes usar %f para imprimir double. Si quieres que se vean como enteros (sin decimales), puedes usar %.0f.