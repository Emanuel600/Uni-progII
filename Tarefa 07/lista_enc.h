/** Declara as fun��es utilizadas para
 * manipula��o e leitura de listas
 **/

// Guarda
#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED
// Include do m�dulo
#include "no.h"

typedef struct listas_enc lista_enc_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (refer�ncia) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Adiciona um n� de lista no in�cio.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: n� que ser� adicionado na cabe�a.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);

// Retorna se a lista est� vazia
int lista_vazia(lista_enc_t* lista);
//Remove cauda do n�
no_t *remover_cauda(lista_enc_t *lista);

//Torna a cabeca da lista pelo pr�ximo n�
void cabecar_prox(lista_enc_t* lista, no_t* no);

// Reduz tamanho da lista
void reduz_lista(lista_enc_t* lista);

// Libera os dados da lista
void liberar_lista(lista_enc_t* lista);

#endif // LISTA_ENC_H_INCLUDED
