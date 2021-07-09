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
#include "grafo.h"

int main(void) {
	grafo_t *g;

	g = ler_csv_nd("adjacencia_nd.txt");

	/* Imprime matriz */
	print_matrix(g);

	busca_larga(g,0);
	busca_prof(g,0);

	/* Libera dados do grafo */
	libera_grafo(g);

	return EXIT_SUCCESS;
}
