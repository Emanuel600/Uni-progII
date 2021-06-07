#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
	int topo;
};


//cria uma pilha generica
pilha_t * cria_pilha (void){
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    pilha->topo = 0;
    
    lista_enc_t* lista = criar_lista_enc();
    
    pilha->dados = lista;

    return pilha;
}


//adiciona elemento na lista dentro da pilha
void push(void* dado, pilha_t *pilha){
	//Criar nó e armazenar o dado
	no_t* no = criar_no(dado);
	add_cabeca(pilha->dados, no);
	pilha->topo++;
}
/*
//retira elemento do topo ?
void *pop(pilha_t *pilha){
	int topo = pilha->topo;
	// Verifica se a lista está corrompida
	if (topo<0){
		perror("Lista corrompida");
		exit(EXIT_FAILURE);
	}
	// Verifica se a pilha está vazia
	if (topo == 0){
		perror("Pilha vazia");
		return 0;
	}
	//Remove elemento
	free(pilha->dados);
	pilha->topo--;
	return obter_lista(pilha);
}
*/

void libera_pilha(pilha_t* pilha){
	free(pilha);
}

// Retorna 1 se a pilha é vazia
int pilha_vazia(pilha_t *pilha){
    return !(pilha->topo>0);
}

void pprint(pilha_t* pilha){
    lista_enc_t* lista = obter_lista(pilha);
    print(lista);
}

lista_enc_t* obter_lista(pilha_t* pilha){
    return pilha->dados;
}


