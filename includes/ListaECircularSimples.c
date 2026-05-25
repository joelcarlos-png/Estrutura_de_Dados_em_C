#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaECircularSimples.h"
#include "controle.h"
#include "cores.h"

//FUNCOES MAE
Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL) return NULL;
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

No *criarNo(TIPO val){
    No *novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return NULL;
    novoNo->prox = NULL;
    novoNo->val = val;

    return novoNo;
}

bool inserirFinal(Lista *l, float valor){
    if(l == NULL) return false;
    No *novoNo = criarNo(valor);
    if(novoNo == NULL) return false;

    if(isEmpty(l)){
        l->inicio = novoNo;
    }else{
        l->fim->prox = novoNo;
    }
    l->fim = novoNo;
    l->fim->prox = l->inicio;
    l->qtd++;

    return true;
}

bool inserirPos(Lista *l, float valor, int indice){
    if(l == NULL || indice < 0 || indice > l->qtd) return false;
    if(indice == 0 && isEmpty(l)){
        return inserirFinal(l, valor);
    }
    No *novoNo = criarNo(valor);
    if(novoNo == NULL) return false;

    if(indice == 0){
        novoNo->prox = l->inicio;
        if(l->qtd == 1){
            l->inicio->prox = novoNo;
            l->fim = l->inicio;
        }
        l->inicio = novoNo;
        l->fim->prox = l->inicio;
        l->qtd++;
        return true;
    }

    No *aux = l->inicio;
    for(int i = 0; i < indice - 1; i++){
        aux = aux->prox;
    }

    if(aux->prox == l->inicio){
        novoNo->prox = l->inicio;
        l->fim = novoNo;
    }else{
        novoNo->prox = aux->prox;
    }
    aux->prox = novoNo;
    l->qtd++;

    return true;
}

bool remover(Lista *l, int indice, TIPO *valorRemovido){
    if(l == NULL || isEmpty(l) || indice < 0 || indice >= l->qtd) return false;
    No *removido = l->inicio;

    if(indice == 0){
        *valorRemovido = removido->val;
        l->inicio = removido->prox;
        l->fim->prox = l->inicio;
        l->qtd--;
        free(removido);
        if(l->qtd <= 0){
            l->inicio = NULL;
            l->fim = NULL;
        }
        return true;
    }

    for(int i = 0; i < indice - 1; i++){
        removido = removido->prox;
    }

    No *aux = removido->prox;
    *valorRemovido = aux->val;
    removido->prox = aux->prox;
    free(aux);
    if(removido->prox == l->inicio){
        l->fim = removido;
    }
    l->qtd--;

    return true;
}

bool isEmpty(Lista *l){
    if(l == NULL) return true;
    return l->fim == NULL && l->inicio == NULL;
}

bool get(Lista *l, int indice, TIPO *valor){
    if(l == NULL || isEmpty(l) || indice < 0 || indice >= l->qtd) return false;
    No *aux = l->inicio;
    for(int i = 0; i < indice; i++){
        aux = aux->prox;
    }

    *valor = aux->val;
    return true;
}
//funcoes a parte
void painel(){
    printf("====OpcoesLista====\n");
    printf("1.Inserir          \n");
    printf("2.Remover          \n");
    printf("3.Consultar Posicao\n");
    printf("4.Size (B)         \n");
    printf("5.Clear (C)        \n");
    printf("6.Mostrar lista (D)\n");
    printf("7.Ordenar Lista (E)\n");
    printf("8.Sair             \n");
    printf("===================\n");
}

//Funcoes a parte
int sizeLista(Lista *l){
    if(isEmpty(l)) return 0;

    No *aux = l->inicio->prox;
    No *parada = l->inicio;

    int qnt = 0;
    while(aux != parada){
        qnt++;
        aux = aux->prox;
    }

    return qnt + 1;
}//b

bool clearLista(Lista *l){
    if(isEmpty(l)) return true;
    TIPO v;
    while(remover(l, 0, &v));
    return true;
}//c

void mostrarLista(Lista *l){
    if(l == NULL) return;
    TIPO v;
    printf(AZUL "Fila:" AMARELO "[");
    if(isEmpty(l)) printf(MAGENTA "--vazio--");
    for(int i = 0; i < l->qtd; i++){
        if(!get(l, i, &v)) return;
        printf(MAGENTA T_TIP, v);
        if(i != l->qtd - 1){
            printf(AMARELO ", ");
        }
    }
    printf(AMARELO "]\n" RESET);
}//d

bool ordenarLista(Lista *l){
    if(l == NULL || isEmpty(l)) return false;
    TIPO v1, v2;
    for(int i = 0; i < l->qtd - 1; i++){
        for(int j = 0; j < l->qtd - i - 1; j++){
            if(!get(l, j, &v1) || !get(l, j + 1, &v2)) return false;
            if(v1 > v2){
                if(!remover(l, j, &v1)) return false;
                if(!inserirPos(l, v1, j + 1)) return false;
            }
        }
    }
    return true;
}//e