#include <stdio.h>
#include <stdlib.h>
#include "pilhaChar.h"

void criarPilhaChar(PilhaChar *p, int tamanho){
    p->vet = malloc(tamanho * sizeof(char));
    p->top = -1;
    p->tam = tamanho;
};

void pushchar(PilhaChar *p, char valor){
    if(p->top < p->tam - 1){
        p->top++;
        p->vet[p->top] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
};


char popchar(PilhaChar *p){
    if(p->top >= 0){
        char valor = p->vet[p->top];
        p->top--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
};

int isEmptychar(PilhaChar *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
        return 1;
    }
    return 0;
};

int isFullchar(PilhaChar *p){
    if(p->top == p->tam - 1){
        printf("Pilha cheia!\n");
        return 1;
    } 
    return 0;
};

void mostrarPilhachar(PilhaChar *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha:\n");
        printf("   ↓↓\n");
        for(int i = p->top; i >= 0; i--){
            printf("   %c\n", p->vet[i]);
        }
        printf("--base--\n");
    }
};

void liberarPilhachar(PilhaChar *p){
    free(p->vet);
    p->vet = NULL;
    p->top = -1;
    p->tam = 0;
};

int verifIgualdadechar(PilhaChar *p1, PilhaChar *p2){
    int flag = 0;
    for(int i = p1->top; i >= 0; i--){
        char valorp1 = popchar(p1);
        char valorp2 = popchar(p2);
        if(valorp1 == valorp2){
            flag++;
        }
    }
    
    if(flag == p1->tam){
        return 1;
    }
    return 0;
};

void painelchar(){
    printf("=-=-=Menu Pilha=-=-=\n1. PUSH\n2. POP\n3. VER PILHA\n4. SAIR\n=-=-=-=-=-=-=-=-=-=-=\n\nDigite sua opcao: ");
};