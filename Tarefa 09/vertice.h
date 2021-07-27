/** Declara as funções utilizadas para
 * manipulação e criação de vértices
 **/

#ifndef GRAFO_VERTICE_H_
#define GRAFO_VERTICE_H_

#include "lista_enc.h"

/* Exporta os tipos de dados do vertice e arestas */
typedef struct vertices vertice_t;
typedef struct arestas arestas_t;

/* Tipo enum o status das arestas: utilizado para exportação do DOT */
typedef enum status_aresta { VAZIO, EXPORTADA } status_aresta_t;

/* Cria um novo vertice com id */
vertice_t *criar_vertice(int id);

/* Cria uma nova aresta */
arestas_t *criar_aresta(vertice_t *fonte, vertice_t *destino, int peso);

/* Obtem id de um vertice */
int vertice_get_id(vertice_t *vertice);

/* Adiciona uma aresta a um grafo */
void adicionar_aresta(vertice_t *vertice, arestas_t *aresta);

/* Obtem a lista encadeada das arestas */
lista_enc_t *vertice_get_arestas(vertice_t *vertice);

/* Retorna o peso de um aresta */
int aresta_get_peso (arestas_t *aresta);

/* Obtem o destinho de uma aresta */
vertice_t *aresta_get_adjacente(arestas_t *aresta);

/* Retorna uma aresta caso seja fonte ou destino */
arestas_t *procurar_adjacente(vertice_t *vertice, vertice_t *adjacente);

/* Configura status de uma aresta */
void aresta_set_status(arestas_t *aresta, status_aresta_t status);

/* Obtem o status de uma aresta */
status_aresta_t aresta_get_status (arestas_t *aresta);

/* Define o valor de uma variável do vértice */
// Pai
void vertice_set_pai(vertice_t *vertice, vertice_t *pai);
// Visitado
void vertice_set_visi(vertice_t* vertice, int visi);
// Distância
void vertice_set_dist(vertice_t *vertice, int dist);
// Direita
void vertice_set_dir(vertice_t *vertice, vertice_t* dir);
// Esquerda
void vertice_set_esq(vertice_t *vertice, vertice_t* esq);
// Key
void vertice_set_key(vertice_t* vertice, int key);

/* Retorna uma variável do vértice */
// Pai
vertice_t* vertice_get_pai(vertice_t *vertice);
// Esquerda
vertice_t* vertice_get_esq(vertice_t *vertice);
// Direita
vertice_t* vertice_get_dir(vertice_t *vertice);
// Id do pai
int vertice_get_pai_id(vertice_t *vertice);
// Distância
int vertice_get_dist(vertice_t *vertice);
// Visitado
int vertice_get_visi(vertice_t* vertice);
// Key
int vertice_get_key(vertice_t* vert);

// Liberar vértices
void liberar_vertices(lista_enc_t* lista);
// Libera um vértice
void libera_vertice(vertice_t* vertice);

#endif /* GRAFO_VERTICE_H_ */
