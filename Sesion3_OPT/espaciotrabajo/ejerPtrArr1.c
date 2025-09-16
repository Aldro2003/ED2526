#include <stdio.h>

int main()
{

  int arr[3] = {0, 1, 2};
  int *ptr;
  ptr = &arr[0];

  while (ptr != &arr[3])
  {
    printf("Valor dentro del array: %d\n", *ptr);
    ptr++;
  }

  return 0;
}

// VERSION GPTO

/*
#include <stdio.h>

int main() {
    int array[10];        // Declaramos un array de 10 enteros
    int *ptr;             // Declaramos un puntero a entero

    ptr = array;          // El puntero apunta al primer elemento del array

    // Inicializamos el array usando el puntero
    for (int i = 0; i < 10; i++) {
        *(ptr + i) = i;   // Asignamos el valor de la posición al elemento
    }

    // Mostramos los valores del array usando el puntero
    printf("Valores del array:\n");
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, *(ptr + i));
    }

    return 0;
}
*/