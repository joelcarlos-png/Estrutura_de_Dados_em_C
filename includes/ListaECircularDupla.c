#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaECircularDupla.h"
#include "controle.h"
#include "cores.h"

//Funcoes maes
Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL) return NULL;
    l->fim = NULL;
    l->inicio = NULL;
    l->qtd = 0;

    return l;
}

No *cirarNo(TIPO valor){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return NULL;
    novo->val = valor;
    novo->prox = NULL;
    novo->ante = NULL;

    return novo;
}

bool inserirFinal(Lista *l, TIPO valor){
    if(l == NULL) return false;
    No *novo = cirarNo(valor);
    if(novo == NULL) return false;

    if(isEmpty(l)){
        l->inicio = novo;
    }else{
        l->fim->prox = novo;
        novo->ante = l->fim;
    }
    l->fim = novo;
    l->fim->prox = l->inicio;
    l->inicio->ante = l->fim;

    l->qtd++;

    return true;
}

bool inserirPos(Lista *l, TIPO valor, int indice){
    if(l == NULL || indice < 0 || indice > l->qtd) return false;
    if(isEmpty(l) && indice == 0){
        inserirFinal(l, valor);
        return true;
    }

    if(indice == l->qtd){
        inserirFinal(l, valor);
        return true;
    }

    No *novo = cirarNo(valor);
    if(novo == NULL) return false;

    if(indice == 0){
        novo->prox = l->inicio;
        novo->ante = l->fim;
        l->fim->prox = novo;
        l->inicio->ante = novo;
        l->inicio = novo;
        l->qtd++;

        return true;
    }

    No *aux = l->inicio;
    for(int i = 0; i < indice; i++){
        aux = aux->prox;
    }

    novo->prox = aux;
    novo->ante = aux->ante;
    aux->ante->prox = novo;
    aux->ante = novo;
    l->qtd++;

    return true;
}

bool remover(Lista *l, TIPO *valorRemovido, int indice){
    if(l == NULL || isEmpty(l) || indice < 0 || indice >= l->qtd) return false;
    
    if(indice == 0){
        No *aux = l->inicio;
        *valorRemovido = aux->val;
        if(l->qtd != 1){
            l->inicio = aux->prox;
            l->inicio->ante = l->fim;
            l->fim->prox = l->inicio;
        }else{
            l->fim = NULL;
            l->inicio = NULL;
        }
        l->qtd--;
        free(aux);
        return true;
    }
    
    No *aux = l->inicio;      
    for(int i = 0; i < indice; i++){
        aux = aux->prox;
    }
    
    *valorRemovido = aux->val;
    aux->ante->prox = aux->prox;
    aux->prox->ante = aux->ante;
    if(indice == l->qtd - 1) l->fim = aux->ante;
    free(aux);
    l->qtd--;
    return true;
}

bool isEmpty(Lista *l){
    return l == NULL || l->qtd == 0;
}

bool get(Lista *l, TIPO *valorConsulta, int indice){
    if(l == NULL || valorConsulta == NULL || isEmpty(l) || indice < 0 || indice >= l->qtd) return false;
    No *aux;
    if(indice > (l->qtd - 1) / 2){
        aux = l->fim;
        for(int i = l->qtd - 1; i > indice; i--) aux = aux->ante;
    }else{
        aux = l->inicio;
        for(int i = 0; i < indice; i++) aux = aux->prox;
    }
    *valorConsulta = aux->val;
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
 
//Funcoes fo exercicio
int sizeLista(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;

    No *ini = l->inicio;
    No *aux = l->inicio->prox;
    int qnt = 1;
    while(ini != aux){
        qnt++;
        aux = aux->prox;
    }

    return qnt;
}//b

bool clearLista(Lista *l){
    if(l == NULL || isEmpty(l)) return true;
    TIPO v;
    while(remover(l, &v, 0));
    return true;
}//c

bool mostrarLista(Lista *l){
    if(l == NULL) return false;
    TIPO v;
    printf(AZUL "Lista:" AMARELO "[");
    if(isEmpty(l)) printf(MAGENTA "--vazio--");
    int tam = sizeLista(l);
    for(int i = 0; i < tam; i++){
        if(!get(l, &v, i)) return false;
        printf(MAGENTA T_TIPO, v);
        if(i != tam - 1){
            printf(AMARELO ", ");
        }
    }
    printf(AMARELO "]\n" RESET);
    return true;
}//d

bool ordenarLista(Lista *l){
    if(l == NULL || isEmpty(l)) return false;
    TIPO v1, v2;
    int tam = sizeLista(l);
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(!get(l, &v1, j) || !get(l, &v2, j + 1)) return false;
            if(v1 > v2){
                if(!remover(l, &v1, j)) return false;
                if(!inserirPos(l, v1, j + 1)) return false;
            }
        }
    }
    return true;
}//e