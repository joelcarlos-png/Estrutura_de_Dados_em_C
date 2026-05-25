#ifndef LISTADUPLA_H
#define LISTADUPLA_H

typedef int TIPO;
#define T_PRI "%d"

#include <stdbool.h>

typedef struct no{
    TIPO val;
    struct no *ante;
    struct no *prox; 
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Lista;

//Struct ArrayListas
typedef struct{
    Lista *list; 
    char nome;
}ArrayListas;

//funcao array list
void mostrarTodasListas(ArrayListas *listas, int qntListas);
ArrayListas *escolherLista(ArrayListas *listas, int qntListas);

//Funcoes Maes
Lista *criarLista();
No *criarNo(TIPO valor);
bool inserir(Lista *l, TIPO valor);
bool inserirPosicao(Lista *l,TIPO valor, int indice);
bool remover(Lista *l, int indice, TIPO *valorRemovido);
bool isEmpty(Lista *l);
bool get(Lista *l, int indice, int *valorGet);

//Funcoes a parte
bool mostrarLista(Lista *l);
void painel(int flag);
bool verificarPrimo(int valor);

//Funcoes do exercicio
int sizeLista(Lista *l);//b
bool clearLista(Lista *l);//c
int verQntPares(Lista *l);//d
int verQntMaiores(Lista *l, TIPO numero);//e
int verQntPrimos(Lista *l);//f
Lista *listaComPares(Lista *l);//g
Lista *ordenarDuasListas(Lista *l1, Lista *l2);//h
void mostrarListaInversa(Lista *l);//i
bool removerPares(Lista *l);//j
Lista *listaComImpares(Lista *l);//k
TIPO verMaior(Lista *l);//l
TIPO verMenor(Lista *l);//m
bool trocarPosicao(Lista *l, int indice1, int indice2);//n
bool verificarIgualdade(Lista *l1, Lista *l2);//o

#endif