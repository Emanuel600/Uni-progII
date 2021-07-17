/** Lê um arquivo CSV contendo
 * informações sobre as adjacências
 * de um grafo no formato:
 * u			,v			 ,<short int>	/!< vértice, vértice, num_vértices  /
 * <short int>	, <short int>				/!< vértice, vértice  				/
 * <short int>	, <short int>				/!< vértice, vértice  				/
 * ...
 *  E performa uma busca de largura
 * ou profundiade
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
// Includes do módulo
#include "pilha.h"
#include "grafo.h"
#include "fila.h"

int main(void) {

	grafo_t *grafo = ler_csv_nd("grafo.txt");
	vertice_t* vertice = procurar_vertice(grafo, 1);
	// Perfoma busca larga
	bfs(grafo, vertice);
	print_larga(grafo);
	// Performa busca profunda
	dfs(grafo, vertice);
	print_prof(grafo);

	exportar_grafo_dot("grafo.dot", grafo);

	liberar_grafo(grafo);

	return EXIT_SUCCESS;
}

