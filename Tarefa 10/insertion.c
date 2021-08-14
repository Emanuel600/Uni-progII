/*
 * insertion.c
 *
 *  Created on: 14 de ago. de 2021
 *      Author: emanu
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "vetores.h"
#include "insertion.h"

void insertion(double* dados, int tamanho){
	int i, loc, j;
	double selec;

	for (i = 1; i < tamanho; ++i){
		j = i - 1;
		selec = dados[i];
		// Encontrar Localização de Inserção
		loc = pesquisa_binaria(dados, selec, 0, j);

		while (j >= loc){
			dados[j+1] = dados[j];
			j--;
		}
		dados[j+1] = selec;
	}
}
// Encontrar Índice de Inserção
int pesquisa_binaria(double* dados, double item, int esq, int dir){
	if (dir <= esq){
		if (item>dados[esq])
			return (esq+1);
		else
			return esq;
	}

	int mid = dir + ((esq-dir)>>1);

	if (item == dados[mid])
		return mid+1;

	if (item > dados[mid])
		return pesquisa_binaria(dados, item, mid+1, dir);

	return pesquisa_binaria(dados, item, esq, mid-1);
}

// Mede o Tempo Que Demora Para Ordenar(em Segundos)
double medir_tempo_insert(int tamanho){
	int i;
	double sum = 0;

	double* rand = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		rand = preenche_vetor(rand, tamanho);
		clock_t start = clock();
		insertion(rand, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Insertion ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(rand);
	#ifdef DEBUG
	printf("Tempo Total (Insertion): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif

	return (sum/20);
}







