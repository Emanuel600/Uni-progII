/*
 * quicksort.c
 *
 *  Created on: 9 de ago. de 2021
 *      Author: emanu
 */

//#define DEBUG

// Include do Sistema
#include <stdio.h>
#include <time.h>
// Include do Módulo
#include "vetores.h"

// Define qual Número Utilizar Como Pivô
double definir_pivo(double num1, double num2, double num3){
	if ((num1>num2) ^ (num1>num3))
		return num1;
	else if ((num2<num1) ^ (num2<num3))
		return num2;
	else
		return num3;
}
// Retorna índice de partição (ip)
int partir(double* dados, int baixo, int alto){
	double pivo = definir_pivo(dados[alto], dados[alto>>1], dados[baixo]);

	int i = baixo - 1;

	for (int j = baixo; j<=alto-1; j++){
		if (dados[j] < pivo){
			i++; // Menor Que Pivô, Vai a Esquerda
			swap(&dados[i], &dados[j]);
		}
	}
	// Troca Elemento Imediatamente (em Índice) Maior Que o Pivô
	//e o Pivô(alto) Para Deixar o Próximo Pivô no Lugar Correto
	swap(&dados[i+1], &dados[alto]);

	return i+1;
}
// Ordena Números de um Vetor <double>
void quicksort(double* dados, int baixo, int alto){
	// Quando Terminar, baixo==alto
	if (baixo<alto){
		// Parte o Bloco Atual em Dois
		int ip = partir(dados, baixo, alto);
		// Chama Quicksort Nos Dois Blocos
		quicksort(dados, baixo, ip-1);
		quicksort(dados, ip+1, alto);
	}
}
// Como a Função Quicksort é Recursiva,
//Esta Função a Chama com Todos os Dados
//Necessários Para a Ordenação
void call_quick(double* dados, int tamanho){
	quicksort(dados, 0, tamanho-1);
}
// Retorna Tempo Real Médio da Ordenação
double medir_tempo_quick(int tamanho){
	int i;
	double sum = 0;

	double* dados = criar_vetor(tamanho);

	for (i = 0; i<20; i++){
		dados = preenche_vetor(dados, tamanho);
		clock_t start = clock();
		call_quick(dados, tamanho);
		clock_t end = clock();

		double secs = (double)(end - start)/CLOCKS_PER_SEC;
		#ifdef DEBUG
		printf("== Quicksort ==\n");
		printf("Tempo iter [%d]: [%g]\n", i+1, secs);
		#endif

		sum+= secs;
	}
	libera_vetor(dados);
	#ifdef DEBUG
	printf("Tempo Total (Quick): [%g]\nTempo Médio: [%g]\n", sum, sum/20);
	#endif

	return (sum/20);
}

