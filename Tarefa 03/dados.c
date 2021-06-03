/* Módulo responsável por
 * stdio.h  => printf, fscanf, etc.
 * stdlib.h => perror, exit, etc.
 * string.h => strcpy
 * locale.h => setlocale;
 */


/* Includes de sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Includes do módulo */
#include "dados.h"


/* Ativa depuração do módulo, comente para código final */
#define DEBUG


struct dados {
    int posicao;
    char nome[40];
    short int ouro, prata,
    bronze, total;
};

/** Cria uma struct com os dados **/
dado_t *criar_dado (int posicao, char *nome, short int ouro, short int prata, short int bronze, short int total){

    dado_t * meu_novo_dado = malloc(sizeof(struct dados));

    if (meu_novo_dado == NULL){
        perror("Erro ao criar dado:");
        exit(EXIT_FAILURE);
    }


    /* Novos dados são copiados para nova estrutura vinda do malloc */
    strcpy(meu_novo_dado->nome, nome);
    meu_novo_dado->ouro = ouro;
    meu_novo_dado->prata = prata;
    meu_novo_dado->total = total;
    meu_novo_dado->bronze = bronze;
    meu_novo_dado->posicao = posicao;

    return meu_novo_dado;
}
/** Conta o número de linhas no arquivo **/
void determinar_linhas(char *nome_do_arquivo, int *total_dados){
    setlocale(LC_ALL, "");
    /** Abrir arquivo **/
    FILE *fp;
    fp = fopen(nome_do_arquivo, "r");
    if (fp == NULL){
        perror("Erro na função deter_linha: ");
        exit(EXIT_FAILURE);
    }

    unsigned int i = 0;
    char linha[128];

    fgets(linha, 128, fp);
    /** Contar quantia de linhas, ignorando a primeira **/
    while(fgets(linha, 128, fp) != NULL)i++;

    /** Fechar arquivo e retornar número de linhas **/
    fclose(fp);
    *total_dados = i;
}

/** Lê e armazena os dados em um vetor struct **/
dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados){
    setlocale(LC_ALL, "");
    /** Receber número de linhas e criar  struct meus_dados **/
    determinar_linhas(nome_do_arquivo, total_dados);
    /** Alocar memória nescessária para meus_dados **/
    dado_t **meus_dados = malloc(sizeof(dado_t*) * (*total_dados));
    if (meus_dados == NULL){
        perror("Erro na alocação para leitura");
        exit(EXIT_FAILURE);
    }

    /** Abrir arquivo **/
    FILE *fp;
    fp = fopen(nome_do_arquivo, "r");

    int posicao, i = 0;
    char nome[50], ign[128];
    short int ouro, prata,
    bronze, total;


    /** Ignora primeira linha **/
    fgets(ign, 128, fp);
    while (fscanf(fp, "%d,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, nome, &ouro,
                  &prata, &bronze, &total) == 6){
          meus_dados[i] = criar_dado(posicao, nome, ouro, prata, bronze, total);
          i++;
        }

    fclose(fp);

    return meus_dados;
}

/** Conjunto de funções que obtem dados **/
int obter_posicao(dado_t *dado){
    return dado->posicao;
}

char* obter_nome(dado_t* dado){
    return dado->nome;
}

short int obter_ouro(dado_t* dado){
    return dado->ouro;
}

short int obter_prata(dado_t* dado){
    return dado->prata;
}

short int obter_bronze(dado_t* dado){
    return dado->bronze;
}

short int obter_total(dado_t* dado){
    return dado->total;
}

/** Imprime os dados na tela em forma de tabela **/
void imprimir(dado_t **dados, int n_linhas){
    setlocale(LC_ALL, "");
    int i;
    /** Cabeçalho **/
    printf("=====================================================================\n");
    printf(" Pos\t\t  Nome  \t\t Ouro\tPrata\tBronze\tTotal\n");
    printf("=====================================================================\n");
    /** Formata em forma de tabela **/
    for (i=0; i < (n_linhas); i++){
        printf( "|%03d| ", obter_posicao( dados[i]) );
        printf( " %-35s ", obter_nome( dados[i]) );
        printf( "|%02hd|\t ", obter_ouro( dados[i]) );
        printf( "|%02hd|\t ", obter_prata( dados[i]) );
        printf( "|%02hd|\t ", obter_bronze( dados[i]) );
        printf( "|%02hd|\t\n", obter_total( dados[i]) );
        printf("---------------------------------------------------------------------\n");
    }
}

void liberar_dados(dado_t **vetor, int n_linhas){
    int i;
    for (i = 0; i<n_linhas; i++)free(vetor[i]);
    free(vetor);
}
