#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
#include <string.h>
#define maxtam 46
#include "nLinhas.h"

typedef struct{
    char letra[maxtam];
    tListaN n_linhas;
}item_palavra;

void imprime_lista(item_palavra *tpalavra);
void imprime_palavra(item_palavra *tpalavra);
char* retorna(item_palavra *tpalavra);
void insere_nlinha(item_palavra *tpalavra, int linha);
void preenche(item_palavra *tpalavra, char *palavra);
void FPalavraVazia(item_palavra *tpalavra);

#endif // PALAVRA_H_INCLUDED
