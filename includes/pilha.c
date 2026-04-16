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

int isEmptypilha(Pilha *p){
    if(p->top == -1){
        return 1;
    }
    return 0;
};

int isFullpilha(Pilha *p){
    if(p->top == p->tam - 1){
        return 1;
    } 
    return 0;
};

void mostrarPilha(Pilha *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha:\n");
        printf("   ↓↓\n");
        for(int i = p->top; i >= 0; i--){
            printf("   %d\n", p->vet[i]);
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

void painelPilha(){
    printf("=-=-=Menu Pilha=-=-=\n1. PUSH\n2. POP\n3. VER PILHA\n4. SAIR\n=-=-=-=-=-=-=-=-=-=-=\n\nDigite sua opcao: ");
};