#include <stdio.h>

int main()
{
  int entero1 = 42;
  int entero2 = 36;
  char caracter = 'X';
  char cadena[] = "Hola, mundo!";
  // Especificadores de formato:
  printf("Suma: %d + %d = %d\n", entero1, entero2, entero1 + entero2); // Ancho mínimo de 5 caracteres
  printf("Carácter: %c\n", caracter);
  printf("Cadena: %-20s\n", cadena); // Justificación a la izquierda, ancho mínimo de 20 caracteres
  return 0;
}
