/*
 * bubble_sort.c
 *
 *  Created on: 7 de ago. de 2021
 *      Author: emanu
 */
//#define DEBUG

// Includes do Sistema
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Include do Módulo
#include "vetores.h"

// Ordena Elementos em Ordem Crescente
void bubble_sort(double* dados, int tamanho){
	int i, j;
	for(i = 0; i<tamanho-1; i++) // Varre Para Garantir Que Foi Ordenado
		for(j=0; j<tamanho-i-1; j++) //Varre Todos os Elementos Para Ordená-los Uma Vez
			if(dados[j]>dados[j+1])
				swap(&dados[j], &dados[j+1]);
}

// Mede o Tempo Que Demora Para Ordenar(em Segundos)
double medir_tempo_bubble(int tamanho){
	int i;
	double sum = 0;

	double* rand = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		rand = preenche_vetor(rand, tamanho);
		clock_t start = clock();
		bubble_sort(rand, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Bubble ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(rand);
	#ifdef DEBUG
	printf("Tempo Total (Bubble): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif
	
	return (sum/20);
}
