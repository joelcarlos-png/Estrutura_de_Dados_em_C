#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listacharE.h"

//Funcoes Maes
Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL) return NULL;
    l->fim = NULL;
    l->inicio = NULL;
    l->qtd = 0;

    return l;
}
 
No *criarNo(char valor){
    No *novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return NULL;
    novoNo->val = valor;
    novoNo->prox = NULL;

    return novoNo;
}

bool inserir(Lista *l, char valor){
    No *novoNo = criarNo(valor);
    if(novoNo == NULL) return false;

    if(isEmpty(l)){
        l->inicio = novoNo;
    }else{
        l->fim->prox = novoNo;
    }
    l->fim = novoNo;

    l->qtd++;
    return true;
}

bool inserirPosicao(Lista *l,char valor, int indice){
    if(indice < 0 || indice > l->qtd) return false;

    if(indice == 0){
        if(isEmpty(l)){
            if(!inserir(l, valor)) return false;
            l->qtd++;
            return true;
        }
        
        No *novoNo = criarNo(valor);
        if(novoNo == NULL) return false;

        novoNo->prox = l->inicio;
        l->inicio = novoNo;
        l->qtd++;
        return true;
    }

    No *aux = l->inicio;
    for(int i = 0; i != indice - 1; i++){
        aux = aux->prox;
    }

    No *novoNo = criarNo(valor);
    novoNo->prox = aux->prox;
    aux->prox = novoNo;

    l->qtd++;
    return true;
}

bool remover(Lista *l, int indice, char *valorRemovido){
    if (l == NULL || isEmpty(l) || indice < 0 || indice >= l->qtd) return false;

    if (indice == 0) {
        No *removido = l->inicio;
        if (removido == NULL) return false;
        l->inicio = removido->prox;
        *valorRemovido = removido->val;
        free(removido);
        l->qtd--;
        if (l->inicio == NULL) l->fim = NULL;
        return true;
    }

    No *aux = l->inicio;
    for (int i = 0; i < indice - 1; i++) {
        if (aux == NULL) return false;
        aux = aux->prox;
    }

    No *removido = aux->prox;
    if (removido == NULL) return false;
    aux->prox = removido->prox;
    if (aux->prox == NULL) l->fim = aux;
    *valorRemovido = removido->val;
    free(removido);
    l->qtd--;
    return true;
}

bool isEmpty(Lista *l){
    if(l->fim == NULL && l->inicio == NULL) return true;
    return false;
}

bool get(Lista *l, int indice, char *valorGet){
    if(indice < 0 || indice >= l->qtd) return false;
    
    No *aux = l->inicio;
    for(int i = 0; i < indice; i++ ){
        aux = aux->prox;
    }

    *valorGet = aux->val;
    return true;
}

//Funcoes a parte
int sizeLista(Lista *l){
    if(isEmpty(l)) return 0;
    int quantidade = 0;
    No *aux = l->inicio;
    while(aux->prox != NULL){
        quantidade++;
        aux = aux->prox;
    }

    return quantidade + 1;
}//b

bool clearLista(Lista *l){
    if(isEmpty(l)) return true;
    char valorRemovido;
    while (remover(l, 0, &valorRemovido));
    return true;
}//c

void mostrarLista(Lista *l){
    printf("[");
    for(No *aux = l->inicio; aux != NULL; aux = aux->prox){
        printf("%c", aux->val);
        if(aux->prox != NULL) printf(", ");
    }
    printf("]");
}//d

bool ordenarLista(Lista *l){
   int tam = sizeLista(l);
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            char valorget1, valorget2;
            get(l, j, &valorget1);
            get(l, j + 1, &valorget2);
            if(valorget1 > valorget2){
                remover(l, j, &valorget1);
                inserirPosicao(l, valorget1, j + 1);
            }
        }
    }
    return true;
}//e

//Funcoes pessoais
void painel(int flag){
    if(flag == 1){
        printf("===========Lista===========\n");
        printf("1.Inserir                  \n"); //opcao de ser na posicao ou final
        printf("2.Remover                  \n"); // remover sempre na posicao
        printf("3.Ver Lista                \n");
        printf("4.Opcoes Exercicio         \n"); // todas as opcoes do exercicio em questao
        printf("5.Sair                     \n");
        printf("===========================\n");
    }else if(flag == 2){
        printf("======OpcoesExercicio======\n");
        printf("1.Size                     \n");
        printf("2.Clear                    \n"); 
        printf("3.Mostrar                  \n");
        printf("4.Ordenar                  \n"); 
        printf("5.Voltar                   \n");
        printf("===========================\n");
    }else{
        return;
    }
}