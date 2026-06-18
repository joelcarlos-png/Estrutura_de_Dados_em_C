#ifndef REVISAOLD_H
#define REVISAOLD_H

#include <stdbool.h>

typedef int TIPO;
#define T_ "%d"

typedef struct no{
    TIPO val;
    struct no *prox;
    struct no *ante; 
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Lista;

Lista *criarLista();//
No *criarNo(TIPO valor);//
bool inserirFinal(Lista *l, TIPO valor);//
bool inserirPos(Lista *l, TIPO valor, int indice);//
bool remover(Lista *l, TIPO *valorRemovido, int indice);//
bool isEmpty(Lista *l);//
bool get(Lista *l, TIPO *valorConsulta, int indice);//

void troca(Lista *l, int indice1, int indice2); //6

//9
bool pertinencia(Lista *l);
Lista *intersecao(Lista *a, Lista *b);
Lista *diferenca(Lista *a, Lista *b);
Lista *uniao(Lista *a, Lista *b);

#endif
