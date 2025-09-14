#include <stdio.h>

enum MesAnyo
{
  ENERO = 1,
  FEBRERO = 2,
  MARZO = 3,
  ABRIL = 4,
  MAYO = 5,
  JUNIO = 6,
  JULIO = 7,
  AGOSTO = 8,
  SEPTIEMBRE = 9,
  OCTUBRE = 10,
  NOVIEMBRE = 11,
  DICIEMBRE = 12
};

int main()
{

  int num = -1;

  while (num != 0)
  {
    printf("Introduzca un numero para saber el mes del anyo (0 para salir):");
    scanf("%d", &num);

    switch (num)
    {
    case ENERO:
      printf("Mes: Enero\n");
      break;
    case FEBRERO:
      printf("Mes: Febrero\n");
      break;
    case MARZO:
      printf("Mes: Marzo\n");
      break;
    case ABRIL:
      printf("Mes: Abril\n");
      break;
    case MAYO:
      printf("Mes: Mayo\n");
      break;
    case JUNIO:
      printf("Mes: Junio\n");
      break;
    case JULIO:
      printf("Mes: Julio\n");
      break;
    case AGOSTO:
      printf("Mes: Agosto\n");
      break;
    case SEPTIEMBRE:
      printf("Mes: Septiembre\n");
      break;
    case OCTUBRE:
      printf("Mes: Octubre\n");
      break;
    case NOVIEMBRE:
      printf("Mes: Noviembre\n");
      break;
    case DICIEMBRE:
      printf("Mes: Diciembre\n");
      break;
    default:
      printf("Numero invalido. Debe ser entre 1 y 12.\n");
    }
  }
  printf("Programa cerrado.");
  return 0;
}