#ifndef REVISAOBST_H
#define REVISAOBST_H

#include <stdbool.h>

typedef struct no{
    char nome[50];
    int chave;
    struct no *dir, *esq;
}No;

typedef struct{ 
    No *raiz;
    int qtd;
}ABB;

ABB *criarArvore();
No *criarNo(const char *nome, int chave);
bool inserir(No **raiz, const char *nome, int chave);//a
No *procurar(No **raiz, int chave);//b
int verifMenor(No **raiz);//c
int verifMaior(No **raiz);//d
void exibirPercursos(No **raiz);//e
bool remover(No **raiz);//f

#endif
