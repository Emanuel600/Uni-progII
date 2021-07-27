/** Parte do programa que contém as funções
 * de criação e manipulação de árvores.
 *
 * Define a estrutura das árvores e a
 *criação/manipulação delas, além da
 *busca por um elemento com uma chave
 *qualquer dentro delas.
 */
// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
// Includes do módulo
#include "lista_enc.h"
#include "vertice.h"
#include "arvore.h"

#define FALSE 0
#define TRUE 1

#define DEBUG

struct arvores {
	int id;                /*!< Identificação numérica da árvore 		*/
	vertice_t *raiz;       /*!< Ponteiro para o vértice raiz  			*/
	lista_enc_t *vertices; /*!< Lista encadeada de vértices  			*/
};

/**
  * @brief  Cria uma árvore. Grau depende do vértice.
  * @param	id: identificação numérica da árvore.
  *
  * @retval arvore_t: ponteiro para uma nova árvore.
  */
arvore_t *cria_arvore(int id)
{
	arvore_t *p = NULL;

	p = (arvore_t*) malloc(sizeof(arvore_t));

	if (p == NULL)	{
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->vertices = cria_lista_enc();

	return p;
}
// Ler CSV contendo informações para criar uma árvore
arvore_t* ler_csv_arv(char* arq){
	FILE* fp = fopen(arq,"r");
	arvore_t* arv = cria_arvore(0);

	if (fp == NULL){
		perror("Erro ao abrir CSV");
		exit(-1);
	}

	char ign;
	fscanf(fp,"%c,%c", &ign, &ign);

	int id, key;

	while (fscanf(fp, "%d,%d", &id, &key) == 2){
		vertice_t* v1 = arvore_get_raiz(arv);

		v1 = arvore_inserir(id, v1, key);
		arvore_adicionar_vertice(arv, v1);
	}

	fclose(fp);
	return arv;
}
// Inserir vértices
vertice_t* arvore_inserir(int id, vertice_t* vert, int key){
	if (vert == NULL){
		vert = criar_vertice(id);
		vertice_set_key(vert, key);
	}

	else if (key < vertice_get_key(vert)){
		vertice_set_esq(vert, arvore_inserir(id, vertice_get_esq(vert), key));
		
		vertice_t* esq = vertice_get_esq(vert);
		vertice_set_pai(esq, vert);
		#ifdef DEBUG
		printf("Pai:[%02d] > Filho:[%02d]\n", vertice_get_id(vert), vertice_get_id(esq));
		#endif
	}
	else{ // key >= vert->key
		vertice_set_dir(vert, arvore_inserir(id, vertice_get_dir(vert), key));
		
		vertice_t* dir = vertice_get_dir(vert);
		vertice_set_pai(dir, vert);
		#ifdef DEBUG
		printf("Pai:[%02d] < Filho:[%02d]\n", vertice_get_id(vert), vertice_get_id(dir));
		#endif
	}
	
	return vert;
}

/**
  * @brief  Adiciona um vértice na árvore. Essa função cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificação numérica do vértice.
  *
  * @retval vertice_t: ponteiro do novo vértice criado e adicionado na árvore.
  */
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id)
{
	vertice_t *vertice;
	no_t *no;

	if (arvore == NULL)	{
			fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
			exit(EXIT_FAILURE);
	}

	if (arvore_procura_vertice(arvore, id) != NULL) {
		fprintf(stderr,"grafo_adicionar_vertice: vertice duplicado!\n");
		exit(EXIT_FAILURE);
	}

	vertice = criar_vertice(id);
	no = criar_no(vertice);

	add_cauda(arvore->vertices, no);

	return vertice;
}

/**
  * @brief  Adiciona um vértice criado na árvore. Essa função NÃO cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	vertice: ponteiro válido de um vértice.
  *
  * @retval vertice_t: ponteiro do vértice adicionado na árvore.
  */
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice){
	no_t *no;

	if (arvore == NULL)	{
			fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
			exit(EXIT_FAILURE);
	}

	no = criar_no(vertice);

	add_cauda(arvore->vertices, no);

	if (vertice_get_id(vertice) == 0)
		arvore_set_raiz(arvore, vertice);

	return vertice;
}

/**
  * @brief  Procura um vértice com identificador específico na árvore.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificador do vértice procurado.
  *
  * @retval vertice_t: NULL se vértice não pertencer a árvore. Um um ponteiro válido caso contrário.
  */
vertice_t* arvore_procura_vertice(arvore_t *arvore, int id)
{
	no_t *no_lista;
	vertice_t *vertice;
	int meu_id;

	if (arvore == NULL)	{
		fprintf(stderr,"procura_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(arvore->vertices) == TRUE)
		return NULL;

	no_lista = obter_cabeca(arvore->vertices);

	while (no_lista)
	{
		//obtem o endereco da lista
		vertice = obter_dado(no_lista);

		//obterm o id do vertice
		meu_id = vertice_get_id(vertice);

		if (meu_id == id) {
			return vertice;
		}

		no_lista = obter_proximo(no_lista);
	}

	return NULL;
}

/**
  * @brief  Configura os filhos de um vértices PERTENCENTES à um árvore por identificador.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  vertice: ponteiro de um vértice à ser configurado.
  * @param	esq: identificador numérico do vértice à esquerda.
  * @param	dir: identificador numérico do vértice à direita.
  *
  * @retval Nenhum
  */
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir)
{
	vertice_t *esquerda;
	vertice_t *direita;

	if (arvore == NULL)	{
		fprintf(stderr,"arvore_adiciona_filhos: arvore invalida!");
		exit(EXIT_FAILURE);
	}

	if (esq != -1){
		esquerda = arvore_procura_vertice(arvore, esq);
		vertice_set_pai(esquerda, vertice);
		vertice_set_esq(vertice, esquerda);
	}

	if (dir != -1){
		direita = arvore_procura_vertice(arvore, dir);
		vertice_set_pai(direita, vertice);
		vertice_set_dir(vertice, direita);
	}
}

/**
  * @brief  Exporta em formato DOT uma árvore.
  * @param  filename: nome do arquivo DOT gerado.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  */
void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore)
{






}

/**
  * @brief  Libera memória dinâmica de uma uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  *//*
void libera_arvore(arvore_t* arvore){
    //liberar_vertices(arvore_obter_vertices(arvore));
    free(arvore);
}
*/
/**
  * @brief  Configura a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  vertice: ponteiro válido de um vértice
  *
  * @retval Nenhum
  */
void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice){
	if (arvore == NULL){
			fprintf(stderr, "libera_set_raiz: arvore invalida\n");
			exit(EXIT_FAILURE);
	}

	arvore->raiz = vertice;

}

/**
  * @brief  Obtém a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval vertice_t: ponteiro do vértice raiz.
  */
vertice_t* arvore_get_raiz (arvore_t *arvore){
	if (arvore == NULL){
			fprintf(stderr, "arvore_get_raiz: arvore invalida\n");
			exit(EXIT_FAILURE);
	}

	return arvore->raiz;
}

/**
  * @brief  Obtém a lista encadeada de vértices.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval lista_enc_t: ponteiro da lista encadeada contendo todos os vértices da árvore.
  */
lista_enc_t *arvore_obter_vertices (arvore_t *arvore){
	if (arvore == NULL){
		fprintf(stderr, "arvore_obter_vertices: arvore invalida\n");
		exit(EXIT_FAILURE);
	}


	return arvore->vertices;
}
// Função auxiliar de busca, chama a função que realmente performa a busca
vertice_t* chamar_busca(arvore_t* arv, int key){
	vertice_t* vert = arvore_get_raiz(arv);
	return arvore_busca_chave(vert, key);
}
// Busca por um vértice de determinada chave e o retorna, se ele existe
vertice_t* arvore_busca_chave(vertice_t* vert, int key){
#ifdef DEBUG
	printf("arvore_busca_chave\n");
#endif
	if (vert == NULL){
	    printf("Vertice com chave |%03d| nao existe\n", key);
		return NULL;
	}
	else if (vertice_get_key(vert) > key)
		return arvore_busca_chave(vertice_get_esq(vert), key);
	else if (vertice_get_key(vert) < key)
		return arvore_busca_chave(vertice_get_dir(vert), key);
	else{
	    printf("vertice [%02d] com chave |%03d| encontrado\n", vertice_get_id(vert), key);
		return vert;
	}
}
// Libera a árvore da memória
void liberar_arvore(arvore_t* arv){
    no_t *no = obter_cabeca(arv->vertices);
	vertice_t* raiz= arvore_get_raiz(arv);
	no_t* prox = NULL;
	
	int i = 0;

	if (arv == NULL)	{
		fprintf(stderr,"liberar_arvore: arvore invalida!");
		exit(EXIT_FAILURE);
	}

	while (no){
		prox = obter_proximo(no);
		
		free(no);
		no = prox;
	}
	
	libera_filhos(raiz);
	
	free(arv->vertices);
	free(arv);
}
// Libera TODOS os filhos da árvore(indo até as folhas)
void libera_filhos(vertice_t* vert){
    vertice_t* dir;
    vertice_t* esq;
    
    if (vert == NULL){
	    perror("libera_filhos: Vertice inexistente");
		exit(-1);
	}
	if (vertice_get_dir(vert)){
		dir = vertice_get_dir(vert);
	    #ifdef DEBUG
	    printf("Eliminando (dir) vertice [%02d]\n", vertice_get_id(dir));
	    #endif
		libera_filhos(dir);
		    free(dir);
	}
	if (vertice_get_esq(vert)){
		esq = vertice_get_esq(vert);
	    #ifdef DEBUG
	    printf("Eliminando (esq) vertice [%02d]\n", vertice_get_id(esq));
	    #endif
	    libera_filhos(esq);
		free(esq);
	}
	if (vertice_get_pai(vert) == NULL)
	    free(vert);
}