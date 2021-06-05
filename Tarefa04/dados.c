/** Parte do programa que define as funções
 * de leitura e manipulação de dados
 * 
 * Define a estrutura de dados e define como cada
 *função deve manipular eles
 */

/** declarações do sistema **/
#include <stdio.h>      /*!< printf, fscanf, etc. */
#include <stdlib.h>     /*!< perror, malloc, etc. */
#include <string.h>     /*!< strcpy               */

#include "lista_enc.h"  /*!< manipulação e criação de listas    */
#include "dados.h"      /*!< declaração das funções             */
#include "no.h"         /*!< manipulação e criação de nós       */

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


lista_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[64];

    /* Demais Variáveis */
    lista_t *lista;
    dado_t *dado;
    no_t *meu_no;

    /* Veriáveis locais, conforme struct dados */
    int posicao;
    char nome[50];
    short int ouro, prata,
    bronze, total;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */

    while (fscanf(fp, "%d,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, nome, &ouro,
                  &prata, &bronze, &total) == 6){

        /** Cria um novo dado abstrato e armazena a sua referência */
         dado = criar_dado(posicao, nome, ouro, prata, bronze, total);
         meu_no = criar_no(dado);
         add_cauda(lista, meu_no);
        }
    fclose(fp);

    return lista;
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
void imprime(dado_t *dados){
    /** Formata em forma de tabela **/
        printf( "|%03d| ", obter_posicao(dados) );
        printf( " %-35s ", obter_nome(dados) );
        printf( "|%02hd|\t  ", obter_ouro(dados) );
        printf( "|%02hd|\t ", obter_prata(dados) );
        printf( "|%02hd|\t ", obter_bronze(dados) );
        printf( "|%02hd|\t\n", obter_total(dados) );
        printf("---------------------------------------------------------------------\n");
    }
