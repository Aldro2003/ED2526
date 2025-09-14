#include <stdio.h>
int main()
{
  int entero = 2097;
  printf("Un char en tu máquina tiene %lu bytes\nUn entero tiene sin embargo %lu bytes\n", sizeof(char), sizeof(int));
  printf("Si interpreto 2097 en decimal (que es 0x0131 en hexadecimal) como caracter sale: %c (como el primer byte solo que es 0x31 o 49 (mira tabla ASCII))\n", entero); // %c interpreta como un caracter la variable entero, cogiendo su primer byte. \n es un carácter que introduce un retorno de carro
  printf("Si interpreto 2097 en decimal (que es 0x0131 en hexadecimal) como entero: %d (como sus cuatro bytes)\n", entero);                                               // %d interpreta como un entero la variable entero, cogiendo sus 4 bytes.
  return 0;
}