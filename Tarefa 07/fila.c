/** Parte do programa que cont�m as fun��es
 * de leitura e manipula��o de pilhas
 *
 * Define a estrutura das pilhas e como
 *cada fun��o deve ler/manipular elas
 */

// Includes do sistema
#include <stdlib.h>
#include <stdio.h>
// Includes do m�dulo
#include "lista_enc.h"
#include "fila.h"
#include "no.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados; // Vari�veis de controle est�o dentro da lista
};


//cria uma pilha generica
fila_t * cria_fila (void){
	fila_t* fila = NULL;
	// Alocar mem�ria
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
    free(fila->dados);
    free(fila);
}

// Retorna 1 se a fila � vazia
int fila_vazia(fila_t *fila){
	if (fila == NULL){
		perror("Fila inexistente");
		exit(EXIT_FAILURE);
	}
    return lista_vazia(fila->dados);
}
