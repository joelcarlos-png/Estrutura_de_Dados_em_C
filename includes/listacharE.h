#ifndef LISTACHARE_H
#define LISTACHARE_H

#include <stdbool.h>

typedef struct no{
    char val;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd; 
}Lista;

//Funcoes Maes 
Lista *criarLista(); 
No *criarNo(char valor);
bool inserir(Lista *l, char valor);
bool inserirPosicao(Lista *l,char valor, int indice);
bool remover(Lista *l, int indice, char *valorRemovido);
bool isEmpty(Lista *l);
bool get(Lista *l, int indice, char *valorGet);

//Funcoes a parte
int sizeLista(Lista *l);//b
bool clearLista(Lista *l);//c
void mostrarLista(Lista *l);//d
bool ordenarLista(Lista *l);//e

//Funcoes pessoais
void painel(int flag);

#endif