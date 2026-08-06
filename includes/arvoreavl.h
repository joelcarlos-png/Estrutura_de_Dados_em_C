#ifndef ARVOREPARCI_H
#define ARVOREPARCI_H

#include <stdbool.h>

typedef struct no{
    int chave;
    struct no *esq, *dir;
}No;

typedef struct{
    No *raiz;
    int qtd;
}ARR;

ARR *criarArvore();
No *criarNo(int val);

bool inserir(No **raiz, int val);
bool remover(No **raiz, int val);

bool balancear(No **raiz);

#endif