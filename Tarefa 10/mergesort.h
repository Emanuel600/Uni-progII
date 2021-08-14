/*
 * mergesort.h
 *
 *  Created on: 11 de ago. de 2021
 *      Author: emanu
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_
/* Conjunto de Funções Para Ordenar um Vetor Qualquer */
// Função Que Separa em Blocos e Chama a Função Que os Ordena
void mergesort(double* dados, int esq, int dir);
// Junta os Blocos de Forma Ordenada
void merge(double* dados, int esq, int mid, int dir);

// Chama a Função Que Ordena um Vetor de Tamanho Qualquer
void call_merge(double* dados, int tamanho);

// Função Que Mede Tempo "Wall"
double medir_tempo_merge(int tamanho);
#endif /* MERGESORT_H_ */
