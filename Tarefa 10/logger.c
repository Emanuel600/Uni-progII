/*
 * logger.c
 *
 *  Created on: 13 de ago. de 2021
 *      Author: emanu
 */

// Include do Sistema
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Includes do Módulo
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertion.h"
#include "bubble_sort.h"
#include "selection_sort.h"

void create_header(char* nome, int tamanho){
	FILE* fp = fopen(nome, "w");

	if (fp == NULL){
		perror("Error ao abrir arquivo");
		exit(-1);
	}

	fprintf(fp, "Dia, Horário, tipo, tempo médio |%d|\n", tamanho);

	fclose(fp);
}

void log_tempo(char* nome, double media, char* tipo){
	time_t hora;
	time(&hora);
	struct tm* calend = localtime(&hora);
	/* Variáveis Para Logar Horário */
	int min = calend->tm_min;
	int sec = calend->tm_sec;
	int dia = calend->tm_mday;
	int hor = calend->tm_hour;

	FILE* fp = fopen(nome, "a");

	if (fp == NULL){
		perror("Erro ao abrir arquivo");
		exit(-1);
	}
	// Loga dia, hora, minuto, segundo, tipo de busca, tempo médio de ordenação e tamanho do vetor
	fprintf(fp, "%d, %d:%d:%d, %s, %g\n", dia, hor, min, sec ,tipo, media);

	fclose(fp);
}

void log_all(char* nome, int tamanho){
	create_header(nome, tamanho);
	/* Conjunto de Funções Para Logar Tempo */
	// Heapsort
	log_tempo(nome, medir_tempo_heap(tamanho), "heapsort");
	// Merge
	log_tempo(nome, medir_tempo_merge(tamanho), "merge");
	// Bubble
	log_tempo(nome, medir_tempo_bubble(tamanho), "bubble");
	// Selection
	log_tempo(nome, medir_tempo_selection(tamanho), "selection");
	// Quicksort
	log_tempo(nome, medir_tempo_quick(tamanho), "quicksort");
	// Insertion
	log_tempo(nome, medir_tempo_insert(tamanho), "insertion");
}
