/*
 * main.c
 *
 *  Created on: 7 de ago. de 2021
 *      Author: emanu
 */
// Include do Sistema
#include <stdio.h>
 // Includes do Módulo
#include "logger.h"
#include "vetores.h"
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertion.h"
#include "bubble_sort.h"
#include "selection_sort.h"

int main(){
	/* Funções Para Ordenar e Imprimir um Vetor */
    // Recebe um Vetor Completo
	/*double* dados = vetor_completo(SIZE);
    // Ordena o Vetor
	insertion(dados, SIZE);
    // Imprime Resultado da Ordenação
	print_vetor(dados, SIZE);
	// Libera Vetor da Memória
	libera_vetor(dados);*/

	/* Imprimir Tempos Médios *//*
	printf("Tempo Médio Merge: [%g]\n", medir_tempo_merge(SIZE));
	printf("Tempo Médio Bubble: [%g]\n", medir_tempo_bubble(SIZE));
	printf("Tempo Médio Selection: [%g]\n", medir_tempo_selection(SIZE));
	printf("Tempo Médio Quicksort: [%g]\n", medir_tempo_quick(SIZE));
	printf("Tempo Médio Insertion: [%g]\n", medir_tempo_insert(SIZE));*/

	/* Logar Tempos Médios */
	log_all("relatorio.csv", SIZE);
}





