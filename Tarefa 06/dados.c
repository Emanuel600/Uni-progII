/** Parte do programa que define as funções
 * de leitura e manipulação de dados
 *
 * Define a estrutura de dados e define como cada
 *função deve manipular eles
 */

// Includes do sistema
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Includes do módulo
#include "fila.h"
#include "dados.h"
  
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


/** Lê os dados de um CSV **/
fila_t *ler_dados_csv_fila(char *nome_do_arquivo){
    char texto[64];
    fila_t *fila;
    dado_t *dado;
    
    /* Demais Variáveis conforme struct dados */
    int posicao;
    char nome[40];
    short int ouro, prata,
    bronze, total;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    fila = cria_fila();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    while (fscanf(fp, "%d,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, nome, &ouro,
                      &prata, &bronze, &total) == 6){

            /** Lê os dados e os armazena na fila */
             dado = criar_dado(posicao, nome, ouro, prata, bronze, total);
             enqueue(dado, fila);
            }
    fclose(fp);
    
    return fila;
}

/** Funções para obter dados **/
int obter_posicao(dado_t *dado){
    if (dado == NULL) {
        fprintf(stderr,"Dado inexistente");
        exit(EXIT_FAILURE);
    }

    return dado->posicao;
}

/** Conjunto de funções para obter os dados da fila **/
// Retorna o nome
char* obter_nome(dado_t* dado){
	if (dado == NULL) {
	        fprintf(stderr,"Dado inexistente");
	        exit(EXIT_FAILURE);
	    }
    return dado->nome;
}
// Retorna a quantia de medalhas de ouro
short int obter_ouro(dado_t* dado){
	if (dado == NULL) {
	        fprintf(stderr,"Dado inexistente");
	        exit(EXIT_FAILURE);
	    }
    return dado->ouro;
}
// Retorna a quantia de medalhas de prata
short int obter_prata(dado_t* dado){
	if (dado == NULL) {
	        fprintf(stderr,"Dado inexistente");
	        exit(EXIT_FAILURE);
	    }
    return dado->prata;
}
// Retorna a quantia de medalhas de bronze
short int obter_bronze(dado_t* dado){
	if (dado == NULL) {
	        fprintf(stderr,"Dado inexistente");
	        exit(EXIT_FAILURE);
	    }
    return dado->bronze;
}
// Retorna a quantia total de medalhas
short int obter_total(dado_t* dado){
	if (dado == NULL) {
	        fprintf(stderr,"Dado inexistente");
	        exit(EXIT_FAILURE);
	    }
    return dado->total;
}

/** Imprime a fila **/
void imprime(fila_t* fila){
	/** Cabeçalho **/
	printf("=====================================================================\n");
	printf(" Pos\t\t  Nome  \t\t   Ouro\t Prata\tBronze\tTotal\n");
	printf("=====================================================================\n");

	while (!fila_vazia(fila)){
	    dado_t* dado = dequeue(fila);
	    print(dado);
	    free(dado);
	 	}
}

// Formata os dados como uma tabela
void print(dado_t *dados){
    /** Formata em forma de tabela **/
        printf( "|%03d| ", obter_posicao(dados) );
        printf( " %-35s ", obter_nome(dados) );
        printf( "|%02hd|\t  ", obter_ouro(dados) );
        printf( "|%02hd|\t ", obter_prata(dados) );
        printf( "|%02hd|\t ", obter_bronze(dados) );
        printf( "|%02hd|\t\n", obter_total(dados) );
        printf("---------------------------------------------------------------------\n");
    }