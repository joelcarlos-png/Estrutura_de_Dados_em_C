#ifndef LISTAECIRCULARSIMPLES_H
#define LISTAECIRCULARSIMPLES_H

typedef float TIPO;
#define T_TIP "%.2f"

#include <stdbool.h>
 
typedef struct no{
    float val;
    struct no *prox;
}No;

typedef struct{ 
    No *inicio;
    No *fim;
    int qtd;
}Lista;

//FUNCOES MAE
Lista *criarLista();
bool inserirFinal(Lista *l, TIPO valor);
bool inserirPos(Lista *l, TIPO valor, int indice);
bool remover(Lista *l, int indice, TIPO *valorRemovido);
bool isEmpty(Lista *l);
bool get(Lista *l, int indice, TIPO *valor);

//funcoes a parte
void painel();
 
//Funcoes fo exercicio
int sizeLista(Lista *l);//b
bool clearLista(Lista *l);//c
void mostrarLista(Lista *l);//d
bool ordenarLista(Lista *l);//e

#endif