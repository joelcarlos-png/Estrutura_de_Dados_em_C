#include <stdio.h>
#include <stdlib.h>
#include "pilhaFloat.h"

void criarPilha(Pilha *p, int tamanho){
    p->vet = malloc(tamanho * sizeof(float));
    p->top = -1;
    p->tam = tamanho;
};

void push(Pilha *p, float valor){
    if(p->top < p->tam - 1){
        p->top++;
        p->vet[p->top] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
};


float pop(Pilha *p){
    if(p->top >= 0){
        float valor = p->vet[p->top];
        p->top--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
};

int isEmptyPilha(Pilha *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
        return 1;
    }
    return 0;
};

int isFullPilha(Pilha *p){
    if(p->top == p->tam - 1){
        printf("Pilha cheia!\n");
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
            printf("  %.2f\n", p->vet[i]);
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

void copyPilha(Pilha *p1, Pilha *p2){
    Pilha aux;
    float valor;
    criarPilha(&aux, p1->tam);
    for(int i = p1->top; i >= 0; i--){
        valor = pop(p1);
        push(&aux, valor);
    }

    for(int i = aux.top; i >= 0; i--){
        valor = pop(&aux);
        push(p2, valor);
    }

    printf("!!Pilhas copiadas!!");

};

static void painelPilhaFloat(){
    printf("=-=-=Menu Pilha=-=-=\n1. PUSH\n2. POP\n3. VER PILHA\n4. SAIR\n=-=-=-=-=-=-=-=-=-=-=\n\nDigite sua opcao: ");
};