#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filacharE.h"

Fila *criarFila(){
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}

bool inserir(Fila *f, char valor);
bool remover(Fila *f, char *valorRemovido);
bool isEmpty(Fila *f);
int size(Fila *f);
void clear(Fila *f);
void mostrarFila(Fila *f);
void inverter(Fila *f);
int lerInteiro(const char *pergunta);
char lerChar(const char *pergunta);