#ifndef ARVOREPARCI_H
#define ARVOREPARCI_H

#include <stdbool.h>

#define PRETA 10
#define VERMELHA 20

typedef struct no{
    int valor;
    int cor;
    struct no *esq, *dir, *pai;
}No;
 
typedef struct{
    No *raiz;
}ARR;

ARR *criarArvore();
No *criarNo(int val, No *pai);

//func padrao
void inserir(No **raiz, int valor);
void repair(No **raiz, No **raizArvore);

//percursos
void percursos(No *raiz);
    void emOrdem(No *raiz);
    void preOrdem(No *raiz);
    void posOrdem(No *raiz);

//Balanceamento
void rotacaoDir(No **raiz);
void rotacaoEsq(No **raiz);

//func exercicio
void parPreto(No *raiz);
void qntImparVermelho(No *raiz);

#endif