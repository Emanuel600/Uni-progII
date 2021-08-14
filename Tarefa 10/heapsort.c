/*
 * heapsort.c
 *
 *  Created on: 13 de ago. de 2021
 *      Author: emanu
 */
// Includes do Sistema
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Includes do Módulo
#include "vetores.h"
#include "heapsort.h"

void heapsort(double* dados, int tamanho){
	int n = (tamanho>>1) - 1;
	int i;
	for (i = n; i >= 0; i--)
		heapify(dados, tamanho, i);
	for (i = tamanho-1; i > 0; i--){
		swap(&dados[0], &dados[i]);
		heapify(dados, i, 0);
	}
}

void heapify(double* dados, int tamanho, int ind){
	int maior = ind;
	int esq = (ind<<1) + 1;
	int dir = (ind<<1) + 2;

	if (esq < tamanho && (dados[esq] > dados[maior]))
		maior = esq;
	if (dir < tamanho && (dados[dir] > dados[maior]))
		maior = dir;
	if (maior != ind){
		swap(&dados[ind], &dados[maior]);

		heapify(dados, tamanho, maior);
	}
}

double medir_tempo_heap(int tamanho){
	int i;
	double sum = 0;

	double* rand = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		rand = preenche_vetor(rand, tamanho);
		clock_t start = clock();
		heapsort(rand, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Heap ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(rand);
	#ifdef DEBUG
	printf("Tempo Total (Heap): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif

	return (sum/20);
}


