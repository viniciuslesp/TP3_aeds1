#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED
#include "lista_de_palavra.h"

typedef struct{
    tipo_word *vetoraux;
}t_ordenacao;

void CriaVetorAux (t_ordenacao *listaAux, lista_words lista, int tamanho);
void SelecionaMetodo(t_ordenacao *listaAux, int metodo, int tamanho);
void Bolha(t_ordenacao *listaAux, int tamanho);
void Selecao(t_ordenacao *listaAux, int tamanho);
void Insercao(t_ordenacao *listaAux, int tamanho);
void ShellSort(t_ordenacao *listaAux, int tamanho);
void QuickSort(t_ordenacao *listaAux, int tamanho);
void Ordena(int esq, int dir, t_ordenacao *listaAux);
void Particao(int esq, int dir, int *i, int *j, t_ordenacao *listaAux);


#endif // ORDENACAO_H_INCLUDED
