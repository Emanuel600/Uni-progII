/** Parte do programa que cont�m as fun��es
 * de cria��o e manipula��o de grafos.
 *
 * Define a estrutura dos grafos e as
 *buscas de largura e profundidade.
 */

#define DEBUG

#define INFINITO 9999

// Includes do sistema
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Include do m�dulo
#include "grafo.h"
#include "fila.h"

struct vertices {
	int id;         		/*!< Identifica��o num�rica do v�rtice		*/
	
    /* Mais informa��es, se necess�rio */
	int distancia;			/*!< Dist�ncia at� a fonte					*/
	vertice_t* pai;			/*!< V�rtice pai							*/

	int visitado;			/*!<Booleano,1  se o v�rtice j� foi visitado*/
};

struct arestas {
	int adj;       			/*!< Valor booleando. Verdadeiro representa uma adjac�ncia entre dois v�rtices  */
	
    /* Mais informa��es, se necess�rio */
};

struct grafos{
	int n_vertices;        	/*!< N�mero de v�rtices do grafo  	*/
	vertice_t *vertices;   	/*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjac�ncia: conjunto E */
};

/**
  * @brief  Cria uma novo grafo est�tico
  * @param	vertices: quantidade de v�rtices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda n�mero total de v�rtices */
	g->n_vertices = vertices;
    /* Aloca v�rtices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de v�rtices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));
    
    
    /* Inicializa ID */
    for ( i = 0; i < vertices; i++ ){
        g->vertices[i].id = i;
    }    

    /* Aloca 1a dimens�o da matriz de adjac�ncia */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimens�o da matriz de adjac�ncia */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a mem�ria utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

// Cria adjac�ncia de u->v e de v->u
int cria_adjacencia_nd(grafo_t *g, int u, int v){
	int ret = 0;
	ret += cria_adjacencia(g,u,v);
	ret += cria_adjacencia(g,v,u);
	return (ret==2);
}

/**
  * @brief  Remove adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

void print_matrix(grafo_t* g){
	#ifdef DEBUG
		printf("============================\n");
		printf("Imprimindo matriz adjac�ncia\n");
		printf("============================\n");
	#endif
	int i, j;
	printf("\t");
	// Imprime cabe�alho
	for (j=0; j< g->n_vertices; j++)
		printf("%d\t", j+1);
	// Imprime adjac�ncia
	for (i=0; i < g->n_vertices; i++){
		printf("\n%d\t", i+1);
		for (j=0; j < g->n_vertices; j++)
			printf("%d\t", adjacente(g,i,j));
	}
	printf("\n");
}

//Imprime em formato csv
void print_csv(grafo_t* g){
	#ifdef DEBUG
		printf("============================\n");
		printf("Imprimindo CSV\n");
		printf("============================\n");
	#endif
	int i, j;
	// Imprime cabe�alho
	for (j=0; j< g->n_vertices; j++)
		if (j< (g->n_vertices)-1)
			printf("%d,", j+1);
		else
			printf("%d\n", j+1);
	// Imprime adjac�ncia
	for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			if (j< (g->n_vertices)-1)
				printf("%d,", adjacente(g,i,j));
			else
				printf("%d\n", adjacente(g,i,j));
		}
	}
	printf("\n");
}

/* Fun��es de busca */
// Largura
void busca_larga(grafo_t* g, int fonte){
	#ifdef DEBUG
		printf("============================\n");
		printf("Fazendo busca larga\n");
		printf("============================\n");
	#endif
	int i;
	fila_t* fila = cria_fila();

	for (i=0; i< g->n_vertices; i++){
		g->vertices[i].distancia = INFINITO;
		g->vertices[i].pai = NULL;
	}

	g->vertices[fonte].distancia = 0;
	enqueue(&g->vertices[fonte], fila);

	while(!fila_vazia(fila)){
		vertice_t* vert = dequeue(fila);

		int v;
		int id = vert->id;

		for (v=0; v< g->n_vertices; v++){

			if (adjacente(g, id, v)){
				#ifdef DEBUG
					printf("[%d]->[%d]:\t", id, v);
				#endif
			    if( g->vertices[v].distancia == INFINITO){
				    g->vertices[v].distancia = vert->distancia + 1;
				    g->vertices[v].pai = vert;
				    enqueue(&g->vertices[v], fila);

				    #ifdef DEBUG //Imprime informa��es sobre o pai do n� e dist�ncia at� a fonte
				    	//Dist�ncia
				    	printf("L%d->L%d | ", g->vertices[v].distancia,
				    			 g->vertices[v].distancia+1);
				    	//Pai
				    	vertice_t* temp = g->vertices[id].pai;
				    	if (temp != NULL) printf("Pai:%d\n", temp->id);
				    	else printf("Fonte\n"); // Se o n� pai � nulo, estamos avaliando o n� fonte
				    #endif
			    }
			#ifdef DEBUG
			    else printf("Nenhuma conexao nova\n");
			#endif
			}
		}
	}
}
// Profundidade
void busca_prof(grafo_t* g, int fonte){
	#ifdef DEBUG
		printf("============================\n");
		printf("Fazendo busca profunda\n");
		printf("============================\n");
	#endif
	int i;
	fila_t* fila = cria_fila();

	for (i=0; i< g->n_vertices; i++)
		g->vertices[i].visitado = FALSE;

	enqueue(&g->vertices[fonte], fila);

	while(!fila_vazia(fila)){
		vertice_t* vert = dequeue(fila);

		int v;
		int id = vert->id;

		if (vert->visitado == FALSE){
			vert->visitado = TRUE;

			for (v=0; v< g->n_vertices; v++){

				if (adjacente(g, id, v)){
					#ifdef DEBUG
						// Confirma que houve conex�o entre id e v
						printf("[%d]->[%d]:\t", id, v);
					#endif
						if( g->vertices[v].visitado == FALSE){
							enqueue(&g->vertices[v], fila);

							#ifdef DEBUG
								// Confirma que v foi visitado
								printf("vertice %d foi visitado\n", v);
							#endif
						}
				#ifdef DEBUG
						else printf("Nenhuma conexao nova\n");
				#endif
				}
			}
		}
	}
}

/* Conjunto de fun��es para ler arquivo CSV */
// Cria grafo n�o direcional
grafo_t* ler_csv_nd(char* nome){
	short int u, v; 				/*!< Identifica��o num�rica do v�rtice  */
	short int num;					/*!< N�mero de v�rtices do grafo  */
	char ign;						/*!< Char a ser ignorada  */
	FILE* fp = fopen(nome, "r");

	if(!fp){
		perror("Erro ao abrir o arquivo");
		exit(-1);
	}

	fscanf(fp, "%c,%c,%hd", &ign, &ign, &num);
	grafo_t* g = cria_grafo(num);

	while ( fscanf( fp, "%hd,%hd", &u, &v ) == 2 ){
		cria_adjacencia_nd(g, u, v);
	}

	fclose(fp);
	return g;
}
// Cria grafo direcional
grafo_t* ler_csv(char* nome){
	short int u, v; 				/*!< Identifica��o num�rica do v�rtice  */
	short int num;					/*!< N�mero de v�rtices do grafo  */
	char ign;						/*!< Char a ser ignorada  */
	FILE* fp = fopen(nome, "r");

	if(!fp){
		perror("Erro ao abrir o arquivo");
		exit(-1);
	}

	fscanf(fp, "%c,%c,%hd", &ign, &ign, &num);
	grafo_t* g = cria_grafo(num);

	while ( fscanf( fp, "%hd,%hd", &u, &v ) == 2 ){
		cria_adjacencia(g, u, v);
	}

	fclose(fp);
	return g;
}
