#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void A(Pilha *p){
    push(p, 1);
    push(p, 2);
    push(p, 4);
    push(p, 5);
    push(p, 10);
}

void mostrarA(Pilha *p){
    printf("Valores de A:\n");
    for(int i = 0; i < 5; i++){
        printf("  %d\n", p->vet[i]);
    }
    printf("-base-\n\n");
}

void B(Pilha *p){
    push(p, 7);
    push(p, 12);
    push(p, 15);
    push(p, 18);
    push(p, 22);
}

void mostrarB(Pilha *p){
    printf("Valores de B:\n");
    for(int i = 5; i < 10; i++){
        printf("  %d\n", p->vet[i]);
    }
    printf("-base-\n");
}

int main(){
    Pilha p;
    criarPilha(&p, 10);

    A(&p); B(&p);

    mostrarA(&p);
    mostrarB(&p);

    return 0;
}