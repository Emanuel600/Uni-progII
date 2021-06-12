/** Declara as funções utilizadas
 * para manipulação e leitura de listas
 **/

#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Adiciona um nó de lista no início.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cabeça.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);

// Retorna FALSO se a lista NÃO está vazia
int lista_vazia(lista_enc_t* lista);
//Remove o último elemento da lista
no_t *remover_cauda(lista_enc_t *lista);

// Define o próximo nó como a cabeça da lista
void cabecar_prox(lista_enc_t* lista, no_t* no);

void reduz_lista(lista_enc_t* lista);

#endif // LISTA_ENC_H_INCLUDED
