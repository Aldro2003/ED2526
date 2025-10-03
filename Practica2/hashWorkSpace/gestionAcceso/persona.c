#include "persona.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CADENA_MAX_LEN 50
/**
 * @struct Persona
 * @brief Estructura para almacenar información personal.
 */

/*
struct Persona{
   unsigned  id;
   char nombre[CADENA_MAX_LEN+1];
   char apellido[CADENA_MAX_LEN+1];
   char email[CADENA_MAX_LEN+1];
};
*/

/**
 * @brief Crea una nueva Persona inicializada con los datos dados.
 * @param id Identificador único.
 * @param nombre Nombre (no se modifica). Asumimos que tiene contenido válido.
 * @param apellido Apellido (no se modifica). Asumimos que tiene contenido válido.
 * @param email Correo electrónico (no se modifica). Asumimos que tiene contenido válido.
 * @return Puntero a Persona creada, o NULL en caso de error (memoria o cadenas demasiado largas).
 */
struct Persona *crearPersona(unsigned id, const char *nombre, const char *apellido, const char *email)
{

  if (strlen(nombre) > CADENA_MAX_LEN + 1 || strlen(apellido) > CADENA_MAX_LEN + 1 || strlen(email) > CADENA_MAX_LEN + 1)
  {
    perror("Cadena demasiado larga.\n");
    exit(-1);
  }

  struct Persona *nuevaPersona = (struct Persona *)malloc(sizeof(struct Persona));

  if (nuevaPersona == NULL)
  {
    perror("No se ha podido reservar memoria.\n");
    exit(-1);
  }

  nuevaPersona->id = id;
  strcpy(nuevaPersona->nombre, nombre);
  strcpy(nuevaPersona->apellido, apellido);
  strcpy(nuevaPersona->email, email);

  return nuevaPersona;
}

/**
 * @brief Muestra por salida estándar la información de una Persona.
 * @param persona Puntero constante a Persona (no se modifica).
 */
void mostrarPersona(const struct Persona *persona)
{
  printf("ID: %i, Nombre: %s, Apellido: %s, Email: %s \n", persona->id, persona->nombre, persona->apellido, persona->email);
}

/**
 * @brief Libera la memoria de una Persona y pone el puntero a NULL.
 * @param persona Doble puntero a Persona.
 */
void liberarPersona(struct Persona **persona)
{

  if (*persona == NULL)
  {
    printf("No hay nada que borrar.\n");
  }
  else
  {
    free(*persona);
    *persona = NULL;
  }
}