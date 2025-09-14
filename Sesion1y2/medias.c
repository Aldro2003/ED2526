#include <stdio.h>

int main()
{
  int n;
  double numeros[100]; // Array para almacenar los números
  double suma = 0.0;

  printf("¿Cuantos numeros desea introducir? ");
  scanf("%d", &n);

  if (n > 100 || n <= 0)
  {
    printf("Numero de elementos no valido. Debe ser entre 1 y 100.\n");
    return 1;
  }

  // Leer los números y almacenarlos en el array
  for (int i = 0; i < n; i++)
  {
    printf("Numero %d: ", i + 1);
    scanf("%lf", &numeros[i]);
    suma += numeros[i]; // Sumar los números mientras se leen
  }

  // Calcular la media
  double media = suma / n;

  // Mostrar la media
  printf("La media de los numeros es: %.2lf\n", media);

  return 0;
}
