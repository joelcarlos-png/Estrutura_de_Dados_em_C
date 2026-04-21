#ifndef FILACHARE_H
#define FILACHARE_H

#include <stdbool.h>

typedef struct No{
    char valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Fila;

Fila *criarFila();
Fila *clonarFila(Fila *orig);
bool inserir(Fila *f, char valor);
bool remover(Fila *f, char *valorRemovido);
bool isEmpty(Fila *f);
bool size(Fila *f, int *quantidadeDeElementos);
bool clear(Fila *f);
bool mostrarFila(Fila *f);
bool inverter(Fila *f);
int lerInteiro(const char *pergunta);
char lerChar(const char *pergunta);
void liberarFila(Fila *f);
void painel();

#endif