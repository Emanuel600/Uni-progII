/* Header responsavel por definir
 *as funções utilizadas para manipular
 *e ler dados
*/

#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/** Cria os dados em uma struct **/
dado_t *criar_dado (int amostra, char *nome, short int ouro, short int prata, short int bronze, short int total);


/** Retorna o número de linhas no arquivo **/
void determinar_linhas(char *nome_do_arquivo, int *total_dados);
/** Lê e armazena os dados do arquivo **/
dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados);

            /** Conjunto de funções para obter dados **/
int obter_posicao(dado_t* dado);        int obter_amostra(dado_t *dado);

short int obter_ouro(dado_t* dado);     short int obter_prata(dado_t* dado);

short int obter_bronze(dado_t* dado);   short int obter_total(dado_t* dado);

/** Imprime os dados em forma de tabela **/
void imprimir(dado_t **dados, int n_linhas);

/** Libera os dados **/
void liberar_dados(dado_t** vetor, int n_linhas);

#endif
