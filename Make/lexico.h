/* 
 * File:   lexico.h
 * Authors: Rodrigo Acosta, Rodrigo Oliveira
 *
 * Created on 28 de Junho de 2013
 */

#ifndef FUNCOES_H
#define	FUNCOES_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCOES_H */

/* Recebe um ponteiro para um arquivo e retorna seu numero de caracteres. */
int conta_caracteres(FILE *arquivo);

/* Recebe um ponteiro para um arquivo e retorna seu numero de linhas. */
int conta_linhas(FILE *arquivo);

/* Elimina os trechos comentados. */
void remove_comentarios(char * entrada, char * saida);

/* Substitui por espacos os trechos comentados.
 * Necessario para manter a contagem de caracteres e linhas
 * sincronizada com o arquivo original. */
void limpa_comentarios(char * entrada, char * saida);

/* Recebe um caracter e um escopo de busca no vocabulario.
 * Retorna 'v' ou 'f'. */
char busca_caracter(char caracter, int ini, int fim);

/* Recebe uma string, um ponteiro, um indicador de final e indices de linha e coluna.
 * Retorna o primeiro token encontrado a partir do ponteiro ou um erro. */
char * gera_token(char * entrada, int * index, char * fim, int * linha, int * coluna);

/* Recebe uma expressao e retorna os tokens correspondentes.
 * Retorna tambem uma mensagem de sucesso ou de erro,
 * indicando, neste ultimo caso, linha e coluna em que ocorreu. */
char * codifica_expressao(char * entrada);