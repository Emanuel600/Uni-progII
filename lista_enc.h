/** Declara as fun��es utilizadas
 * para manipula��o de listas
 **/

#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h" /*!< para poder retornar n�s */

typedef struct listas_enc lista_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (refer�ncia) da nova lista encadeada.
  */
lista_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_t *lista, no_t* elemento);

/**
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_t *lista);

/** Imprime os dados **/
void print(lista_t *lista);

/** Libera os dados **/
void liberar_dados(lista_t *lista);

#endif // LISTA_ENC_H_INCLUDED
