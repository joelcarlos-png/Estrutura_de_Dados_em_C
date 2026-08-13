#ifndef ARVOREPARCI_H
#define ARVOREPARCI_H

#include <stdbool.h>

typedef struct no{
    int chave;
    char nome[50];
    int altura;
    struct no *esq, *dir;
}No;
 
typedef struct{
    No *raiz;
    int qtd;
}ARR;

ARR *criarArvore();
No *criarNo(int val, const char nome[50]);

void inserir(No **raiz, int chave, const char nome[50]);
void remover(No **raiz, int chave);
const char *get(No *raiz, int chave);
int verMenor(No *raiz);
int verMaior(No *raiz);

bool balancear(No **raiz);
int altura(No *n);
int fatorBalanceamento(No *n);
void rotacaoDir(No **raiz);
void rotacaoEsq(No **raiz);

#endif