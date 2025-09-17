#include <stdio.h>
#include <string.h>

int main()
{

  char cad1[10]; // CUIDADO CON EL CARACTER TERMINADOR \0
  char cad2[10];
  char cad3[10] = ""; // CUIDADO CON LA BASURA, POR ESO SE DECLARA VACÍO

  strcpy(cad1, "hola");
  strcpy(cad2, "peos");

  printf("str1: %s \n", cad1);
  printf("str2: %s \n", cad2);
  printf("str3: %s \n", cad3);

  strcpy(cad3, cad2);
  printf(" \nstr3: %s \n", cad3);

  strcat(cad1, cad2);
  printf("\nstr1+str2: %s\n", cad1);

  if (strcmp(cad1, cad3) != 0)
  {
    printf("\nSon diferentes");
  }
  else
  {
    printf("\nSon iguales");
  }

  return 0;
}