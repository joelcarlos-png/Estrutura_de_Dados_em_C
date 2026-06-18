#include <stdio.h>
#include <stdlib.h>
#include "revisaoLD.h"

Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL){return NULL;}
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
    return l;
}

No *criarNo(TIPO valor){
    No *n = malloc(sizeof(No));
    if(n == NULL){return NULL;}
    n->val = valor;
    n->prox = NULL;
    n->ante = NULL;
    return n;
}

bool inserirFinal(Lista *l, TIPO valor){
    if(l == NULL){return false;}
    No *novo = criarNo(valor);
    if(novo == NULL){return false;}
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        novo->ante = l->fim;
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
    return true;
}

bool inserirPos(Lista *l, TIPO valor, int indice){
    if(l == NULL || indice < 0 || indice > l->qtd){return false;}
    No *novo = criarNo(valor);
    if(novo == NULL){return false;}
    if(indice == 0){
        novo->prox = l->inicio;
        if(l->inicio != NULL){l->inicio->ante = novo;}
        l->inicio = novo;
        if(l->qtd == 0){l->fim = novo;}
    }else if(indice == l->qtd){
        novo->ante = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }else{
        No *atual = l->inicio;
        for(int i = 0; i < indice; i++){
            atual = atual->prox;
        }
        novo->prox = atual;
        novo->ante = atual->ante;
        atual->ante->prox = novo;
        atual->ante = novo;
    }
    l->qtd++;
    return true;
}

bool remover(Lista *l, TIPO *valorRemovido, int indice){
    if(l == NULL || indice < 0 || indice >= l->qtd){return false;}
    No *rem;
    if(indice == 0){
        rem = l->inicio;
        l->inicio = rem->prox;
        if(l->inicio != NULL){l->inicio->ante = NULL;}
        if(l->qtd == 1){l->fim = NULL;}
    }else if(indice == l->qtd - 1){
        rem = l->fim;
        l->fim = rem->ante;
        l->fim->prox = NULL;
    }else{
        rem = l->inicio;
        for(int i = 0; i < indice; i++){
            rem = rem->prox;
        }
        rem->ante->prox = rem->prox;
        rem->prox->ante = rem->ante;
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

bool get(Lista *l, TIPO *valorConsulta, int indice){
    if(l == NULL || indice < 0 || indice >= l->qtd || valorConsulta == NULL){return false;}
    No *atual = l->inicio;
    for(int i = 0; i < indice; i++){
        atual = atual->prox;
    }
    *valorConsulta = atual->val;
    return true;
}

void troca(Lista *l, int indice1, int indice2){
    if(l == NULL || indice1 < 0 || indice2 < 0 || indice1 >= l->qtd || indice2 >= l->qtd){ return;}
    if(indice1 == indice2){return;}

    int menor = indice1 < indice2 ? indice1 : indice2;
    int maior = indice1 < indice2 ? indice2 : indice1;
    
    TIPO val;
    remover(l, &val, menor);
    inserirPos(l, val, maior);
    remover(l, &val, maior - 1);
    inserirPos(l, val, menor);
}//6

bool pertinencia(Lista *l){
    
}

Lista *intersecao(Lista *a, Lista *b){

}

Lista *diferenca(Lista *a, Lista *b){

}

Lista *uniao(Lista *a, Lista *b){

}//9
