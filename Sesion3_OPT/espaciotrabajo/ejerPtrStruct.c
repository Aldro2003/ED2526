#include <stdio.h>

struct Punto
{
  int x, y;
};

void intercambiarXY(struct Punto *p)
{

  int temp;
  temp = p->x;
  p->x = p->y;
  p->y = temp;
}

int main()
{

  struct Punto p;

  p.x = 5;
  p.y = 3;

  printf("Punto antes: X=%d Y=%d\n", p.x, p.y);
  intercambiarXY(&p);
  printf("Punto despues: X=%d Y=%d", p.x, p.y);

  return 0;
}