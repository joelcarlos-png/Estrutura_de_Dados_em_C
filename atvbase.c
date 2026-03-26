#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vet;
    int top;
    int tam;
}Pilha;

void criarPilha(Pilha *p, int tam){
    p->vet = malloc(tam * sizeof(int));
    p->top = -1;
    p->tam = tam;
}