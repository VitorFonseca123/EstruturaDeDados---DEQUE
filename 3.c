#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*

*/
typedef struct estrutura
{
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;
typedef struct
{
    NO *inicio1;
    NO *inicio2;
} DEQUE;

void inicializarDeque(DEQUE *d)
{
    d->inicio1 = NULL;
    d->inicio2 = NULL;
}
int tamanhoDeque(DEQUE d)
{
    NO *p = d.inicio1;
    int tam = 0;
    while (p)
    {
        tam++;
        p = p->prox;
    }
    return (tam);
}
void entrarDeque1(int ch, DEQUE *d)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->ant = NULL;
    novo->prox = d->inicio1;
    if (d->inicio1)
        d->inicio1->ant = novo; // já contém dados
    else
        d->inicio2 = novo; // 1a. inserção
    d->inicio1 = novo;
}
void inserir2(DEQUE *d, int ch)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    novo->ant = d->inicio2;

    if (d->inicio2)
    {
        d->inicio2->prox = novo;
    }
    else
    {
        d->inicio1 = novo;
        d->inicio2 = novo;
    }
}
void exibirD1(DEQUE d)
{
    NO *p = d.inicio1;
    while (p)
    {
        printf("%d ", p->chave);
        p = p->prox;
    }
}
int main()
{
    int v[5] = {1, 2, 3, 4, 5};
    DEQUE d;
    inicializarDeque(&d);

    inserir2(&d, 0);
    exibirD1(d);
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        entrarDeque1(v[i], &d);
    }
    exibirD1(d);
    inserir2(&d, 5);
    printf("\n");
    exibirD1(d);

    return 0;
}