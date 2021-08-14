/*
 * heapsort.h
 *
 *  Created on: 13 de ago. de 2021
 *      Author: emanu
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

void heapsort(double* dados, int tamanho);
void heapify(double* dados, int tamanho, int ind);

double medir_tempo_heap(int tamanho);

#endif /* HEAPSORT_H_ */
