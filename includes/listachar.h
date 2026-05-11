#ifndef LISTACHAR_H
#define LISTACHAR_H

#include <stdbool.h>
#include <string.h>

typedef struct{
    int fim, tam;
    char *valor;
}Lista;

Lista *criarLista(int tamanho);
bool isFull(Lista *l);
bool isEmpty(Lista *l);
bool inserirFinal(Lista *l, char valor);
bool inserirIndice(Lista *l, char valor, int indice);
bool remover(Lista *l, int indice, char *valorRemovido);
void mostrarLista(Lista *l);
bool consultar(Lista *l, int indice);
bool sizeLista(Lista *l, int *tamanhoLista);
bool clearLista(Lista *l);
bool ordenar(Lista *l);
bool ordenarZA(Lista *l);
void painel();
bool mostarInversa(Lista *l);

#endif 