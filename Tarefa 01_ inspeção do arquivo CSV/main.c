/** Programa exemplo que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *
  *         Cabeçalho
  *         Pos        ,Nome    ,Ouro       ,Prata      ,Bronze     ,Total
  *         <short int>,<string>,<short int>,<short int>,<short int>,<short int>
  *         <short int>,<string>,<short int>,<short int>,<short int>,<short int>
  *
  * O programa lê o arquivo <winterGames.csv> formatado conforme o cabeçalho acima e os
  *apresenta em forma de tabela para melhor organização na saída(ignorando a primeira linha).
  *
  * Para melhor uso de memória, foi utilizado short int, uma vez que nenhum
  *dos dados pode passar de (2^16)-1.
  *
  * O programa não é capaz de armazenar os dados propriamente, somente os apresenta assim que
  *os lê, desta forma não é nescessário criar um vetor.
  * Isso faz com que caso for nescessário manipular os dados, será possível fazer isso somente
  *dentro do loop em que lê os dados, foi feito isso para salvar um pouco de memória já que
  *seria nescessário vários vetores para armazenar tudo que seria possível com uma tabela deste tipo
  *(um para cada paíz)
  */

/********************************
 *Nome: Emanuel S. Araldi       *
 *Data: 01/06/20                *
 ********************************/

#include <stdio.h>  /* Para fgets, fscanf, ... */
#include <stdlib.h> /* Para exit, malloc, ... */

int main(){
    char linha[128];

    short int posicao;      /*!< Posição: short int */
    char nome[50];              /*!< Nomes */
    short int ouro,         /*!< short int usa um pouco menos memória */
    prata, bronze, total;   /*!< Medalhas */

    FILE *fp = fopen("winterGames.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

     /* Ignora primeira linha */
    fgets(linha,128, fp);
    printf("Ignorando: %s\n\n", linha);

    /** Cabeçalho **/
    printf("=====================================================================\n");
    printf(" Pos\t\t  Nome  \t\t Ouro\tPrata\tBronze\tTotal\n");
    printf("=====================================================================\n");

    /* Imprima os dados:*/

      /** Lê todas as variáveis e confirma que todas as 6 foram lidas propriamente **/
    while (fscanf(fp, "%hd,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, &nome, &ouro,
                  &prata, &bronze, &total) == 6){
        printf("|%03hd| %-35s |%02hd|\t |%02hd|\t |%02hd|\t |%02hd|\t\n", posicao, nome, ouro,
                  prata, bronze, total);
        printf("---------------------------------------------------------------------\n");
                  }

    fclose(fp);
}
