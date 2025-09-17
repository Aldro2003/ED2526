#include <stdio.h>
#include <string.h>

void copiaCadena(char destino[], char origen[])
{
  int i = 0;
  while (origen[i] != '\0')
  {
    destino[i] = origen[i];
    i++;
  }
}

int main()
{

  char cad1[20] = "Stardew Valley";
  char cad2[20];

  copiaCadena(cad2, cad1);
  printf("Cadena1: %s \nCadena2: %s", cad1, cad2);

  return 0;
}