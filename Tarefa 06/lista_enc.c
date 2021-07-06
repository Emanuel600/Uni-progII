/** Parte do programa que contém as funções
 * de leitura, manipulação e liberação de listas
 *
 * Define a estrutura das listas e define como cada
 *função deve ler/manipular elas
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Includes do módulo
#include "lista_enc.h"
#include "no.h"

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: Ãºltimo elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

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
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
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

// Adicionar nó no topo da lista
void add_cabeca(lista_enc_t *lista, no_t* elemento){
	if (lista == NULL || elemento == NULL){
		        fprintf(stderr,"add_cabeca: ponteiros invalidos");
		        exit(EXIT_FAILURE);
		    }

		//Caso a lista esteja vazia
		if (lista_vazia(lista)){

		        lista->cauda = elemento;
		        lista->cabeca = elemento;
		        lista->tamanho++;

		        desligar_no(elemento);
		 }

		 else{
		   ligar_nos(elemento, lista->cabeca);
		   lista->cabeca = elemento;
		   lista->tamanho++;
		 }
}

// Remove nó no final da lista
no_t *remover_cauda(lista_enc_t *lista){
	setlocale(LC_ALL, "Portuguese");
		if (lista->cauda == NULL) {
			fprintf(stderr,"Lista não contém cauda ou não existe");
	        exit(EXIT_FAILURE);
	    }
	no_t *no = lista->cauda;
	free(lista->cauda);
	return no;
}

// Reduz tamanho da lista
void reduz_lista(lista_enc_t* lista){
    lista->tamanho--;
}

// Retorna falso se a lista NÃO é vazia
int lista_vazia(lista_enc_t* lista){
	if (lista == NULL){
		fprintf(stderr,"Lista inexistente");
		exit(EXIT_FAILURE);
		}
	return !( (lista->tamanho) > 0);
}
// Define o próximo nó como a cabeça da lista
void cabecar_prox(lista_enc_t* lista, no_t* no){
    lista->cabeca = obter_proximo(no);
}

