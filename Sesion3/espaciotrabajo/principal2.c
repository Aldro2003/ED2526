#include <stdio.h>
int main(void)
{
  char cad0[4] = {'p', 'e', 'n', 'a'};
  char cad[4] = {'h', 'o', 'l', '\0'}; // Con \0 se soluciona el problema
  char cad1[4] = {'c', 'a', 'r', 'a'};
  printf("%s\n", cad);

  // cad="Hola"  NO!
  // strcpy(cad, "Hola") SI!

  return 0;
}