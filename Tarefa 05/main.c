/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  * 
  * Pos  , nome    , ouro       , prata      , bronze     , total
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * (...)
  *
  * Utiliza uma pilha  para armazenaros dados
  *em nós e imprime os valores na tela
  *em forma de tabela reversa
  *
  */
 
#include "pilha.h"
#include "dados.h"


int main(){
    // Ler os dados em formato de pilha
    pilha_t *pilha = ler_dados_csv_pilha("winterGames.csv");
     
    /* Imprima os dados:*/
    //imprime(pilha);

    /* Libera os dados */
    liberar_dados(pilha);
    
    return 0;
}