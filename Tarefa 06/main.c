/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  * 
  * Pos  , nome    , ouro       , prata      , bronze     , total
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * (...)
  *
  * Utiliza uma fila  para armazenaros dados
  *em nós e imprime os valores na tela
  *em forma de tabela
  *
  **/
  
// Includes do módulo
#include "dados.h"
#include "fila.h"


int main(){
	// Ler dados
    fila_t *fila = ler_dados_csv_fila("winterGames.csv");
     
    /* Imprima os dados:*/
    imprime(fila);

    // Liberar os dados da fila
    libera_fila(fila);
    
    return 0;
}
