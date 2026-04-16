#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typdef struct{
    char valor;
    struct No proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd
}Fila;

Fila *criarFila(){
    Fila *f = malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}
