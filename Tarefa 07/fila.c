/** Parte do programa que contém as funções
 * de leitura e manipulação de pilhas
 *
 * Define a estrutura das pilhas e como
 *cada função deve ler/manipular elas
 */

// Includes do sistema
#include <stdlib.h>
#include <stdio.h>
// Includes do módulo
#include "lista_enc.h"
#include "fila.h"
#include "no.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados; // Variáveis de controle estão dentro da lista
};


//cria uma pilha generica
fila_t * cria_fila (void){
	fila_t* fila = NULL;
	// Alocar memória
	fila = (fila_t*)malloc(sizeof(fila_t));

	fila->dados = criar_lista_enc();

	return fila;
}


//adiciona elemento
void enqueue(void* dado, fila_t *fila){
	no_t* no;
	no = criar_no(dado);
	add_cauda(fila->dados, no);
}

// Retira elemento do topo
void *dequeue(fila_t *fila){
	no_t* no = obter_cabeca(fila->dados);
	cabecar_prox(fila->dados, no);
	void* dados = obter_dado(no);
	free(no);
	reduz_lista(fila->dados);
	return dados;
}

// Libera elementos da fila
void libera_fila(fila_t* fila){
    while (!fila_vazia(fila) ){
	    void* dado = dequeue(fila);
	    free dado;
    }
    free(fila->dados);
    free(fila);
}

// Retorna 1 se a fila é vazia
int fila_vazia(fila_t *fila){
	if (fila == NULL){
		perror("Fila inexistente");
		exit(EXIT_FAILURE);
	}
    return lista_vazia(fila->dados);
}
