/** Declara as funções utilizadas
 * para manipulação e leitura de filas
 **/
 
// Guarda
#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
// Include do módulo
#include "lista_enc.h"

typedef struct filas fila_t;

// Cria uma fila
fila_t * cria_fila (void);

// Adiciona um elemento no topo da lista
void enqueue(void *dado, fila_t *fila);
// Remove o Ãºltimo elemento a ser colocado na lista
void* dequeue(fila_t *fila);

// Retorna se a fila está vazia
int fila_vazia(fila_t *fila);

// Libera a fila da memória
void libera_fila(fila_t* fila);

#endif // FILA_H_INCLUDED
