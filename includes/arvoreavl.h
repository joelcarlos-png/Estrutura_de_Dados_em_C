#ifndef ARVOREPARCI_H
#define ARVOREPARCI_H

#include <stdbool.h>

typedef struct no{ 
    int chave;
    const char nome[50];
    struct no *esq, *dir;
}No;
 
typedef struct{
    No *raiz;
    int qtd;
}ARR;

ARR *criarArvore();
No *criarNo(int val);

void inserir(No **raiz, int chave, const char nome[50]);
bool remover(No **raiz, int chave);
const char get(No *raiz, int chave);
No verMenor(No *raiz);
No verMaior(No *raiz);

bool balancear(No **raiz);

#endif