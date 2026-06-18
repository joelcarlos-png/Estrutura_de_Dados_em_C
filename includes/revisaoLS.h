#ifndef REVISAOLS_H
#define REVISAOLS_H

#include <stdbool.h>

typedef float TIPO;
#define T_ "%.2f"

typedef struct no{
    TIPO val;
    struct no *prox;
}No;

typedef struct{ 
    No *inicio;
    No *fim;
    int qtd;
}Lista;

Lista *criarLista();
bool inserirFinal(Lista *l, TIPO valor);
bool inserirPos(Lista *l, TIPO valor, int indice);
bool remover(Lista *l, int indice, TIPO *valorRemovido);
bool isEmpty(Lista *l);
bool get(Lista *l, int indice, TIPO *valor);

Lista *ordenacao(Lista *l); //1 
void removerDuplicadas(Lista *l); //2
void substituirImpares(Lista *l);//3
void inverterLista(Lista *l);//4
void removerNo(No *A, No *B);//5
No *search(Lista *l);//7
No *insert(Lista *l, TIPO x);//8

#endif
