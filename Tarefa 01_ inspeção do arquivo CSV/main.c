/** Programa exemplo que exibe na tela dados formatados
  * de um arquivo CSV conforme o padr�o:
  *
  *         Cabe�alho
  *         Pos        ,Nome    ,Ouro       ,Prata      ,Bronze     ,Total
  *         <short int>,<string>,<short int>,<short int>,<short int>,<short int>
  *         <short int>,<string>,<short int>,<short int>,<short int>,<short int>
  *
  * O programa l� o arquivo <winterGames.csv> formatado conforme o cabe�alho acima e os
  *apresenta em forma de tabela para melhor organiza��o na sa�da(ignorando a primeira linha).
  *
  * Para melhor uso de mem�ria, foi utilizado short int, uma vez que nenhum
  *dos dados pode passar de (2^16)-1.
  *
  * O programa n�o � capaz de armazenar os dados propriamente, somente os apresenta assim que
  *os l�, desta forma n�o � nescess�rio criar um vetor.
  * Isso faz com que caso for nescess�rio manipular os dados, ser� poss�vel fazer isso somente
  *dentro do loop em que l� os dados, foi feito isso para salvar um pouco de mem�ria j� que
  *seria nescess�rio v�rios vetores para armazenar tudo que seria poss�vel com uma tabela deste tipo
  *(um para cada pa�z)
  */

/********************************
 *Nome: Emanuel S. Araldi       *
 *Data: 01/06/20                *
 ********************************/

#include <stdio.h>  /* Para fgets, fscanf, ... */
#include <stdlib.h> /* Para exit, malloc, ... */

int main(){
    char linha[128];

    short int posicao;      /*!< Posi��o: short int */
    char nome[50];              /*!< Nomes */
    short int ouro,         /*!< short int usa um pouco menos mem�ria */
    prata, bronze, total;   /*!< Medalhas */

    FILE *fp = fopen("winterGames.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

     /* Ignora primeira linha */
    fgets(linha,128, fp);
    printf("Ignorando: %s\n\n", linha);

    /** Cabe�alho **/
    printf("=====================================================================\n");
    printf(" Pos\t\t  Nome  \t\t Ouro\tPrata\tBronze\tTotal\n");
    printf("=====================================================================\n");

    /* Imprima os dados:*/

      /** L� todas as vari�veis e confirma que todas as 6 foram lidas propriamente **/
    while (fscanf(fp, "%hd,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, &nome, &ouro,
                  &prata, &bronze, &total) == 6){
        printf("|%03hd| %-35s |%02hd|\t |%02hd|\t |%02hd|\t |%02hd|\t\n", posicao, nome, ouro,
                  prata, bronze, total);
        printf("---------------------------------------------------------------------\n");
                  }

    fclose(fp);
}
