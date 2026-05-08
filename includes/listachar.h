#ifndef LISTACHAR_H
#define LISTACHAR_H

#include <stdbool.h>

typedef struct{
    int fim, tam;
    char *valor;
}Lista;

Lista *criarLista(int tamanho);
bool isFull(Lista *l);
bool isEmpty(Lista *l);
bool inserirFinal(Lista *l, char valor);
bool inserirIndice(Lista *l, char valor, int indice);
bool remover(Lista *l, int indice);
void mostrarLista(Lista *l);
bool consultar(Lista *l, int indice);

#endif