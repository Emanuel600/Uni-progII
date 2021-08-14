/*
 * quicksort.h
 *
 *  Created on: 9 de ago. de 2021
 *      Author: emanu
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
// Retorna Índice de Partição
int partir(double* dados, int baixo, int alto);
// Chama Quicksort Recursivamente
void quicksort(double* dados,int baixo, int alto);
// Chama a Fucção Quicksort Conforme Necessário
void call_quick(double* dados);
// Retorna Tempo Real Médio
double medir_tempo_quick(int tamanho);
#endif /* QUICKSORT_H_ */
