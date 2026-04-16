#ifndef PILHAFLOAT_H
#define PILHAFLOAT_H

typedef struct {
    float *vet;
    int top;
    int tam;
} Pilha;

void criarPilha(Pilha *p, int tamanho);
void push(Pilha *p, float valor);
float pop(Pilha *p);
int isEmptyPilha(Pilha *p);
int isFullPilha(Pilha *p);
void mostrarPilha(Pilha *p);
void liberarPilha(Pilha *p);
void copyPilha(Pilha *p1, Pilha *p2);

#endif