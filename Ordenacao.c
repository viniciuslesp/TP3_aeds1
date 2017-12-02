#include "Ordenacao.h"

void CriaVetorAux (t_ordenacao *listaAux, lista_words lista, int tamanho)
{
    int i;

    listaAux->vetoraux = (tipo_word*) malloc(tamanho * sizeof(tipo_word));

    for(i = 0; i < tamanho; i++)
    {
        listaAux->vetoraux[i] = lista.word2[i];
    }

}

void SelecionaMetodo(t_ordenacao *listaAux, int metodo, int tamanho)
{
    switch(metodo)
    {
        case 1:
            Bolha(listaAux, tamanho);
            break;
        case 2:
            Selecao(listaAux, tamanho);
            break;
        case 3:
            Insercao(listaAux, tamanho);
            break;
        case 4:
            ShellSort(listaAux, tamanho);
            break;
        case 5:
            QuickSort(listaAux, tamanho);
            break;
        /*case 6:
            HeapSort(listaAux, tamanho);
            break;*/
    }
}

void Bolha(t_ordenacao *listaAux, int tamanho)
{
    int i, j;
    item_palavra aux;

    for(i = 0; i < tamanho-1; i++)
    {
        for(j = 1; j < tamanho-i; j++)
        {
            if(strcmp(listaAux->vetoraux[j].word.letra, listaAux->vetoraux[j-1].word.letra) < 0)
            {

                aux = listaAux->vetoraux[j].word;
                listaAux->vetoraux[j].word = listaAux->vetoraux[j-1].word;
                listaAux->vetoraux[j-1].word = aux;

            }
        }
    }

    for(i = 0; i < tamanho; i++)
    {
        imprime_lista((&listaAux->vetoraux[i].word));
    }
}

void Selecao(t_ordenacao *listaAux, int tamanho)
{
    int i, j, min;
    item_palavra aux;

    for(i = 0; i < tamanho-1; i++)
    {
        min = i;
        for(j = i+1; j < tamanho; j++)
        {
            if(strcmp(listaAux->vetoraux[j].word.letra, listaAux->vetoraux[min].word.letra) < 0)
                min = j;
        }
        if(i != min)
        {
            aux = listaAux->vetoraux[i].word;
            listaAux->vetoraux[i].word = listaAux->vetoraux[min].word;
            listaAux->vetoraux[min].word = aux;
        }
    }

    for(i = 0; i < tamanho; i++)
    {
        imprime_lista((&listaAux->vetoraux[i].word));
    }
}

void Insercao(t_ordenacao *listaAux, int tamanho)
{
    int i, j;
    item_palavra aux;

    for(i = 1; i < tamanho; i++)
    {
        aux = listaAux->vetoraux[i].word;
        j = i-1;

        while(j >= 0 && (strcmp(listaAux->vetoraux[j].word.letra, aux.letra) > 0))
        {
            listaAux->vetoraux[j+1].word = listaAux->vetoraux[j].word;
            j--;
        }
        listaAux->vetoraux[j+1].word = aux;
    }

    for(i = 0; i < tamanho; i++)
    {
        imprime_lista((&listaAux->vetoraux[i].word));
    }
}

void ShellSort(t_ordenacao *listaAux, int tamanho)
{
    int i, j;
    int h = 1;
    item_palavra aux;

    do
    {
        h = h * 3 +1;
    }while(h < tamanho);

    do
    {
        h = h/3;
        for(i = h; i < tamanho; i++)
        {
            aux = listaAux->vetoraux[i].word;
            j = i;
            while(strcmp(listaAux->vetoraux[j-h].word.letra, aux.letra) > 0)
            {
                listaAux->vetoraux[j] = listaAux->vetoraux[j-h];
                j -= h;
                if(j < h)
                    break;
            }
            listaAux->vetoraux[j].word = aux;
        }
    }while(h != 1);

    for(i = 0; i < tamanho; i++)
    {
        imprime_lista((&listaAux->vetoraux[i].word));
    }
}
/*inicio QuickSort*/
void QuickSort(t_ordenacao *listaAux, int tamanho)
{
    int x;

    Ordena(0, tamanho-1, listaAux);

    for(x = 0; x < tamanho; x++)
    {
        imprime_lista((&listaAux->vetoraux[x].word));
    }
}

void Ordena(int esq, int dir, t_ordenacao *listaAux)
{
    int i, j;

    Particao(esq, dir, &i, &j, listaAux);

    if(esq < j)
        Ordena(esq, j, listaAux);
    if(i < dir)
        Ordena(i, dir, listaAux);
}

void Particao(int esq, int dir, int *i, int *j, t_ordenacao *listaAux)
{
    item_palavra pivo, aux;

    *i = esq;
    *j = dir;

    pivo = listaAux->vetoraux[(*i + *j)/2].word;

    do
    {
        while(strcmp(listaAux->vetoraux[*i].word.letra, pivo.letra) < 0)
        {
            (*i)++;
        }

        while(strcmp(listaAux->vetoraux[*j].word.letra, pivo.letra) > 0)
        {
            (*j)--;
        }
        if(*i <= *j)
        {
            aux = listaAux->vetoraux[*i].word;
            listaAux->vetoraux[*i].word = listaAux->vetoraux[*j].word;
            listaAux->vetoraux[*j].word = aux;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}
/*fim QuickSort*/

/*inicio HeapSort*/
/*void HeapSort(t_ordenacao *listaAux, int *tamanho)
{
    int i;
    int esq, dir;
    item_palavra aux;

    Constroi(listaAux, tamanho);

    esq = 1;
    dir = *tamanho;

    while(dir > 1)
    {
        aux = listaAux->vetoraux[1].word;
        listaAux->vetoraux[1].word = listaAux->vetoraux[dir].word;
        listaAux->vetoraux[dir].word = aux;
        dir--;
        Refaz(esq, dir, listaAux);
    }

    for(i = 0; i < *tamanho; i++)
    {
        imprime_lista((&listaAux->vetoraux[i].word));
    }
}

void Constroi(t_ordenacao *listaAux, int *tamanho)
{
    int esq;

    esq = *tamanho/2 + 1;

    while(esq > 1)
    {
        esq--;
        Refaz(esq, *tamanho, listaAux);
    }
}

void Refaz(int esq, int dir, t_ordenacao *listaAux)
{
    int j = esq*2;
    item_palavra aux = listaAux->vetoraux[esq].word;

    while(j <= dir)
    {
        if((j < dir) && (strcmp(listaAux->vetoraux[j].word.letra, listaAux->vetoraux[j+1].word.letra) < 0))
            j++;
        if(strcmp(listaAux->vetoraux[j].word.letra, aux.letra) >= 0)
            break;

        listaAux->vetoraux[esq] = listaAux->vetoraux[j];
        esq = j;
        j = esq*2;
    }
    listaAux->vetoraux[esq].word = aux;
}*/
/*fim HeapSort*/
