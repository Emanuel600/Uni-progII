/** Declara as funções utilizadas
 * para manipulação e leitura de dados
 **/

// Guarda
#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED
// Includes do módulo
#include "no.h"
#include "fila.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/* Lê os dados de um arquivo CSV */
fila_t* ler_dados_csv_fila(char *nome_do_arquivo);

/** Função para criar dados **/
dado_t *criar_dado (int posicao, char *nome, short int ouro,
                    short int prata, short int bronze, short int total);

            /** Conjunto de funções para obter dados **/
int obter_posicao(dado_t* dado);        //int obter_amostra(dado_t *dado);

short int obter_ouro(dado_t* dado);     short int obter_prata(dado_t* dado);

short int obter_bronze(dado_t* dado);   short int obter_total(dado_t* dado);

/** Imprime os dados em forma de tabela **/
void imprime(fila_t* fila);
void print(dado_t *dados);

//Libera os dados de um nó
void liberar_dados(no_t *fila);

#endif
