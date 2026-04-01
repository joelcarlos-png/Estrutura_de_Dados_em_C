#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int tamanho;
    printf("Digite o tamanho da pilha:\n");
    scanf("%d", &tamanho);
    Pilha p;
    criarPilha(&p, tamanho);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);
    mostrarPilha(&p);

    return 0;
}