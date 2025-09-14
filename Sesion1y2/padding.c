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

  printf("Sin Padding seria: c: %d, c2: %d, i: %d \n", sizeof(sp.c), sizeof(sp.c2), sizeof(sp.i));
  printf("Con Padding seria: c: %d, c2: %d, i: %d \n", sizeof(p.c), sizeof(p.c2), sizeof(p.i));

  return 0;
}

// No entiendo muy bien el concepto de esto