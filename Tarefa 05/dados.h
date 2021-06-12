/** Declara as funções utilizadas
 * para manipulação e leitura de dados
 **/


#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED
#include "lista_enc.h"  /*!< Para usar listas como retorno e entrada */
#include "pilha.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;


/** Função para criar dados **/
dado_t *criar_dado (int posicao, char *nome, short int ouro,
                    short int prata, short int bronze, short int total);

            /** Conjunto de funções para obter dados **/
int obter_posicao(dado_t* dado);        //int obter_amostra(dado_t *dado);

short int obter_ouro(dado_t* dado);     short int obter_prata(dado_t* dado);

short int obter_bronze(dado_t* dado);   short int obter_total(dado_t* dado);

/** Função para ler o arquivo e armazenar os dados na pilha **/
pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo);

// Imprime a lista na tela
void imprime (pilha_t* pilha);

/** Imprime os dados em forma de tabela **/
void formata(dado_t *dados);

//Libera os dados da pilha
void liberar_dados(pilha_t *pilha);

#endif