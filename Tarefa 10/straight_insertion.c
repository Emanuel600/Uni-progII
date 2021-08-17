/*
 * Ordena um Vetor de Dados <double*> Por Straight Insertion
 *e Mede o Tempo Médio de Ordenação
 */
// Include do Sistema
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Include do Módulo
#include "vetores.h"
#include "straight_insertion.h"

void insertion_sort(double* dados, int tamanho){
	int i, j;
	double chave;

	for (i=0; i<tamanho; i++){
		chave = dados[i];
		j = i - 1;

		while (j>=0 && dados[j] > chave){
			dados[j+1] = dados[j];
			j--;
		}

		dados[j+1] = chave;
	}
}

// Mede o Tempo Que Demora Para Ordenar(em Segundos)
double medir_tempo_insertion(int tamanho){
	int i;
	double sum = 0;

	double* rand = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		rand = preenche_vetor(rand, tamanho);
		clock_t start = clock();
		insertion_sort(rand, tamanho);
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
