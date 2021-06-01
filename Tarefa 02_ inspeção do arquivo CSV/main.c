/** Programa exemplo que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *
  *         Cabeçalho
  *         Pos  ,Nome    ,Ouro       ,Prata      ,Bronze     ,Total
  *         <int>,<string>,<short int>,<short int>,<short int>,<short int>
  *         <int>,<string>,<short int>,<short int>,<short int>,<short int>
  *
  * O programa lê o arquivo <winterGames.csv> formatado conforme o cabeçalho acima e os
  *apresenta em forma de tabela para melhor organização na saída(ignorando a primeira linha).
  *
  * Para melhor uso de memória, foi utilizado short int, uma vez que nenhum
  *dos dados pode passar de (2^16)-1.
  * Para melhor alocação de memória, malloc foi utilizado para alocar somente
  *o nescessário para o processo, sendo a memória que a struct ocupa.
  */

/********************************
 *Nome: Emanuel S. Araldi       *
 *Data: 31/05/20                *
 ********************************/

#include <stdio.h>  /* Para fgets, fscanf, ... */
#include <stdlib.h> /* Para exit, malloc, ... */

struct dados {
    int posicao;            /*!< Posição: int */
    char nome[64];          /*!< Nome */
    short int ouro,         /*!< short int usa um pouco menos memória */
    prata, bronze, total;   /*!< Medalhas */
};

int main(){
    int i;
    int n_linhas  = 0;
    char info[64];

    /* Ponteiro para alocação dinâmica dos dados */
    struct dados *dados = NULL;

    FILE *fp = fopen("winterGames.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(info,64, fp);

    /* Contar todas as linhas: use while e fgets() */
    while ( fgets(info,100, fp ) ){
        n_linhas++; //Lembrando que a primeira linha foi ignorada
    }

    /* Aloque memória: */
    dados = malloc(sizeof(struct dados) * n_linhas);

    if (dados == NULL){
    	perror("main");
    	exit(EXIT_FAILURE);
    }

    rewind(fp);
     /* Ignora primeira linha */
    fgets(info,64, fp);

     struct dados linha[n_linhas];
         /** Lê todas as variáveis e confirma que todas as 6 foram lidas propriamente **/
    while (fscanf(fp, "%d,%50[^,],%hd,%hd,%hd,%hd\n",&dados[i].posicao, &dados[i].nome, &dados[i].ouro,
                  &dados[i].prata, &dados[i].bronze, &dados[i].total) == 6) i++; //Contador

    /* Imprima os dados:*/

    /** Cabeçalho **/
    printf("=====================================================================\n");
    printf(" Pos\t\t  Nome  \t\t Ouro\tPrata\tBronze\tTotal\n");
    printf("=====================================================================\n");

    for (i=0; i < n_linhas; i++){
        /**  Formata os dados em forma de tabela **/
        printf("|%03d| %-35s |%02hd|\t |%02hd|\t |%02hd|\t |%02hd|\t\n", dados[i].posicao, dados[i].nome, dados[i].ouro,
                dados[i].prata, dados[i].bronze, dados[i].total);
        printf("---------------------------------------------------------------------\n");
    }

    free(dados);
    fclose(fp);
}
