/** Parte do programa que contém as funções
 * de leitura e manipulação de nós
 *
 * Define a estrutura dos nós e define como cada
 *função deve ler/manipular eles
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
// include do módulo
#include "no.h"

struct nos{
    void* dados;     /*!< Referência do dado respectiva ao nó da lista encadeada. */
    no_t *proximo;   /*!< Referência do próximo elemento da lista encadeada. */
    no_t *anterior;  /*!< Referência do elemento anterior da lista encadeada. */
};

/**
  * @brief  Cria um novo nó de lista encadeada.
  * @param	dado: ponteiro genérico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo nó contendo a referência do dado.
  */
no_t *criar_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

/**
  * @brief  Faz o encadeamento entre dois nós de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligação.
  * @param  destino: ponteiro do destino entre a ligação.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
    destino->anterior = fonte;
}

/**
  * @brief  Remove encadeamento completo.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
    no->anterior = NULL;
}


/**
  * @brief  Remove encadeamento: apenas nó anterior.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no_anterior (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->anterior = NULL;
}

/**
  * @brief  Remove encadeamento: apenas nó sucessor.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado. 
  */
void *obter_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: onteiro do próximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}

/**
  * @brief  Obtém a referência encadeada anterior.
  * @param	no: nó de lista que se deseja obter o elemento anterior.
  *
  * @retval no_t *: ponteiro do elemento anterior da lista. NULL se final de lista.
  */
no_t *obter_anterior (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->anterior;
}
