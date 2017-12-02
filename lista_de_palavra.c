#include "lista_de_palavra.h"
#include "Ordenacao.h"

void CriaListaVazia(lista_words *pLista)
{
    pLista->primeiro = 0;
    pLista->ultimo = pLista->primeiro;
    pLista->tam_word2 = 0;
}

int VerificaListaVazia(lista_words *pLista)
{
    if(pLista->primeiro == pLista->ultimo)
        return 1; //lista vazia
    else
        return 0;
}

int verifica_palavra(lista_words *pLista, char *palavra)
{
    int i;

    for(i = 0; i <= pLista->tam_word2; i++)
    {
        if(strcmp(palavra, retorna(&pLista->word2[i].word)) == 0)
            return 1; // a palavra existe
    }

    return 0;
}

void insere_palavra(lista_words *pLista, char *palavra, int numlinha)
{
    int i;

    if(VerificaListaVazia(pLista) == 1)
    {
        (pLista->tam_word2)++;
		pLista->word2 = (tipo_word*) malloc((pLista->tam_word2)*sizeof(tipo_word));
		FPalavraVazia(&pLista->word2[pLista->ultimo].word);
        preenche(&pLista->word2[pLista->ultimo].word, palavra);
        insere_nlinha(&pLista->word2[pLista->ultimo].word, numlinha);
        (pLista->ultimo)++;
    }
    else if(verifica_palavra(pLista, palavra) == 0)
	{
		(pLista->tam_word2)++;
		pLista->word2 = (tipo_word*) realloc(pLista->word2, pLista->tam_word2 * sizeof(tipo_word));
		FPalavraVazia(&pLista->word2[pLista->ultimo].word);

        preenche(&pLista->word2[pLista->ultimo].word, palavra);

        insere_nlinha(&pLista->word2[pLista->ultimo].word, numlinha);

        (pLista->ultimo)++;

	}
	else
	{
		for(i = 0; i <= pLista->ultimo; i++)
		{
			if(strcmp(palavra, retorna(&pLista->word2[i].word)) == 0)
			{
				insere_nlinha(&pLista->word2[i].word, numlinha);
			}
		}
	}
}

int RemovePalavraDada(lista_words *pLista, char *palavra) //remove palavra dada
{
    int i, j;

    if(VerificaListaVazia(pLista) == 1) //verifica se a lista esta vazia
    {
        return 0;
    }

    for(i = 0; i < pLista->tam_word2; i++)
	{
		if(strcmp(palavra, retorna(&pLista->word2[i].word))==0)
		{
			ApagaLista(&pLista->word2[i].word.n_linhas);
			(pLista->tam_word2)--;

			for(j = i; j < (pLista->ultimo - 1); j++)
			{
				pLista->word2[j] = pLista->word2[j+1];
			}
			pLista->word2 = (tipo_word*) realloc(pLista->word2, pLista->tam_word2 * sizeof(tipo_word));
			(pLista->ultimo)--;
			return 1;
		}
	}

    return 0;
}

void ImprimeListaPalavra(lista_words pLista) //imprime palavra + lista de numero de linha
{
    int i;

    for(i = 0; i < pLista.tam_word2; i++)
    {
        imprime_lista(&pLista.word2[i].word); //chama função para imprimir
    }
}

int RetornaNumPalavras(lista_words *pLista) //conta quantas palavras existem na lista
{
    return(pLista->tam_word2);
}

void RemovePalavraFinal(lista_words *pLista) //remove a ultima celula da lista
{
    ApagaLista(&pLista->word2[pLista->ultimo].word.n_linhas);

	(pLista->tam_word2)--;

	pLista->word2 = (tipo_word*) realloc(pLista->word2, pLista->tam_word2 * sizeof(tipo_word));

	(pLista->ultimo)--;
}

void imprimeListaOrdenada(lista_words *lista, int metodo)
{
    t_ordenacao listaAux;
    CriaVetorAux(&listaAux, *lista, lista->tam_word2);
    SelecionaMetodo(&listaAux, metodo, lista->tam_word2);
}
