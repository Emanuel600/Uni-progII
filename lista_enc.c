/** Parte do programa que cont�m as fun��es
 * de leitura, manipula��o e libera��o de listas
 *
 * Define a estrutura de dados e define como cada
 *fun��o deve manipular elas
 */

#include <stdio.h>          /*!< printf, fprintf */
#include <stdlib.h>         /*!< malloc, free    */

#include "lista_enc.h"      /*!< declara��o das fun��es         */
#include "dados.h"          /*!< manipula��o e cria��o de dados */
#include "no.h"             /*!< manipula��o e cria��o de n�s   */

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Refer�ncia da cabe�a da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Refer�ncia da cauda da lista encadeada: �ltimo elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (refer�ncia) da nova lista encadeada.
  */
lista_t *criar_lista_enc (void) {
    lista_t *p = malloc(sizeof(lista_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

void print (lista_t *lista){
    no_t *no;
    no = obter_cabeca(lista);

    /** Cabe�alho **/
    printf("=====================================================================\n");
    printf(" Pos\t\t  Nome  \t\t   Ouro\t Prata\tBronze\tTotal\n");
    printf("=====================================================================\n");

    while (no != NULL){
        dado_t *dados = obter_dado(no);
        imprime(dados);
        no = obter_proximo(no);
    }
}

void liberar_dados(lista_t *lista){
    no_t* no = obter_cabeca(lista);
    no_t* temp;
    while (no != NULL){
        temp = obter_proximo(no);
        free(obter_dado(no));
        free(no);
        no = temp;
    }
    free(lista);
}
