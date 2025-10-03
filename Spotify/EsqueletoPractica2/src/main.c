#include "lista_enlazada_doble.h"
#include <stdio.h>

int main()
{
    struct PlayList myPlaylist;

    printf("=== Inicializando Playlist ===\n");
    PlayList_create(&myPlaylist);

    // Insertar al frente
    printf("\n=== Insertando canciones al frente ===\n");
    PlayList_insertAtFront(&myPlaylist, "Song A");
    PlayList_insertAtFront(&myPlaylist, "Song B");
    PlayList_insertAtFront(&myPlaylist, "Song C"); // Lista: C, B, A
    PlayList_print(myPlaylist);

    // Insertar al final
    printf("\n=== Insertando canciones al final ===\n");
    PlayList_insertAtEnd(&myPlaylist, "Song D");
    PlayList_insertAtEnd(&myPlaylist, "Song E"); // Lista: C, B, A, D, E
    PlayList_print(myPlaylist);

    // Insertar en orden
    printf("\n=== Insertando canciones en orden ===\n");
    PlayList_insertInOrder(&myPlaylist, "Song F");  // Se colocará al final
    PlayList_insertInOrder(&myPlaylist, "Song AA"); // Se colocará al principio
    PlayList_print(myPlaylist);

    // Intentar insertar duplicado
    printf("\n=== Intentando insertar duplicado ===\n");
    if (PlayList_insertAtFront(&myPlaylist, "Song A") == -1)
    {
        printf("No se puede insertar 'Song A', ya existe.\n");
    }

    // Insertar después de una canción
    printf("\n=== Insertando después de 'Song B' ===\n");
    PlayList_insertAfter(&myPlaylist, "Song B", "Song G");
    PlayList_print(myPlaylist);

    // Insertar antes de una canción
    printf("\n=== Insertando antes de 'Song D' ===\n");
    PlayList_insertBefore(&myPlaylist, "Song D", "Song H");
    PlayList_print(myPlaylist);

    // Probar forward y backward
    printf("\n=== Probando forward y backward ===\n");
    printf("Canción actual: %s\n", PlayList_currentSong(myPlaylist));
    PlayList_forwardSong(&myPlaylist);
    printf("Siguiente canción: %s\n", PlayList_currentSong(myPlaylist));
    PlayList_backwardSong(&myPlaylist);
    printf("Canción anterior: %s\n", PlayList_currentSong(myPlaylist));

    // Borrar canción
    printf("\n=== Borrando 'Song A' ===\n");
    PlayList_deleteSong(&myPlaylist, "Song A");
    PlayList_print(myPlaylist);

    // Borrar desde el frente
    printf("\n=== Borrando desde el frente ===\n");
    PlayList_deleteFromFront(&myPlaylist);
    PlayList_print(myPlaylist);

    // Ordenar lista
    printf("\n=== Ordenando lista ===\n");
    PlayList_order(&myPlaylist);
    PlayList_print(myPlaylist);

    // Borrar todo
    printf("\n=== Borrando toda la lista ===\n");
    PlayList_deleteAll(&myPlaylist);
    PlayList_print(myPlaylist);

    return 0;
}
