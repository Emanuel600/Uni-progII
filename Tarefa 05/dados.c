/** Parte do programa que define as funções
 * de leitura e manipulação de dados
 * 
 * Define a estrutura de dados e define como cada
 *função deve manipular eles
 */

// Includes do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Includes do módulo
#include "pilha.h"
#include "dados.h"
  
struct dados {
int posicao;
    char nome[40];
    short int ouro, prata,
    bronze, total;
};

// Cria um dado
dado_t *criar_dado (int posicao, char *nome, short int ouro, short int prata,
                    short int bronze, short int total){

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

// Ler dados a partir de um arquivo CSV
pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo){
    char texto[64];
    pilha_t *pilha;
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
    
    pilha = cria_pilha();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    while (fscanf(fp, "%d,%50[^,],%hd,%hd,%hd,%hd\n",&posicao, nome, &ouro,
                  &prata, &bronze, &total) == 6){
        /** Cria um novo dado e o armazena na pilha */
         dado = criar_dado(posicao, nome, ouro, prata, bronze, total);
         push(dado, pilha);
        }
    fclose(fp);
    
    return pilha;
}

/** Conjunto de funções que obtem dados **/
// Posição
int obter_posicao(dado_t *dado){
    return dado->posicao;
}
// Nome do país
char* obter_nome(dado_t* dado){
    return dado->nome;
}
// Quantia de medalhas de ouro
short int obter_ouro(dado_t* dado){
    return dado->ouro;
}
// Quantia de medalhas de prata
short int obter_prata(dado_t* dado){
    return dado->prata;
}
// Quantia de medalhas de bronze
short int obter_bronze(dado_t* dado){
    return dado->bronze;
}
// Quantia total de medalhas
short int obter_total(dado_t* dado){
    return dado->total;
}

// Imprime os dados na tela em formato de tabela
void formata(dado_t *dados){
    /** Formata em forma de tabela **/
    printf( "|%03d| ", obter_posicao(dados) );
    printf( " %-35s ", obter_nome(dados) );
    printf( "|%02hd|\t  ", obter_ouro(dados) );
    printf( "|%02hd|\t ", obter_prata(dados) );
    printf( "|%02hd|\t ", obter_bronze(dados) );
    printf( "|%02hd|\t\n", obter_total(dados) );
    printf("---------------------------------------------------------------------\n");
}
    
    
// Libera os dados em uma pilha
void liberar_dados(pilha_t *pilha){
    dado_t* dado;
	if (pilha == NULL) {
	        fprintf(stderr,"Pilha inexistente");
	        exit(EXIT_FAILURE);
	    }
    //Loop para liberar tudo
    while (!pilha_vazia(pilha)){
        dado = pop(pilha);
        formata(dado);
        free(dado);
    }
    free(obter_lista(pilha));
    free(pilha);
}