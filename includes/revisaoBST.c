#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "revisaoBST.h"

ABB *criarArvore(){
    ABB *a = malloc(sizeof(ABB));
    if(a == NULL){return NULL;}
    a->raiz = NULL;
    a->qtd = 0;
    return a;
}

No *criarNo(const char *nome, int chave){
    No *n = malloc(sizeof(No));
    if(n == NULL){return NULL;}
    strcpy(n->nome, nome);
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

bool inserir(No **raiz, const char *nome, int chave){
    if((*raiz) == NULL){
        *raiz = criarNo(nome, chave);
        return true;
    }

    if(chave < (*raiz)->chave) return inserir(&(*raiz)->esq, nome, chave);
    else if(chave > (*raiz)->chave) return inserir(&(*raiz)->dir, nome, chave);
    return false;
}//a

No *procurar(No *raiz, int chavep){
    if(raiz == NULL) return NULL;
    if(raiz->chave == chavep) return raiz;
    if(chavep < raiz->chave) return procurar(&raiz->esq, chavep);
    else if(chavep > raiz->chave) return procurar(&raiz->dir, chavep);
}//b

int verifMenor(No *raiz){
    if(raiz == NULL) return -1;
    if(raiz->esq == NULL) return raiz->chave;
    return verifMenor(raiz->esq);
}//c

int verifMaior(No *raiz){
    if(raiz == NULL) return -1;
    if(raiz->dir == NULL) return raiz->chave;
    return verifMenor(raiz->dir);
}//d

void preordem(No *raiz){
    if (raiz != NULL) {
        printf("%.2f ", raiz->chave);
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

void emordem(No *raiz){
    if (raiz != NULL) {
        emordem(raiz->esq);
        printf("%.2f ", raiz->chave);
        emordem(raiz->dir);
    }
}

void posordem(No *raiz){
    if (raiz != NULL) {
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf("%.2f ", raiz->chave);
    }
}

void exibirPercursos(No *raiz){
    printf("Pré-Ordem: \n");
    preordem(raiz);
    printf("\nEm-Ordem: \n");
    emordem(raiz);
    printf("\nPos-Ordem: \n");
    posordem(raiz);
}//e

bool remover(No **raiz){
    
}//f
