#include <stdio.h>

int main()
{
  int n;
  double numeros[100]; // Array para almacenar los números
  double suma = 0.0;

  while (n > 100 || n <= 0)
  {
    printf("¿Cuantos numeros desea introducir? (Debe ser entre 1 y 100) ");
    scanf("%d", &n);
  }

  printf("Introduce los numeros: ");

  // Leer los números y almacenarlos en el array
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &numeros[i]);
    suma += numeros[i]; // Sumar los números mientras se leen
  }

  // Calcular la media
  double media = suma / n;

  // Mostrar la media
  printf("La media de los numeros es: %.2lf\n", media);

  return 0;
}
