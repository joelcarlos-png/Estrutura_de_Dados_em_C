#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvorerb.h"
#include "cores.h"

ARR *criarArvore(){
    ARR *new = malloc(sizeof(ARR));
    if(new == NULL) return NULL;
    new->qtd = 0;
    new->raiz = NULL;

    return new;
}

No *criarNo(int val, No *pai){
    No *new = malloc(sizeof(No));
    new->altura;
    new->cor = VERMELHA;
    new->valor = val;
    new->dir = NULL;
    new->esq = NULL;
    new->pai = NULL;

    return new;
}

//func padrao

static void ;
void inserir(No **raiz, int valor){
    if(*raiz == NULL){
        No *new = criarNo(valor, NULL);
        *raiz = new;
    }else if (valor > (*raiz)->valor)inserir((*raiz)->dir, valor);
    else if (valor < (*raiz)->valor) inserir((*raiz)->esq, valor);
    else return;
}

void repair(No **raiz){

}

//Balanceamento
void rotacaoDir(No **raiz);
void rotacaoEsq(No **raiz);

//percursos
void preOrdem(No *raiz){
    if(raiz = NULL) return;
    printf(AMARELO "%d" RESET, raiz->valor);
    emOrdem(raiz->esq);
    emOrdem(raiz->dir);
}
void emOrdem(No *raiz){
    if(raiz = NULL) return;
    emOrdem(raiz->esq);
    printf(AMARELO "%d" RESET, raiz->valor);
    emOrdem(raiz->dir);
}
void posOrdem(No *raiz){
    if(raiz = NULL) return;
    emOrdem(raiz->esq);
    emOrdem(raiz->dir);
    printf(AMARELO "%d" RESET, raiz->valor);
}

void percursos(No *raiz){
    printf(VERDE "==========Percursos==========\n" 
    VERMELHO "Pre-Ordem:\n");
    preOrdem(raiz);
    printf(VERMELHO "Em-Ordem:\n");
    emOrdem(raiz);
    printf(VERMELHO "Pos-Ordem:\n");
    posOrdem(raiz);
}

//func exercicio
void parPreto(No *raiz);
void qntImparVermelho(No *raiz);
