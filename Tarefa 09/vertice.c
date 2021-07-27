/** Parte do programa que contém as funções
 * de criação e manipulação de vértices.
 *
 * Define a estrutura dos vértices e sua
 *criação/manipulação.
 */

// Includes do sistema
#include <stdlib.h>
#include <stdio.h>
// Includes do módulo
#include "lista_enc.h"
#include "vertice.h"

struct vertices {
	int id;                /*!< Identificação numérica do vértice  */
	/* Informações para a busca em largura */
	int distancia;
	vertice_t* pai;

    /* Árvore */
    vertice_t* esq;
	vertice_t* dir;
	int key;
};

/**
  * @brief  Cria uma novo vértice 
  * @param	id: Identificação numérica do vértice
  *
  * @retval vertice_t: ponteiro para um novo vértice
  */
vertice_t *criar_vertice(int id)
{
	vertice_t *p = NULL;

	p = malloc(sizeof(vertice_t));

	if (p == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->esq = NULL;
	p->dir = NULL;
	p->key = 0;

	return p;
}

/**
  * @brief  Obtém o identificador numérico do vértice
  * @param	vertice: ponteiro do vértice
  *
  * @retval int: identificador numérico do vértice
  */
int vertice_get_id(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_obter_id: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->id;
}

// Retorna Key do vértice
int vertice_get_key(vertice_t* vert){
	if (vert == NULL){
		perror("vertice_get_key: vertice invalido");
		exit(-1);
	}
	return vert->key;
}

void vertice_set_pai(vertice_t *vertice, vertice_t *pai) {

	if (vertice == NULL){
		fprintf(stderr, "vertice_set_pai: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	vertice->pai = pai;
}

void vertice_set_dir(vertice_t* vert, vertice_t* dir){
	if (vert == NULL){
		perror("vertice_set_dir: Vertice invalido");
		exit(EXIT_FAILURE);
	}

	vert->dir = dir;
}
// Define valor da variável 'key' no vértice
void vertice_set_key(vertice_t* vert, int key){
	if (vert == NULL){
		perror("vertice_set_key: Vertice invalido");
		exit(-1);
	}

	vert->key = key;
}
// Define que vértice está a esquerda do vértice
void vertice_set_esq(vertice_t* vert, vertice_t* esq){
	if (vert == NULL){
		perror("vertice_set_esq: Vertice invalido");
		exit(EXIT_FAILURE);
	}

	vert->esq = esq;
}
// Retorna pai do vértice
vertice_t* vertice_get_pai(vertice_t *vertice){
	if (vertice == NULL){
		fprintf(stderr, "vertice_get_pai: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	return vertice->pai;
}
// Retorna vértice a direita do vértice
vertice_t* vertice_get_dir(vertice_t *vertice){
	if (vertice == NULL){
		perror("vertice_get_dir: Vertice invalido");
		exit(-1);
	}
	return vertice->dir;
}
// Retorna vértice a esquerda do vértice
vertice_t* vertice_get_esq(vertice_t *vertice){
	if (vertice == NULL){
		perror("vertice_get_esq: Vertice invalido");
		exit(-1);
	}
	return vertice->esq;
}
// Retorna ID do pai do vértice
int vertice_get_pai_id(vertice_t *vertice){
	if (vertice == NULL){
		fprintf(stderr, "vertice_get_pai_id: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	return (vertice->pai)->id;
}

// Retorna se o vértice foi visitado
int vertice_get_dist(vertice_t* vertice){
	if (vertice == NULL){
		fprintf(stderr, "vertice_get_dist: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	int dist = vertice->distancia;

	return dist;
}