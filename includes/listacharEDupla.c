#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listacharedupla.h"

Lista *criarLista(int tamanho){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

bool inserir(Lista *l, char valor){
    No *novoNo = malloc(sizeof(No));
    novoNo->val = valor;
    
    if(isEmpty(l)){
        l->inicio = novoNo;
    }else{
        l->fim->prox = novoNo;
        novoNo->ante = l->fim;
    }
    l->fim = novoNo;

    l->qtd++;

    return true;
}


bool inserirPosicao(Lista *l,char valor, int indice){
    if(isEmpty(l) || indice < 0  || indice > l->qtd){return false;}
    No *aux = l->inicio;
    No *aux2 = l->inicio->prox;
    for(int i = 0; i < l->qtd; i++){
        if(indice == i - 1){
            break;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    No *novoNo = malloc(sizeof(No));
    novoNo->val = valor;

    novoNo->ante = aux;
    novoNo->prox = aux2;
    aux->prox = novoNo;
    if(aux2 != NULL){
        aux2->ante = novoNo;
    }
    
    if(novoNo->prox == NULL){
        l->fim = novoNo;
    }
}

bool isEmpty(Lista *l){
    if(l->inicio == NULL && l->fim == NULL){
        return true;
    }
    return false;
}

void get(Lista *l, int indice);

void mostrarLista(Lista *l);