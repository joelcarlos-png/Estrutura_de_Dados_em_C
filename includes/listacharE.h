#ifndef FILACHARE_H
#define FILACHARE_H

#include <stdbool.h>

typedef struct no{
    char val;
    struct no *ante;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Lista;

//Funcoes Maes
Lista *criarLista(int tamanho);
bool inserir(Lista *l);
bool inserirPosicao(Lista *l, int indice);
bool isEmpty(Lista *l);
void get(Lista *l, int indice);

//Funcoes a parte
void mostrarLista(Lista *l);

#endif