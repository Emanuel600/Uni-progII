/*
 * logger.h
 *
 *  Created on: 13 de ago. de 2021
 *      Author: emanu
 */

#ifndef LOGGER_H_
#define LOGGER_H_
/* Funções Para Criar Log*/
// Cria Cabeçalho
void create_header(char* nome);
// Loga Tempo Qualquer
void log_tempo(char* nome, double media, char* tipo);

// Loga as Médias de Todas as Ordenações
void log_all(char* nome, int tamanho);

#endif /* LOGGER_H_ */
