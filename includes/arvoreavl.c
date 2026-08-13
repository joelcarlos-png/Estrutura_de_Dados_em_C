#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "arvoreavl.h"

static int maxInt(int a, int b){ return (a > b) ? a : b; }

static void atualizarAltura(No *n){
    if(n == NULL) return;
    n->altura = 1 + maxInt(altura(n->esq), altura(n->dir));
}

ARR *criarArvore(){
    ARR *a = malloc(sizeof(ARR)); 
    if(a == NULL) return NULL; 
    a->qtd = 0;
    a->raiz = NULL;

    return a;
}

No *criarNo(int chave, const char nome[50]){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return NULL;
    novo->chave = chave;
    strcpy(novo->nome, nome);
    novo->dir = NULL;
    novo->esq = NULL;
    novo->altura = 1;

    return novo;
}

void inserir(No **raiz, int chave, const char nome[50]){
    if(*raiz == NULL){
        No *novo = criarNo(chave, nome);
        *raiz = novo;
    }else if(chave > (*raiz)->chave){
        inserir(&(*raiz)->dir, chave, nome);
    }else if(chave < (*raiz)->chave){
        inserir(&(*raiz)->esq, chave, nome);
    }else{
        return;
    }

    atualizarAltura(*raiz);
    balancear(raiz);
}

const char *get(No *raiz, int chave){
    if(raiz == NULL) return NULL;
    if(raiz->chave == chave) return raiz->nome;
    else if(chave > raiz->chave)return get(raiz->dir, chave);
    else if(chave < raiz->chave)return get(raiz->esq, chave);
    else return NULL;
}

int verMenor(No *raiz){
    if(raiz->esq == NULL) return raiz->chave;
    return verMenor(raiz->esq);
}

int verMaior(No *raiz){
    if(raiz->dir == NULL) return raiz->chave;
    return verMaior(raiz->dir);
}

void remover(No **raiz, int val){
    if(*raiz == NULL) return;
    if((*raiz)->chave == val){
        No *aux = *raiz;
        if((*raiz)->esq != NULL && (*raiz)->dir == NULL){
            *raiz = (*raiz)->esq;
            free(aux);
            atualizarAltura(*raiz);
            balancear(raiz);
        }else if((*raiz)->esq == NULL && (*raiz)->dir != NULL){
            *raiz = (*raiz)->dir;
            free(aux);
            atualizarAltura(*raiz);
            balancear(raiz);
        }else if((*raiz)->esq != NULL && (*raiz)->dir != NULL){
            int var = verMenor((*raiz)->dir);
            (*raiz)->chave = var;
            remover(&(*raiz)->dir, var);
            atualizarAltura(*raiz);
            balancear(raiz);
        }else{
            *raiz = NULL;
            free(aux);
            atualizarAltura(*raiz);
            balancear(raiz);
        }
    }else{
        if(val > (*raiz)->chave){
            remover(&(*raiz)->dir, val);
        }else if (val < (*raiz)->chave){
            remover(&(*raiz)->esq, val);
        }
        atualizarAltura(*raiz);
        balancear(raiz);
    }
}

int altura(No *n){
    if(n == NULL) return 0;
    else return n->altura;
}

int fatorBalanceamento(No *n){
    if(n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}


void rotacaoDir(No **raiz){
    No *y  = *raiz;
    No *x  = y->esq;
    No *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    *raiz = x;        
}

void rotacaoEsq(No **raiz){
    No *x  = *raiz;
    No *y  = x->dir;
    No *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    *raiz = y;
}

bool balancear(No **raiz){
    if(*raiz == NULL) return true;

    int fb = fatorBalanceamento(*raiz);

    if(fb > 1){                                  
        int fbEsq = fatorBalanceamento((*raiz)->esq);
        if(fbEsq < 0){                            
            rotacaoEsq(&(*raiz)->esq);         
        }
        rotacaoDir(raiz);                     
    }
    else if(fb < -1){                       
        int fbDir = fatorBalanceamento((*raiz)->dir);
        if(fbDir > 0){                          
            rotacaoDir(&(*raiz)->dir);         
        }
        rotacaoEsq(raiz);                        
    }

    return true;
}