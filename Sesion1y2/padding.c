#include <stdio.h>

// Usa *sizeof*
struct SinPadding
{
  char c;  // 1 byte
  int i;   // 4 bytes
  char c2; // 1 byte
};
struct ConPadding
{
  char c;  // 1 byte
  char c2; // 1 byte
  int i;   // 4 bytes
};

int main()
{
  struct SinPadding sp;
  struct ConPadding p;

  // printf("Sin Padding seria: c: %d, c2: %d, i: %d \n", sizeof(sp.c), sizeof(sp.c2), sizeof(sp.i));
  // printf("Con Padding seria: c: %d, c2: %d, i: %d \n", sizeof(p.c), sizeof(p.c2), sizeof(p.i));

  printf("Tamanyo total SinPadding: %zu\n", sizeof(sp));
  printf("Tamanyo total ConPadding: %zu\n", sizeof(p));

  return 0;
}

/*
Cuando defines una struct, el compilador puede agregar bytes extra entre los miembros para que cada dato quede alineado según su tipo.
Esto se llama padding.
La alineación depende de la arquitectura y del tipo de dato.
Por ejemplo, un int generalmente debe estar en una dirección múltiplo de 4 bytes.
Si no está alineado, el procesador podría acceder más lento a la memoria.
*/

// REPASAR!!!