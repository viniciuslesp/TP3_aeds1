#ifndef NLINHAS_H_INCLUDED
#define NLINHAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/*Item da celula.
 *Armazena o numero da linha*/
typedef struct{
    int numLinha;
}tNum;

/*Estrutura da celula*/
typedef struct tCelulaN *pCel;
typedef struct tCelulaN{
    tNum nLinhas;
    pCel prox;
}tCelulaN;

typedef struct{
    pCel primeiro;
    pCel ultimo;
    int cont;
}tListaN;

void CriaListanLinhas(tListaN *pLista);
int LeListanLinhasVazia(tListaN *pLista);
void InserenLinha(tListaN *pLista, tNum item);
int VerificaNaLista(tListaN *pLista, tNum item);
void RemoveFinal(tListaN *pLista);
int QtdLinhas(tListaN *pLista);
void ImprimeListanLinhas(tListaN Lista);
void ApagaLista(tListaN *pLista);


#endif // NLINHAS_H_INCLUDED
