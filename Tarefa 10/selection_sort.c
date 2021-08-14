/*
 * selection_sort.c
 *
 *  Created on: 7 de ago. de 2021
 *      Author: emanu
 */

//#define DEBUG 
 
//Includes do Sistema
#include <time.h>
#include <stdio.h>
// Include do Módulo
#include "vetores.h"

// Ordena o Vetor
void selection_sort(double* dados, int tamanho){
	int min_index, j, i = 0;

	for(i=0; i<tamanho-1; i++){
		min_index = i;

		for (j=i+1; j<tamanho; j++)
			if(dados[j]<dados[min_index])
				min_index = j;
		swap(&dados[min_index], &dados[i]);
	}
}

// Mede o Tempo Que Demora Para Ordenar(em Segundos)
double medir_tempo_selection(int tamanho){
	int i;
	double sum = 0;

	double* rand = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		rand = preenche_vetor(rand, tamanho);
		clock_t start = clock();
		selection_sort(rand, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Selection ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(rand);
	#ifdef DEBUG
	printf("Tempo Total (Selection): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif
	
	return (sum/20);
}
