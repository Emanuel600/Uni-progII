/** Declara as funções utilizadas
 * para manipulação e criação de grafos
 **/

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0

// Definir estruturas de dados
typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

// Criar grafo com (n) vértices
grafo_t *cria_grafo(int vertices);
// Libera os dados contidos no grafo
void libera_grafo (grafo_t *g);

/** Funções para criar adjacência **/
// Define adjacência entre os nós como "verdadeira"(1) de u->v
int cria_adjacencia(grafo_t *g, int u, int v);
// Define adjacência entre nós como "verdadeira"(1) tanto de u->v como de v->u
int cria_adjacencia_nd(grafo_t *g, int u, int v);

// Define adjacência entre nós como "falsa"(0)
int rem_adjacencia(grafo_t *g, int u, int v);
// Retorna se os nós 'u' e 'v' são adjacentes
int adjacente(grafo_t *g, int u, int v);

// Imprime matriz de adjacência
void print_matrix(grafo_t* g);
// Imprime matriz de adjacência em forma de csv
void print_csv(grafo_t* g);

/* Funções de busca */
// Larga
void busca_larga(grafo_t* g, int fonte);
// Profunda
void busca_prof(grafo_t* g ,int fonte);

/* Conjunto de funções para ler arquivo CSV */
// Cria grafo não direcional
grafo_t* ler_csv_nd(char* nome);
// Cria grafo direcional
grafo_t* ler_csv(char* nome);

#endif /* GRAFO_H_ */
