/** Declara as funções utilizadas para
 * manipulação e criação de árvores
 **/
//Guarda
#ifndef SRC_ARVORE_ARVORE_H_
#define SRC_ARVORE_ARVORE_H_
// Include do módulo
#include "vertice.h"

typedef struct arvores arvore_t;
// Cria uma árvore vazia genérica
arvore_t* cria_arvore(int id);
// Lê um CSV formatado
arvore_t* ler_csv_arv(char* arq);
// Adiciona vértice a partir de um id
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id);
// Adiciona o vértice passado como parâmetro
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice);
// Retorna a raíz de uma árvore qualquer
vertice_t* arvore_get_raiz (arvore_t *arvore);
// Procura um vértice por seu id
vertice_t* arvore_procura_vertice(arvore_t *arvore, int id);
// Retorna lista de vértices da árvore
lista_enc_t *arvore_obter_vertices (arvore_t *arvore);
// Insere um vértice na árvore, seguindo a regra de maiores à direita, menores à esquerda
vertice_t* arvore_inserir(int id, vertice_t* vert, int key);
// Função auxiliar de busca, chama a função que realmente performa a busca
vertice_t* chamar_busca(arvore_t* arv, int key);
// Performa a busca de forma recursiva, retornando um vértice com a chave especificada, se este existe
vertice_t* arvore_busca_chave(vertice_t* vert, int key);
//Não funciona
void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore);
// Adiciona filhos à um vértice pai
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir);
// Define vértice passado como raíz da árvore especificada
void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice);
// Libera a árvore da memória
void liberar_arvore(arvore_t *arvore);
// Libera os filhos do vértice da memória (libera TODOS os filhos, até as folhas)
void libera_filhos(vertice_t* vertice);


#endif /* SRC_ARVORE_ARVORE_H_ */
