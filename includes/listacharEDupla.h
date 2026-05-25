#ifndef LISTACHAREDUPLA_H
#define LISTACHAREDUPLA_H

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
Lista *criarLista();
No *criarNo(char valor);
bool inserir(Lista *l, char valor);
bool inserirPosicao(Lista *l,char valor, int indice);
bool remover(Lista *l, int indice);
bool isEmpty(Lista *l);
bool get(Lista *l, int indice, int *valorGet);

//Funcoes a parte
void mostrarLista(Lista *l);
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

#endif