#include "nLinhas.h"

void CriaListanLinhas(tListaN *pLista)
{
    /*Cria uma celula cabeça para iniciar a lista
     *e inicializa o contador com 0*/
     pLista->primeiro = (pCel) malloc(sizeof(tCelulaN));
     pLista->ultimo = pLista->primeiro;
     pLista->ultimo->prox = NULL;
     pLista->cont = 0;
}

int LeListanLinhasVazia(tListaN *pLista)
{
    if(pLista->primeiro == pLista->ultimo)
        return 1; //lista vazia
    else if(pLista->primeiro == NULL)
        return 1; //lista vazia
    else
        return 0; //lista nao vazia
}

/*Insere numero de linha no final da lista*/
void InserenLinha(tListaN *pLista, tNum item)
{
    if(VerificaNaLista(pLista, item) == 0)
    {
        pLista->ultimo->prox = (pCel) malloc(sizeof(tCelulaN));
        pLista->ultimo = pLista->ultimo->prox;
        pLista->ultimo->nLinhas = item;
        pLista->ultimo->prox = NULL;
        (pLista->cont)++;
    }
}

int VerificaNaLista(tListaN *pLista, tNum item)
{
    pCel aux;

    aux = pLista->primeiro->prox;

    while(aux != NULL)
    {
        if(item.numLinha == aux->nLinhas.numLinha)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void RemoveFinal(tListaN *pLista)
{
    pCel aux1, aux2;

    aux1 = pLista->ultimo;
    aux2 = pLista->primeiro->prox;

    if(LeListanLinhasVazia(pLista) == 1)
        return;

    else if(pLista->cont == 1)
    {
        pLista->ultimo = pLista->primeiro;
        pLista->primeiro->prox = NULL;
        free(aux1);
        (pLista->cont)--;
    }
    else
    {
        while(aux2 != aux1)
        {
            if(aux2->prox == aux1)
            {
                aux2->prox = NULL;
                free(aux1);
                (pLista->cont)--;
            }
            aux2 = aux2->prox;
        }
    }
}

int QtdLinhas(tListaN *pLista)
{
    return(pLista->cont);
}

void ImprimeListanLinhas(tListaN Lista)
{
    pCel aux;

    aux = Lista.primeiro->prox;

    if(LeListanLinhasVazia(&Lista) == 1)
        printf("Não ha uma lista de numero de linhas!\n");
    else
    {
        while(aux != NULL)
        {
            printf("Linha: %d\n", aux->nLinhas.numLinha);
            aux = aux->prox;
        }
    }
}

void ApagaLista(tListaN *pLista)
{
    pCel auxCel, aux;

    auxCel = pLista->primeiro;

    while(auxCel != NULL)
    {
        aux = auxCel;
        auxCel = auxCel->prox;
        free(aux);
    }
}
