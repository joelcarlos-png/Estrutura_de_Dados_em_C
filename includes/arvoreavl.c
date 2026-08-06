#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvoreavl.h"

ARR *criarArvore(){
    ARR *a = malloc(sizeof(ARR));
    if(a = NULL) return NULL;
    a->qtd = 0;
    a->raiz = NULL;

    return a;
}

No *criarNo(int val){
    No *novo = malloc(sizeof(No));
    if(novo = NULL) return NULL;
    novo->chave = val;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

bool inserir(No **raiz, int val){
    if(*raiz == NULL){
        No *novo = criarNo(val);
        *raiz = novo;
    }else if(val > (*raiz)->chave){
        inserir(&(*raiz)->dir, val);
    }else if(val < (*raiz)->chave){
        inserir(&(*raiz)->esq, val);
    }else{
        return;
    }
}

bool remover(No **raiz, int val){
    
}

bool balancear(No **raiz);