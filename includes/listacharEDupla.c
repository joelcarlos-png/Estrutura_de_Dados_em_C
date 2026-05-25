#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listacharedupla.h"

Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL) return NULL;
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

No *criarNo(char valor){
    No *novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return NULL;
    novoNo->ante = NULL;
    novoNo->prox = NULL;
    novoNo->val = valor;

    return novoNo;
}

bool inserir(Lista *l, char valor){
    No *novoNo = criarNo(valor);
    if(novoNo == NULL) return false;
    
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
    if(indice < 0  || indice > l->qtd){return false;}
    
    if(indice == 0){
        if(isEmpty(l)){
            if(!inserir(l, valor)) return false;
            return true;
        }
        No *novoNo = criarNo(valor);

        l->inicio->ante = novoNo;
        novoNo->prox = l->inicio;
        l->inicio = novoNo;
        l->qtd++;
        return true;
    }
    
    No *aux = l->inicio;
    No *aux2 = l->inicio->prox;
    for(int i = 0; i != indice - 1; i++){
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    No *novoNo = criarNo(valor);
    
    novoNo->ante = aux;
    novoNo->prox = aux2;
    aux->prox = novoNo;
    if(aux2 != NULL){
        aux2->ante = novoNo;
    }
    
    if(novoNo->prox == NULL){
        l->fim = novoNo;
    }

    l->qtd++;
    return true;
}

bool remover(Lista *l, int indice){
    
}

bool isEmpty(Lista *l){
    if(l->inicio == NULL && l->fim == NULL){
        return true;
    }
    return false;
}

bool get(Lista *l, int indice, int *valorGet){
    if(isEmpty(l) || indice < 0  || indice > l->qtd){return false;}
    No *aux = l->inicio;
    for(int i = 0; i != indice; i++){
        aux = aux->prox;
    }
    
    *valorGet = aux->val;
    return true;
}

//Funcoes a parte
void mostrarLista(Lista *l){
    printf("[");
    No *aux = l->inicio;
    while(aux != NULL){
        printf("%c ", aux->val);
        if(aux->prox != NULL){
            printf(",");
        }
        aux = aux->prox;
    }
    printf("]\n");
}

bool sizeLista(Lista *l, int *tamanhoRemovido);//b
bool clearLista(Lista *l);//c
int verPares(Lista *l);//d
int verQntMaiores(Lista *l, int numero);//e
int verQntPrimos(Lista *l);//f
Lista *listaComPares(Lista *l);//g
Lista *ordenarDuasListas(Lista *l1, Lista *l2);//h
void mostrarListaInversa(Lista *l);//i
bool removerPares(Lista *l);//j
Lista *listaComImpares(Lista *l);//k
char verMaior(Lista *l);//l
char verMenor(Lista *l);//m
bool trocarPosicao(Lista *l, int indice1, int indice2);//n
bool verificarIgualdade(Lista *l1, Lista *l2);//o
