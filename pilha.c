#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(Pilha *p, int tamanho){
    p->vet = malloc(tamanho * sizeof(int));
    p->top = -1;
    p->tam = tamanho;
};

void push(Pilha *p, int valor){
    if(p->top < p->tam - 1){
        p->top++;
        p->vet[p->top] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
};

int pop(Pilha *p){
    if(p->top >= 0){
        int valor = p->vet[p->top];
        p->top--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
};

void isEmpty(Pilha *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
    }
};

void isFull(Pilha *p){
    if(p->top == p->tam - 1){
        printf("Pilha cheia!\n");
    } 
};

void mostrarPilha(Pilha *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha:\n");
        printf("   ↓↓\n");
        for(int i = p->top; i >= 0; i--){
            printf("   %d \n", p->vet[i]);
        }
        printf("--base--\n");
    }
};

void liberarPilha(Pilha *p){
    free(p->vet);
    p->vet = NULL;
    p->top = -1;
    p->tam = 0;
}