/** Parte do programa que contém as funções
 * de leitura, manipulação e liberação de listas
 * 
 * Define a estrutura de dados e define como cada
 *função deve manipular elas
 */

#include <stdio.h>          /*!< printf, fprintf */
#include <stdlib.h>         /*!< malloc, free    */

#include "lista_enc.h"      /*!< declaração das funções         */
#include "dados.h"          /*!< manipulação e criação de dados */
#include "no.h"             /*!< manipulação e criação de nós   */

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
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
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
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

    /** Cabeçalho **/
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
