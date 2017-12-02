#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED
#define tammax 26
#include "letra.h"

typedef struct{
    tLetras texto;
}tAlfabeto;

typedef struct{
    tAlfabeto alfabeto[tammax];
}ListaAlfabeto;

void PreencheAlfabeto (ListaAlfabeto *Alfabeto);
void InsereNaLista(ListaAlfabeto *Alfabeto, char *palavra, int numerolinha);
void RemovePalavra(ListaAlfabeto *Alfabeto, char *palavra);
void ImprimeAlfabeto(ListaAlfabeto *Alfabeto, char letra);
void ImprimeDicionario(ListaAlfabeto Alfabeto);
void remove_char(char* str, char c);


#endif // DICIONARIO_H_INCLUDED
