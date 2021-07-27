/* Lê um arquivo CSV contendo
 *um par ordenado <id,chave>
 *
 * Organizado tal que:
 *<char>,   <char>      <= Chars a serem ignorados
 *<int> ,   <int>       <= id da raíz(0) e chave da mesma
 *<int> ,   <int>       <= id de um vértice qualquer e sua chave
 *...                   <= Continua indefinidamente seguindo o mesmo formato
 *
 * E organiza os dados tal que
 *chaves maiores são encaminhadas
 *à "direita" e menores à "esquerda",
 *criando uma "árvore" com várias "sub-árvores"
 *
 * Finalmente, performa uma busca para
 *encontrar um vértice com chave qualquer
 */
// Includes do Sistema
#include <stdio.h>
// Includes do módulo
#include "arvore.h"
#include "vertice.h"

int main(){
    // Ler CSV
	arvore_t* arv = ler_csv_arv("grafo.txt");
	// Buscar vértice com uma chave específica
	chamar_busca(arv, 64);
	// Liberar dados da memória
	liberar_arvore(arv);
	return 0;
}
