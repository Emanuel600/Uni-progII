/** Programa que exibe na tela dados formatados
  *de um arquivo CSV conforme o padrão:
  *
  *  Pos  , nome    , ouro       , prata     , bronze    , total
  *  <int>, <string>, <short int>,<short int>,<short int>,<short int>
  *  <int>, <string>, <short int>,<short int>,<short int>,<short int>
  *  (...)
  *
  * Os dados são armazenados em um vetor de estruturas, utializando dados
  *abstratos e alocando somente a memória nescessária para aquele vetor de
  *estruturas.
  *
  * Lê o arquivo winterGames.csv e imprime os dados na tela em formato de tabela
  *
  */

/********************************
 *Nome: Emanuel S. Araldi       *
 *Data: 01/06/20                *
 ********************************/

#include <stdio.h>
#include "dados.h"

int main(){
    int n_linhas = 0;

    dado_t **dados = ler_dados_csv("winterGames.csv", &n_linhas);

    /* Imprima os dados:*/
    imprimir(dados, n_linhas);

    liberar_dados(dados, n_linhas);
}
