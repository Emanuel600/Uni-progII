/** Parte do programa que cont�m as fun��es
 * de leitura, manipula��o e libera��o de listas
 *
 * Define a estrutura das listas e define como cada
 *fun��o deve ler/manipular elas
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Includes do m�dulo
#include "lista_enc.h"
#include "no.h"

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
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
   //lista vazia
   if (lista->tamanho == 0)
   {
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

// Adicionar n� no topo da lista
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

// Remove n� no final da lista
no_t *remover_cauda(lista_enc_t *lista){
	setlocale(LC_ALL, "Portuguese");
		if (lista->cauda == NULL) {
			fprintf(stderr,"Lista n�o cont�m cauda ou n�o existe");
	        exit(EXIT_FAILURE);
	    }
	no_t *no = lista->cauda;
	free(lista->cauda);
	lista->tamanho--;
	return no;
}

// Reduz tamanho da lista
void reduz_lista(lista_enc_t* lista){
    lista->tamanho--;
}

// Retorna falso se a lista NÃO � vazia
int lista_vazia(lista_enc_t* lista){
	if (lista == NULL){
		fprintf(stderr,"Lista inexistente");
		exit(EXIT_FAILURE);
		}
	return !( (lista->tamanho) > 0);
}
// Define o pr�ximo n� como a cabe�a da lista
void cabecar_prox(lista_enc_t* lista, no_t* no){
    lista->cabeca = obter_proximo(no);
}

