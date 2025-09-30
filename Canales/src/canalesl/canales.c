#include "canales.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 25
/*


enum Tipo {TV, RADIO};

struct T_Canal{
    char nombre[MAX_NOMBRE+1];
    int pos;            //posicion que ocupa el canal en la lista
    enum Tipo tipo;     //canal de radio o television
    struct T_Canal*  sig;   //referencia al siguiente canal
};
*/

/**
 * @brief Crea un nuevo canal.
 *
 * Esta función se encarga de inicializar la lista de canales.
 *
 * @param canales Doble puntero a una estructura T_Canal donde se almacenarán los canales en un futuro.
 */
void crear(struct T_Canal **canales)
{
    *canales = NULL;
}

/**
 * @brief Destruye la lista de canales.
 *
 * Esta función libera la memoria asignada para cada canal, dejando el @p canales apuntando a NULL.
 *
 * @param canales Dirección de memoria del puntero a la cabeza de la lista.
 */
void destruir(struct T_Canal **canales)
{
    free(*canales);
    *canales = NULL;
}

/**
 * @brief Muestra la información de los canales.
 *
 * Esta función toma un puntero a una estructura T_Canal y muestra la información
 * contenida en los canales.
 *
 * @param canales Puntero a una estructura T_Canal que contiene la información de los canales.
 */
void mostrar(struct T_Canal *canales)
{
    struct T_Canal *aux = canales;
    while (aux != NULL)
    {
        printf("Nombre: %s, Posicion: %d, Tipo: %d \n", aux->nombre, aux->pos, aux->tipo);
        aux = aux->sig;
    }
}

/**
 * @brief Inserta un nuevo canal en la lista de canales.
 *
 * Esta función inserta un nuevo canal en la posición especificada dentro de la lista de canales. Si en la lista de canales ya existe un canal en dicha
posicion, el nuevo se insertar en la posición indicada y el canal antiguo (y los consecutivos en posiciones mayores) se desplazaran una posición.
 *
 * @param canales Dirección de memoria del puntero a la cabeza de la lista.
 * @param nombreCanal Nombre del canal a insertar.
 * @param posCanal Posición en la que se debe insertar el nuevo canal.
 * @param tipoCanal Tipo del canal a insertar.
 */
void insertar(struct T_Canal **canales, char *nombreCanal, int posCanal, enum Tipo tipoCanal)
{
    if (strlen(nombreCanal) > MAX_NOMBRE)
    {
        perror("Nombre demasiado largo.\n");
        exit(-1);
    }

    struct T_Canal *nuevoCanal = (struct T_Canal *)malloc(sizeof(struct T_Canal));

    if (nuevoCanal == NULL)
    {
        perror("Espacio insuficiente.\n");
        exit(-1);
    }

    strcpy(nuevoCanal->nombre, nombreCanal);
    nuevoCanal->pos = posCanal;
    nuevoCanal->tipo = tipoCanal;
    nuevoCanal->sig = NULL;

    if (*canales == NULL || (*canales)->pos > nuevoCanal->pos) // CASO 1: ESTÁ VACÍA LA LISTA DE CANALES
    {
        nuevoCanal->sig = *canales;
        *canales = nuevoCanal;
    }
    else
    { // CASO 2: NO ESTÁ VACÍA LA LISTA DE CANALES

        struct T_Canal *aux = *canales;

        while (aux->sig != NULL && aux->sig->pos < posCanal)
        {
            aux = aux->sig;
        }

        nuevoCanal->sig = aux->sig;
        aux->sig = nuevoCanal;

        while (nuevoCanal->sig != NULL && nuevoCanal->sig->pos == nuevoCanal->pos)
        {
            nuevoCanal->sig->pos++;
            nuevoCanal = nuevoCanal->sig;
        }
    }
}

/**
 * @brief Elimina un canal de la lista de canales.
 *
 * Esta función busca un canal por su nombre en la lista de canales proporcionada
 * y lo elimina si es encontrado.
 *
 * @param canales Dirección de memoria del puntero a la cabeza de la lista.
 * @param nombreCanal Nombre del canal a eliminar.
 * @return int Retorna 0 si el canal fue eliminado exitosamente, o un valor negativo si ocurrió un error.
 */
int eliminar(struct T_Canal **canales, char *nombreCanal)
{

    struct T_Canal *aux = *canales;

    struct T_Canal *anterior = NULL;

    while (aux != NULL && strcmp(aux->nombre, nombreCanal) != 0)
    {
        anterior = aux;
        aux = aux->sig;
    }

    if (aux == NULL)
    {
        return -1;
    }

    if (anterior == NULL)
    {
        *canales = aux->sig;
    }
    else
    {
        anterior->sig = aux->sig;
    }

    free(aux);

    return 0;
}

/**
 * @brief Extrae un canal de radio de la lista de canales de origen.
 *
 * @param origen Dirección de memoria dónde está el puntero a la cabeza de la lista.
 * @return Dirección de memoria de la lista de solo canales de radio extraída. Debes mover, no pedir nueva memoria para maxima nota.
 */

struct T_Canal *extraerRadio(struct T_Canal **origen)
{
    struct T_Canal *Radio_Lista = NULL;  // Cabeza de la nueva lista que contendrá solo canales RADIO.
    struct T_Canal *Radio_Actual = NULL; // Puntero al último nodo de Radio_Lista (para añadir en O(1)).
    struct T_Canal **actual = origen;    // "Puntero a puntero" usado para recorrer y modificar la lista origen.

    while (*actual != NULL) // Mientras el nodo apuntado por 'actual' exista (es decir, no hemos llegado al final).
    {
        if ((*actual)->tipo == RADIO) // Si el nodo actual es de tipo RADIO...
        {
            struct T_Canal *canalRadio = *actual; // Guardamos el nodo RADIO (no creamos uno nuevo, lo movemos).
            *actual = (*actual)->sig;             // Lo quitamos de la lista origen: hacemos que el puntero que
                                                  // apuntaba a este nodo pase a apuntar al siguiente (lo "salta").
            canalRadio->sig = NULL;               // Desconectamos el nodo movido: su 'sig' ahora es NULL,
                                                  // porque lo vamos a poner al final de Radio_Lista.
            if (Radio_Lista == NULL)              // Si la lista de radios aún está vacía...
            {
                Radio_Lista = canalRadio;  // ...este nodo será la cabeza de Radio_Lista.
                Radio_Actual = canalRadio; // Y también el último nodo (porque es el único).
            }
            else // Si ya hay nodos en Radio_Lista...
            {
                Radio_Actual->sig = canalRadio; // ...enlazamos el nuevo nodo al final.
                Radio_Actual = canalRadio;      // Actualizamos el puntero al último nodo.
            }
        }
        else // Si el nodo actual NO es de tipo RADIO...
        {
            actual = &(*actual)->sig; // ...avanzamos: 'actual' pasa a apuntar al puntero 'sig'
                                      // del nodo actual (es decir, ahora referenciamos al siguiente nodo).
            // Nota: usar puntero-a-puntero evita tener que mantener un 'prev'. Cuando *actual cambia
            // para "saltar" un nodo RADIO, seguimos apuntando al lugar correcto para continuar el recorrido.
        }
    }

    return Radio_Lista; // Devolvemos la lista que contiene sólo los nodos RADIO (movidos).
}
