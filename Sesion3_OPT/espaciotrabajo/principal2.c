#include <stdio.h>

int main()
{

  // ARRAY

  /*
    Se permiten comparar direcciones de memoria, un array es un puntero al primer elemento.
    a == &a[0]

    Se puede sumar a un puntero. Dependiendo de su tipo, avanzará mas o menos bytes en memoria.
    *(ptr + 1) == a[1]

    El operador ++ se puede usar para iterar.
    ptr++

    Podemos saltar el puntero i posiciones en el array
    ptr += i
  */

  // CADENAS

  /*
  // Copia src en dest (sin controlar el tamaño de src)
    char *strcpy(char *dest, const char *src);
  //Retorna la longitud de str (se supone terminado en \0)
    size_t strlen(const char *str);
  //Añade src a dest
    char *strcat(char *dest, const char *src);
  //Compara str1 y str2, devuelve:
    //0 si son iguales;
    //menor que 0 si str1<str2;
    //y mayor que 0 si str1>str2
    int strcmp(const char *str1, const char *str2);

  */

  /*
  Si necesitamos pasar un array como parámetro de
  un función SIEMPRE se le pasa la dirección de
  comienzo de éste
  Nunca se pasan por valor (copia de sus elementos)
  */

  return 0;
}