#include <stdio.h>

int main()
{
  int entero1;
  int entero2;
  char caracter;
  char cadena[100];

  printf("Introduce un numero entero para sumar:");
  scanf("%d", &entero1); // Le decimos a scanf: "guarda el entero que leas en la dirección de entero1"
                         // para eso sirve el &
  printf("Introduce un numero entero para sumar:");
  scanf("%d", &entero2);

  printf("Introduce un caracter: ");
  scanf(" %c", &caracter);

  // ¿Pq tengo que dejar un espacio en " %c"?

  // scanf("%d", &entero2) lee un número, pero no consume el Enter que presionas.
  // Entonces el siguiente scanf("%c", &caracter) lee ese '\n' en lugar del carácter que quieres.

  printf("Introduce una cadena: ");
  scanf("%s", &cadena);

  // Especificadores de formato:
  printf("Suma: %d + %d = %d\n", entero1, entero2, entero1 + entero2); // Ancho mínimo de 5 caracteres
  printf("Carácter: %c\n", caracter);
  printf("Cadena: %-20s\n", cadena); // Justificación a la izquierda, ancho mínimo de 20 caracteres
  return 0;
}
