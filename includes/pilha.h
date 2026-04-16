#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *vet;
    int top;
    int tam;
} Pilha;

void criarPilha(Pilha *p, int tamanho);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int isEmptypilha(Pilha *p);
int isFullpilha(Pilha *p);
void mostrarPilha(Pilha *p);
void liberarPilha(Pilha *p);
void painelPilha();

#endif