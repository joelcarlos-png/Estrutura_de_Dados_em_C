#include <stdio.h>
#include <stdlib.h>
#include "revisaoLS.h"

Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL){return NULL;}
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
    return l;
}

bool inserirFinal(Lista *l, TIPO valor){
    if(l == NULL){return false;}
    No *novo = malloc(sizeof(No));
    if(novo == NULL){return false;}
    novo->val = valor;
    novo->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
    return true;
}

bool inserirPos(Lista *l, TIPO valor, int indice){
    if(l == NULL || indice < 0 || indice > l->qtd){return false;}
    No *novo = malloc(sizeof(No));
    if(novo == NULL){return false;}
    novo->val = valor;
    novo->prox = NULL;
    if(indice == 0){
        novo->prox = l->inicio;
        l->inicio = novo;
        if(l->qtd == 0){l->fim = novo;}
    }else{
        No *atual = l->inicio;
        for(int i = 0; i < indice - 1; i++){
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
        if(indice == l->qtd){l->fim = novo;}
    }
    l->qtd++;
    return true;
}

bool remover(Lista *l, int indice, TIPO *valorRemovido){
    if(l == NULL || indice < 0 || indice >= l->qtd){return false;}
    No *rem;
    if(indice == 0){
        rem = l->inicio;
        l->inicio = rem->prox;
        if(l->qtd == 1){l->fim = NULL;}
    }else{
        No *atual = l->inicio;
        for(int i = 0; i < indice - 1; i++){
            atual = atual->prox;
        }
        rem = atual->prox;
        atual->prox = rem->prox;
        if(indice == l->qtd - 1){l->fim = atual;}
    }
    if(valorRemovido != NULL){*valorRemovido = rem->val;}
    free(rem);
    l->qtd--;
    return true;
}

bool isEmpty(Lista *l){
    if(l == NULL){return true;}
    return l->qtd == 0;
}

bool get(Lista *l, int indice, TIPO *valor){
    if(l == NULL || indice < 0 || indice >= l->qtd || valor == NULL){return false;}
    No *atual = l->inicio;
    for(int i = 0; i < indice; i++){
        atual = atual->prox;
    }
    *valor = atual->val;
    return true;
}

Lista *ordenacao(Lista *l){
    
}//1

void removerDuplicadas(Lista *l){

}//2

void substituirImpares(Lista *l){

}//3

void inverterLista(Lista *l){

}//4

void removerNo(No *A, No *B){

}//5

No *search(Lista *l){

}//7

No *insert(Lista *l, TIPO x){

}//8
