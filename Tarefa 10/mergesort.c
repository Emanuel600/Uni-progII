/*
 * mergesort.c
 *
 *  Created on: 11 de ago. de 2021
 *      Author: emanu
 */
//#define DEBUG

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mergesort.h"
#include "vetores.h"

/* Funções de Ordenação */
// Divide o Vetor em Partes e Chama a Funçao Que o Ordena
void mergesort(double* dados, int esq, int dir){
	//printf("esq: %d | dir: %d\n", esq, dir);
	if (esq < dir){
		int mid = dir + ((esq - dir)>>1); // Reduz Chance de Overflow
		// Quebrar Vetor em Dois Blocos
		mergesort(dados, esq, mid);
		mergesort(dados, mid+1, dir);
		// Unir Dois Blocos
		merge(dados, esq, mid, dir);
		}
}
// Recebe um Bloco e o Ordena
void merge(double* dados, int esq, int mid, int dir){
	//printf("Merge foi chamado\n");
	int i, j, k;				// Índices Genéricos Dos Vetores
	int tamanho = dir-esq+1;	// Tamanho do Bloco
	int ind_esq = esq; 			// Índice Inicial do Bloco Esquerdo
	int ind_dir = mid + 1;		// Índice Inicial do Bloco Direito
	// Criar Vetor Temporário
	double* temp = (double*)malloc(tamanho * sizeof(double));

	// Fundir os Dois de Forma Ordenada
    i = ind_esq;	// Índice Inicial do Primeiro
    j = ind_dir; 	// Índice Inicial do Segundo
    k = 0; 			// Índice Inicial do Ordenado
    while (i <= mid && j <= dir) {
        if (dados[i] <= dados[j]){
            temp[k] = dados[i];
            i++;
        }
        else {
            temp[k] = dados[j];
            j++;
        }
        k++;
    }
    // Copiar o Resto (Caso Exista)
    while (i <= mid){
    	temp[k] = dados[i];
    	i++;
    	k++;
    }
    while (j <= dir){
    	temp[k] = dados[j];
    	j++;
		k++;
    }
    // Mover Dados Para o Vetor Original
    for (k = esq; k <= dir ; k++){
    	dados[k] = temp[k - esq];
    }
	// Liberar Vetor Alocado
	free(temp);
}

// Chama Função Merge Para um Vetor de Tamanho Qualquer
void call_merge(double* dados, int tamanho){
	mergesort(dados, 0, tamanho-1);
}

// Medir Tempo Médio da Ordenação
double medir_tempo_merge(int tamanho){
	int i;
	double sum = 0;

	double* dados = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		dados = preenche_vetor(dados, tamanho);
		clock_t start = clock();
		call_merge(dados, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Mergesort ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(dados);
	#ifdef DEBUG
	printf("Tempo Total (Merge): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif

	return (sum/20);
}
