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
#include "pilha.h"
#include "no.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1
// Estruta da pilha
struct pilhas {
	lista_enc_t *dados;
};


// Cria uma pilha generica
pilha_t * cria_pilha (void){
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));
    
    lista_enc_t* lista = criar_lista_enc();
    
    pilha->dados = lista;

    return pilha;
}


// Adiciona elemento na lista dentro da pilha
void push(void* dado, pilha_t *pilha){
	//Criar nó e armazenar o dado no topo da lista
	no_t* no = criar_no(dado);
	add_cabeca(pilha->dados, no);
}

// Retira elemento do topo da 'pilha'
void *pop(pilha_t *pilha){
    void* dado;
    lista_enc_t *lista = pilha->dados;
	// Verifica se a 'pilha' está corrompida
	if (obter_lista == NULL){
		perror("Pilha corrompida");
		exit(EXIT_FAILURE);
	}
	// Verifica se a lista está vazia
	if ( lista_vazia(lista) ){
		perror("Lista vazia");
		exit(EXIT_FAILURE);
	}
	// Remove a cabeca da lista
	no_t* no = obter_cabeca(lista);
	cabecar_prox(lista, no);
	dado = obter_dado(no);
	free(no);
	reduz_lista(lista);
	
	return dado;
}


// Retorna 1 se a pilha é vazia
int pilha_vazia(pilha_t *pilha){
    return (lista_vazia( pilha->dados ));
}

// Retorna a lista contida na pilha
lista_enc_t* obter_lista(pilha_t* pilha){
    return pilha->dados;
}