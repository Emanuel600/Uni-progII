/** Declara as funções utilizadas
 * para manipulação e criação de grafos
 **/

#ifndef GRAFO_GRAFO_H_
#define GRAFO_GRAFO_H_

#include "vertice.h"
#include "pilha.h"

typedef struct grafos grafo_t;

/* Cria um novo grafo com id */
grafo_t *criar_grafo(int id);

/* Adiciona um vertice ao grafo */
vertice_t* grafo_adicionar_vertice(grafo_t *grafo, int id);

/* Cria arestas:
 * grafo: grafo que pertence a aresta
 * vertice: ponteiro do vertice que se deseja adicionar arestas
 * n: numero total dos proximos parametros
 * proximos parametros: par ordenado composto por: <vert. destino> , <peso da aresta>
 * Ex: adicionar uma aresta para o vertice 2 e 3 com respectivos pesos 9 e 15
 * adiciona_adjacentes(grafo, vertice, 4, 2, 9, 3, 15);  */
void adicionar_adjacentes_ptr_peso(grafo_t *grafo, vertice_t *vertice, int n, ...);
void adicionar_adjacentes_id_peso(grafo_t *grafo, int vertice_id, int n, ...);
void adicionar_adjacentes_id(grafo_t *grafo, int vertice_id, int n, ...);
void adicionar_adjacentes_id_nd(grafo_t *grafo, int vertice_id, int n, ...);

/* Procura um vertice no grafo com id numerico */
vertice_t* procurar_vertice(grafo_t *grafo, int id);
// Lê um arquivo CSV que descreve um grafo e cria dito grafo
grafo_t* ler_csv_nd(char* arquivo);

/* Exporta o grafo utilizando a linguagem dot */
void exportar_grafo_dot(const char *filename, grafo_t *grafo);

/* Libera memoria utilizada pelo grafo */
void liberar_grafo (grafo_t *grafo);

/* Menor camingo entre todos os nos:
 * retorna um pilha do caminho entre fonte e destino  */
pilha_t* Dijkstra(grafo_t *grafo, vertice_t *fonte, vertice_t *destino);

/* Procura um vertice com menor a menor distancia
 * Ver: struct vertices */
no_t *busca_menos_distante(lista_enc_t *Q);

/* Retorna TRUE se vertice_procurado estiver no conjunto Q*/
int busca_vertice(lista_enc_t *lista, vertice_t *vertice_procurado);

lista_enc_t* componentes_conexos(grafo_t *grafo);

/* Funções de busca */
// Larga
void bfs(grafo_t *grafo, vertice_t* inicial);
// Profunda
void dfs(grafo_t *grafo, vertice_t* inicial);

/* Funções de display dos resultados das buscas */
// Larga
void print_larga(grafo_t* grafo);
// Profunda
void print_prof(grafo_t* grafo);

#endif /* GRAFO_GRAFO_H_ */
