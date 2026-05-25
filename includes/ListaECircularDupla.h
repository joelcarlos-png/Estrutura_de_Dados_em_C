#ifndef LISTAECIRCULARDUPLA_H
#define LISTAECIRCULARDUPLA_H

typedef int TIPO;
#define T_TIPO "%d"

typedef struct no{
    TIPO val;
    struct no *prox;
    struct no *ante; 
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Lista;

#include <stdbool.h>

//Funcoes maes
Lista *criarLista();
No *cirarNo(TIPO valor);
bool inserirFinal(Lista *l, TIPO valor);
bool inserirPos(Lista *l, TIPO valor, int indice);
bool remover(Lista *l, TIPO *valorRemovido, int indice);
bool isEmpty(Lista *l);
bool get(Lista *l, TIPO *valorConsulta, int indice);

//funcoes a parte
void painel();
 
//Funcoes fo exercicio
int sizeLista(Lista *l);//b
bool clearLista(Lista *l);//c
bool mostrarLista(Lista *l);//d
bool ordenarLista(Lista *l);//e


#endif