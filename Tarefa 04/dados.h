/** Declara as funções utilizadas
 * para manipulação e leitura de dados
 **/


#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED
#include "lista_enc.h"  /*!< Para usar listas como retorno e entrada */

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;


/** Função para criar dados **/
dado_t *criar_dado (int posicao, char *nome, short int ouro, short int prata, short int bronze, short int total);

/** Função para ler o arquivo e armazenar os dados no nó **/
lista_t *ler_dados_csv(char *nome_do_arquivo);

            /** Conjunto de funções para obter dados **/
int obter_posicao(dado_t* dado);        int obter_amostra(dado_t *dado);

short int obter_ouro(dado_t* dado);     short int obter_prata(dado_t* dado);

short int obter_bronze(dado_t* dado);   short int obter_total(dado_t* dado);

/** Imprime os dados em forma de tabela **/
void imprime(dado_t *dados);

#endif
