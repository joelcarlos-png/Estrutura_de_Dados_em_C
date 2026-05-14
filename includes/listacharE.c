#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listachare.h"

Lista *criarLista(int tamanho){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

bool inserir(Lista *l);
bool inserirPosicao(Lista *l, int indice);
bool isEmpty(Lista *l);
void get(Lista *l, int indice);

void mostrarLista(Lista *l);