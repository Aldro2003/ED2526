/**
 * @file persona.h
 * @brief Cabecera para la estructura Persona y sus funciones asociadas.
 */

#ifndef PERSONA_H
#define PERSONA_H

#define CADENA_MAX_LEN   50
/**
 * @struct Persona
 * @brief Estructura para almacenar información personal.
 */
struct Persona{
    unsigned  id;
    char nombre[CADENA_MAX_LEN+1];
    char apellido[CADENA_MAX_LEN+1];
    char email[CADENA_MAX_LEN+1];
};

/**
 * @brief Crea una nueva Persona inicializada con los datos dados.
 * @param id Identificador único.
 * @param nombre Nombre (no se modifica). Asumimos que tiene contenido válido.
 * @param apellido Apellido (no se modifica). Asumimos que tiene contenido válido.
 * @param email Correo electrónico (no se modifica). Asumimos que tiene contenido válido.
 * @return Puntero a Persona creada, o NULL en caso de error (memoria o cadenas demasiado largas).
 */
struct Persona * crearPersona(unsigned id, const char *nombre, const char *apellido, const char *email);

/**
 * @brief Muestra por salida estándar la información de una Persona.
 * @param persona Puntero constante a Persona (no se modifica).
 */
void mostrarPersona(const struct Persona *persona);

/**
 * @brief Libera la memoria de una Persona y pone el puntero a NULL.
 * @param persona Doble puntero a Persona.
 */
void liberarPersona(struct Persona **persona);

#endif // PERSONA_H
