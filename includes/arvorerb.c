#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvorerb.h"
#include "cores.h"

ARR *criarArvore(){
    ARR *new = malloc(sizeof(ARR));
    if(new == NULL) return NULL;
    new->raiz = NULL;

    return new;
}

No *criarNo(int val, No *pai){
    No *new = malloc(sizeof(No));
    new->cor = VERMELHA;
    new->valor = val;
    new->dir = NULL;
    new->esq = NULL;
    new->pai = pai;

    return new;
}

//func padrao

static void inserirParci(No **raiz, int valor, No *pai, No **raizArvore){
    if(*raiz == NULL){
        No *new = criarNo(valor, pai);
        *raiz = new;
        repair(raiz, raizArvore); 
    }else if (valor > (*raiz)->valor)inserirParci(&(*raiz)->dir, valor, *raiz, raizArvore);
    else if (valor < (*raiz)->valor) inserirParci(&(*raiz)->esq, valor, *raiz, raizArvore);
    else return;
}

void inserir(No **raiz, int valor){
    if(*raiz == NULL){
        No *new = criarNo(valor, NULL);
        new->cor = PRETA;
        *raiz = new;
    }else if (valor > (*raiz)->valor)inserirParci(&(*raiz)->dir, valor, *raiz, raiz);
    else if (valor < (*raiz)->valor) inserirParci(&(*raiz)->esq, valor, *raiz, raiz);
    else return;
}

void caso1(No *pai, No *avo, No *tio, No **raizArvore){
    pai->cor = tio->cor = PRETA;
        if(avo->pai == NULL){
            avo->cor = PRETA;
            return;
        }else{
            avo->cor = VERMELHA;
            if(avo->pai->cor == VERMELHA){
                repair(&avo, raizArvore);
            }
        }
}

void caso2(No **linkPai, bool giraEsq){ 
    if(giraEsq) rotacaoEsq(linkPai);
    else rotacaoDir(linkPai);
}

void caso3(No *sobe, No *avo, No **linkAvo, bool giraEsq){
    sobe->cor = PRETA;
    avo->cor = VERMELHA;
    if(giraEsq) rotacaoDir(linkAvo);
    else rotacaoEsq(linkAvo);
}

void repair(No **raiz, No **raizArvore){
    if((*raiz)->pai == NULL || (*raiz)->pai->cor == PRETA) return;

    No *filho = *raiz;
    No *pai = filho->pai;
    No *avo = pai->pai;
    No *tio = (avo->esq == pai) ? avo->dir : avo->esq;

    No **linkPai = (avo->esq == pai) ? &(avo->esq) : &(avo->dir);
    No **linkAvo = (avo->pai == NULL) ? raizArvore: ((avo->pai->esq == avo) ? &(avo->pai->esq) : & (avo->pai->dir));

    bool paiEsq = (avo->esq == pai);
    bool filhoDir = (pai->dir == filho);

    if(tio != NULL && tio->cor == VERMELHA) caso1(pai, avo, tio, raizArvore);//case 1
    else if(paiEsq && filhoDir){caso2(linkPai, true); caso3(filho, avo, linkAvo, true); }
    else if(!paiEsq && !filhoDir){ caso2(linkPai, false); caso3(filho, avo, linkAvo, false); }//case 2
    else if(paiEsq && !filhoDir) caso3(pai, avo, linkAvo, true); //case 3
    else caso3(pai, avo, linkAvo, false);
}

//Balanceamento
void rotacaoDir(No **raiz){
    if(raiz == NULL || *raiz == NULL || (*raiz)->esq == NULL) return;
    No *Y = *raiz;
    No *X = Y->esq;
    No *B = X->dir;
    No *paiAnt = Y->pai;

    Y->esq = B;
    X->dir = Y;

    Y->pai = X;
    X->pai = paiAnt;
    if(B != NULL) B->pai = Y;

    *raiz = X;
}

void rotacaoEsq(No **raiz){
    if(raiz == NULL || *raiz == NULL || (*raiz)->dir == NULL) return;
    No *X = *raiz;
    No *Y = X->dir;
    No *B = Y->esq;
    No *paiAnt = X->pai;

    X->dir = B;
    Y->esq = X;

    X->pai = Y;
    Y->pai = paiAnt;
    if(B != NULL) B->pai = X;

    *raiz = Y;
}

//percursos
void preOrdem(No *raiz){
    if(raiz == NULL) return;
    printf(AMARELO "%d " RESET, raiz->valor);
    emOrdem(raiz->esq);
    emOrdem(raiz->dir);
}
void emOrdem(No *raiz){
    if(raiz == NULL) return;
    emOrdem(raiz->esq);
    printf(AMARELO "%d " RESET, raiz->valor);
    emOrdem(raiz->dir);
}
void posOrdem(No *raiz){
    if(raiz == NULL) return;
    emOrdem(raiz->esq);
    emOrdem(raiz->dir);
    printf(AMARELO "%d " RESET, raiz->valor);
}

void percursos(No *raiz){
    printf(VERDE "==========Percursos==========\n" 
    VERMELHO "Pre-Ordem: ");
    preOrdem(raiz);
    printf(VERMELHO "\nEm-Ordem: ");
    emOrdem(raiz);
    printf(VERMELHO "\nPos-Ordem: ");
    posOrdem(raiz);
}

//func exercicio
void parPreto(No *raiz){
    if(raiz == NULL) return;
    parPreto(raiz->esq);
    if(raiz->valor % 2 == 0 && raiz->cor == PRETA) printf(AMARELO "%d " RESET, raiz->valor);
    parPreto(raiz->dir);
}

static void qntImparVermelhoParci(No *raiz, int *qnt){
    if(raiz == NULL) return;
    qntImparVermelhoParci(raiz->esq, qnt);
    if(raiz->valor % 2 != 0 && raiz->cor == VERMELHA) (*qnt)++;
    qntImparVermelhoParci(raiz->dir, qnt);
}

void qntImparVermelho(No *raiz){
    int qnt = 0;
    qntImparVermelhoParci(raiz, &qnt);
    printf("Quantidade de Impares Vermelhos: "AMARELO "%d" RESET, qnt);
}
