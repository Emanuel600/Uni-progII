/** Declara as funções utilizadas
 * para manipulação e leitura de pilhas
 **/

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "lista_enc.h"

typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha vazia.
  * @param	Nenhum
  *
  * @retval pilha_t *: ponteiro (referência) da nova pilha.
  */
pilha_t * cria_pilha (void);

// Adiciona um elemento no topo da pilha
void push(void *dado, pilha_t *pilha);

// Remove o topo da pilha
void* pop(pilha_t *pilha);

// Libera dados da pilha
void libera_pilha(pilha_t* pilha);

// Retorna FALSO se a pilha NÃO está vazia
int pilha_vazia(pilha_t *pilha);

// Obtém a lista contida em uma pilha
lista_enc_t* obter_lista(pilha_t* pilha);

#endif // PILHA_H_INCLUDED
