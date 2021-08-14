/*
 * vetores.h
 *
 *  Created on: 7 de ago. de 2021
 *      Author: emanu
 */

#ifndef VETORES_H_
#define VETORES_H_
#define SIZE 1000

/* Funções Para Criar um Vetor */
// Cria um Vetor de Determinado Tamanho
double* criar_vetor(int tamanho);
// Preenche um Vetor de Determinado Tamanho
double* preenche_vetor(double* vet, int tamanho);
// Retorna um Vetor Completo
double* vetor_completo(int tamanho);

// Imprime um Vetor de Tamanho SIZE
void print_vetor(double* vet, int tamanho);
//Troca Dois Elementos de um Vetor
void swap(double* esq, double* dir);
// Libera Dados de um Vetor
void libera_vetor(double* dados);
#endif /* VETORES_H_ */
