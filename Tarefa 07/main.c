/** L� um arquivo CSV contendo
 * informa��es sobre as adjac�ncias
 * de um grafo no formato:
 * u			,v			 ,<short int>	/!< v�rtice, v�rtice, num_v�rtices  /
 * <short int>	, <short int>				/!< v�rtice, v�rtice  				/
 * <short int>	, <short int>				/!< v�rtice, v�rtice  				/
 * ...
 *  E performa uma busca de largura
 * ou profundiade
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
// Includes do m�dulo
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
