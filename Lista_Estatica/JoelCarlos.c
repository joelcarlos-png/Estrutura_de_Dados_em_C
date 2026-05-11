#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listachar.h"
#include "controle.h"

int main(){
    int op = lerInteiro("Digite o tamanho  para a lista: ");
    Lista *l = criarLista(op);
    
    int indice, ctr;
    char val;

    while(op != 11){
        painel();
        op = lerInteiro("Digite sua opcao: ");

        switch (op){
        case 1:
            ctr = lerInteiro("Digite a quantidade de valores pra adicionar: ");
            for(int i = 0; i < ctr; i++){
                char pergunta[64];
                sprintf(pergunta, "Valor %d: ", i + 1);
                val = lerChar(pergunta);
                sprintf(pergunta, "Indice %d: ", i + 1);
                indice = lerInteiro(pergunta);
                
                bool flag = inserirIndice(l, val, indice);
                
                if(flag == false){
                    printf("!!escreva um indice de 0 a %d!!\n", l->fim + 1);
                    i--;
                }else{
                    printf("!!Valor %c adicionado no indice %d!!\n", val, indice);
                }
                
                if(isFull(l)){
                    printf("Lista ficou cheia!!\n");
                    break;
                }
            }
            break;
        case 2:
            ctr = lerInteiro("Digite a quantidade de valores pra remover: ");
            for(int i = 0; i < ctr; i++){
                char pergunta[64];
                sprintf(pergunta, "Indice %d: ", i + 1);
                indice = lerInteiro(pergunta);
                
                char valorRemov;
                bool flag = remover(l, indice, &valorRemov);
                
                if(flag == false){
                    printf("!!escreva um indice de 0 a %d!!\n", l->fim + 1);
                    i--;
                }else{
                    printf("!!Valor %c removido do indice %d!!\n", valorRemov, indice);
                }

                if(isEmpty(l)){
                    printf("A lista ficou vazia!!\n");
                    break;
                }
            }
            break;
        case 3:
            int tamanho;
            sizeLista(l, &tamanho);
            printf("Tamanho da lista: %d\n", tamanho);
            break;
        case 4:
            if(lerInteiro("Tem certeza que deseja apagar TODA a lista? (1: sim, 2:nao): ") == 1){
                clearLista(l);
                printf("Lista limpa com sucesso!!\n");
            }else{
                printf("Voltando...\n");
            }
            break;
        case 5:
            mostrarLista(l);
            break;
        case 6:
            if(lerInteiro("Tem certeza? (1: sim, 2:nao): ") == 1){
                int tamanho;
                sizeLista(l, &tamanho);
                clearLista(l);
                printf("Tamanho da lista: %d\nLista limpa com sucesso!!\n", tamanho);
            }else{
                printf("Voltando...\n");
            }
            break;
        case 7:
            if(lerInteiro("Tem certeza? (1: sim, 2:nao): ") == 1){
                mostarInversa(l);
                clearLista(l);
                printf("Lista limpa com sucesso!!\n", tamanho);
            }else{
                printf("Voltando...\n");
            }
            break;
        case 8:
            char palavra[64];
            printf("Digite a palavra: ");
            while(getchar() != '\n');
            fgets(palavra, sizeof(palavra), stdin);

            for(int i = 0; i < strlen(palavra) - 1; i++){
                bool flag = inserirFinal(l, palavra[i]);
                if(flag == false){
                    printf("A palavra nao coube na lista\n");
                    break;
                }
            }
            break;
        case 9:
            if(lerInteiro("Tem certeza? (1: sim, 2:nao): ") == 1){
                ordenar(l, 0);
                printf("Lista ordenada(A - Z) com sucesso!!\n");
            }else{
                printf("Voltando...\n");
            }
            break;
        case 10:
            if(lerInteiro("Tem certeza? (1: sim, 2:nao): ") == 1){
                ordenar(l, 1);
                printf("Lista ordenada(Z - A) com sucesso!!\n");
            }else{
                printf("Voltando...\n");
            }
            break;
        case 11:
            printf("Saindo...\n");
            break;
        default:
            printf("Digite um numero de 1 a 11\n");
            break;
        }
    }

}
