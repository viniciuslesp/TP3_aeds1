#include "palavra.h"

void FPalavraVazia(item_palavra *tpalavra)
{
    CriaListanLinhas(&tpalavra->n_linhas);
}

void preenche(item_palavra *tpalavra, char *palavra)
{
    strcpy(tpalavra->letra, palavra);
}

void insere_nlinha(item_palavra *tpalavra, int linha)
{
    tNum linhax;

    linhax.numLinha = linha;
    InserenLinha(&tpalavra->n_linhas, linhax);
}

char* retorna(item_palavra *tpalavra)
{
    return(tpalavra->letra);
}

void imprime_palavra(item_palavra *tpalavra)
{
    printf("Palavra: %s\n", tpalavra->letra);
}

void imprime_lista(item_palavra *tpalavra)
{
    printf("Palavra: %s\n", tpalavra->letra);
    ImprimeListanLinhas(tpalavra->n_linhas);
    printf("\n");
}
