#include <stdio.h>
#include <stdlib.h>
#include "arvoreparci.h"

ARR *criarARR(){
    ARR *a = malloc(sizeof(ARR));
    if(a == NULL) return NULL;
    a->qtd = 0;
    a->raiz = NULL; 

    return a;
}

No *criarNo(double val){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return NULL;
    novo->chave = val;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

void inserir(No **raiz, double val){
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

double verMenor(No **raiz){
    if((*raiz)->esq == NULL){
        return (*raiz)->chave;
    }else{
        return verMenor(&(*raiz)->esq);
    }
}

double verMaior(No **raiz){
    if((*raiz)->dir == NULL){
        return (*raiz)->chave;
    }else{
        return verMaior(&(*raiz)->dir);
    }
}

void preordem(No **raiz){
    if (raiz != NULL && *raiz != NULL) {
        printf("%.2f ", (*raiz)->chave);
        preordem(&((*raiz)->esq));
        preordem(&((*raiz)->dir));
    }
}

void emordem(No **raiz){
    if (raiz != NULL && *raiz != NULL) {
        emordem(&((*raiz)->esq));
        printf("%.2f ", (*raiz)->chave);
        emordem(&((*raiz)->dir));
    }
}

void posordem(No **raiz){
    if (raiz != NULL && *raiz != NULL) {
        posordem(&((*raiz)->esq));
        posordem(&((*raiz)->dir));
        printf("%.2f ", (*raiz)->chave);
    }
}

void exibirPercursos(No **raiz){
    printf("Pré-Ordem: \n");
    preordem(&(*raiz));
    printf("\nEm-Ordem: \n");
    emordem(&(*raiz));
    printf("\nPos-Ordem: \n");
    posordem(&(*raiz));
}

void procurar(No **raiz, double busca){
    if (raiz == NULL || *raiz == NULL) {
        printf("Valor %.2f nao encontrado.\n", busca);
        return;
    }
    if((*raiz)->chave == busca){
        printf("%.2f", (*raiz)->chave);
    }else{
        if(busca > (*raiz)->chave){
            procurar(&(*raiz)->dir, busca);
        }else if (busca < (*raiz)->chave){
            procurar(&(*raiz)->esq, busca);
        }
    }
}

void excluir(No **raiz, double valor){
    if (*raiz == NULL) return;
    if((*raiz)->chave == valor){
        No *aux = *raiz;
        if((*raiz)->esq != NULL && (*raiz)->dir == NULL){
            *raiz = (*raiz)->esq;
            free(aux);
        }else if((*raiz)->esq == NULL && (*raiz)->dir != NULL){
            *raiz = (*raiz)->dir;
            free(aux);
        }else if((*raiz)->esq != NULL && (*raiz)->dir != NULL){
            double var = verMenor(&(*raiz)->dir);
            (*raiz)->chave = var;
            excluir(&(*raiz)->dir, var);
        }else{
            *raiz = NULL;
            free(aux);
        }
    }else{
        if(valor > (*raiz)->chave){
            excluir(&(*raiz)->dir, valor);
        }else if (valor < (*raiz)->chave){
            excluir(&(*raiz)->esq, valor);
        }
    }
}