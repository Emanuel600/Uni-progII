/** Declara as funções utilizadas
 * para manipulação e leitura de filas
 **/

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct filas fila_t;

fila_t * criar_fila (void);

void enqueue(void *dado, fila_t *fila);
void* dequeue(fila_t *fila);

int fila_vazia(fila_t *fila);
void liberar_fila(fila_t* fila);

#endif // FILA_H_INCLUDED
