/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  * 
  * Pos  , nome    , ouro       , prata      , bronze     , total
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * <int>, <string>, <short int>, <short int>, <short int>, <short int>
  * (...)
  *
  * Utiliza uma lista encadeada  para armazenar
  *os dados em nós e imprime os valores na tela
  *em forma de tabela
  *
  */

#include "dados.h"      /*!< ler_dados_csv                   */
#include "lista_enc.h"  /*!< Manipulação e leitura de listas */


int main(){
    /* Ler os dados:      */
    lista_t *lista = ler_dados_csv("winterGames.csv");

    /* Imprimir os dados: */
    print(lista);
    /* Liberar os dados:  */
    liberar_dados(lista);

    return 0;
}
