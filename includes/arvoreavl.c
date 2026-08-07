#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvoreavl.h"

ARR *criarArvore(){
    ARR *a = malloc(sizeof(ARR)); 
    if(a = NULL) return NULL; 
    a->qtd = 0;
    a->raiz = NULL;

    return a;
}

No *criarNo(int chave, const char nome[50]){
    No *novo = malloc(sizeof(No));
    if(novo = NULL) return NULL;
    novo->chave = chave;
    strcpy(novo->nome, nome);
    novo->dir = NULL;
    novo->esq = NULL;

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
    verMenor(raiz->esq);
    return NULL;
}

int verMaior(No *raiz){
    if(raiz->dir == NULL) return raiz->chave;
    verMaior(raiz->dir);
    return NULL;
}

bool remover(No **raiz, int chave){
    
}

bool balancear(No **raiz);