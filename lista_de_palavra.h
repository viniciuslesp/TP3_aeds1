#ifndef LISTA_DE_PALAVRA_H_INCLUDED
#define LISTA_DE_PALAVRA_H_INCLUDED
#include "palavra.h"

typedef struct{
    item_palavra word;
}tipo_word;

typedef struct{
    tipo_word *word2;
    int tam_word2;
    int primeiro, ultimo;
}lista_words;

void imprimeListaOrdenada(lista_words *lista, int metodo);
void CriaListaVazia(lista_words *pLista);
int VerificaListaVazia(lista_words *pLista);
int verifica_palavra(lista_words *pLista, char *palavra);
void insere_palavra(lista_words *pLista, char *palavra, int numlinha);
int RemovePalavraDada(lista_words *pLista, char *palavra);
void ImprimeListaPalavra(lista_words pLista);
int RetornaNumPalavras(lista_words *pLista);
void RemovePalavraFinal(lista_words *pLista);

#endif // LISTA_DE_PALAVRA_H_INCLUDED
