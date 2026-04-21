#include <stdio.h>
#include <stdlib.h>
#include "pilhaFloat.h"

int main(){
    Pilha p1, p2;
    int tamanho;
    printf("Tamanho para a pilha 1: ");
    scanf("%d", &tamanho);
    criarPilha(&p1, tamanho);
    criarPilha(&p2, tamanho);
    
    printf("\nEscreva %d valores(float) para Pilha 1: \n", tamanho);
    float valor;
    for(int i = p1.tam; i > 0; i--){
        scanf("%f", &valor);
        push(&p1, valor);
    }
    printf("Pilha 1: ");
    mostrarPilha(&p1);
    printf("\n\nPilha 2 no momento: \n");
    mostrarPilha(&p2);
    
    printf("\n");
    copyPilha(&p1, &p2);
    printf("\n");

    printf("\nPilha 2 depois da copia: ");
    mostrarPilha(&p2);

    return 0;
}