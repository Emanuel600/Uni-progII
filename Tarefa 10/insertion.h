/*
 * insertion.h
 *
 *  Created on: 14 de ago. de 2021
 *      Author: emanu
 */

#ifndef INSERTION_H_
#define INSERTION_H_

void insertion(double* dados, int tamanho);

int pesquisa_binaria(double* dados, double item, int esq, int dir);


double medir_tempo_insert(int tamanho);

#endif /* INSERTION_H_ */
