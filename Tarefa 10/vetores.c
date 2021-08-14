/*
 * vetores.c
 *
 *  Created on: 7 de ago. de 2021
 *      Author: emanu
 */

// Includes do Sistema
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Include do Módulo
#include "vetores.h"

/* Conjunto de Funções Para Criar Vetores */
// Cria um Vetor de Tamanho SIZE
double* criar_vetor(int tamanho){
	double* vet = malloc(sizeof(double)*tamanho);
	
	if (vet == NULL){
	    perror("Erro ao criar vetor");
	    exit(-1);
	}

	srand((unsigned) time(NULL));

	return vet;
}
// Preenche um Vetor Com Dados Aleatórios
double* preenche_vetor(double* vet, int tamanho){
	int i;

	for(i=0;i<tamanho;i++)
		vet[i] = rand()/173.1; // Cria um número qualquer de tipo <double>

	return vet;
}
// Cria e Preenche um Vetor
double* vetor_completo(int tamanho){
	double* vet = criar_vetor(tamanho);
	vet = preenche_vetor(vet, tamanho);

	return vet;
}

// Imprime um Vetor de Determinado Tamanho
void print_vetor(double* vet, int tamanho){
	int i = 0;

	for(i=0;i<tamanho;i++)
		printf("Elemento[%d] -> [%g]\n", i, *(vet+i));
}

// Troca Dois Elementos de um Vetor
void swap(double* esq, double* dir){
	double temp = *esq;

	*esq = *dir;
	*dir = temp;
}
// Libera Dados de um Vetor
void libera_vetor(double* dados){
    free(dados);
}
