#include <stdio.h>

struct Punto
{
  double x, y;
};

int main()
{
  int n = -1;
  double sumaX = 0.0;
  double sumaY = 0.0;
  struct Punto p;

  while (n > 100 || n <= 0)
  {
    printf("¿Cuantos puntos desea introducir? (Debe ser entre 1 y 100) ");
    scanf("%d", &n);
  }

  for (int i = 0; i < n; i++)
  {
    printf("Introduce el punto: ");

    // Leer los números y almacenarlos en el array
    scanf("%lf %lf", &p.x, &p.y);
    sumaX += p.x; // Sumar los números mientras se leen
    sumaY += p.y;
  }

  // Calcular la media
  double xc = sumaX / n;
  double yc = sumaY / n;

  // Mostrar la media
  printf("El centroide es: (%.2lf, %.2lf)\n", xc, yc);

  return 0;
}