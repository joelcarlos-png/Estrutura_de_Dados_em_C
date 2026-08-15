#include <stdio.h>
#include <stdlib.h>
#include "pilhaChar.h"

int main(){
    Pilha p1, p2;
    int tamanho;
    printf("Tamanho para as duas pilhas: ");
    scanf("%d", &tamanho);
    criarPilha(&p1, tamanho);
    criarPilha(&p2, tamanho);

    printf("\nEscreva %d caracteres(char) para Pilha 1: \n", tamanho);
    char valor;
    for(int i = p1.tam; i > 0; i--){
        scanf(" %c", &valor);
        push(&p1, valor);
    }

    printf("\n\nEscreva %d caracteres(char) para Pilha 2: \n", tamanho);
    for(int i = p2.tam; i > 0; i--){
        scanf(" %c", &valor);
        push(&p2, valor); 
    }

    printf("Pilha 1: ");
    mostrarPilha(&p1);

    printf("\nPilha 2: ");
    mostrarPilha(&p2);

    if(verifIgualdade(&p1, &p2) == 1){ printf("\nIguais"); }
    else {printf("\nDiferentes"); }


    return 0;
}