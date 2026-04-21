#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filacharE.h"

int main(){
    Fila *f = criarFila();

    int op = 1, opcoes;
    char val;
    while (op != 10){
        painel();
        op = lerInteiro("Digite sua opcao: ");

        switch (op){
        case 1:
            opcoes = lerInteiro("Digite a quantidade de valores para adicionar: ");
            for(int i = 0; i < opcoes; i++){
                char pergunta[64];
                sprintf(pergunta, "Valor %d: ", i + 1);
                val = lerChar(pergunta);
                inserir(f, val);
            }
            printf("%d valores adicionados!\n", opcoes);
            break;
        case 2:
            op = lerInteiro("Digite a quantidade de valores para remover: ");
            for(int i = 0; i < op; i++){
                remover(f, &val);
                printf("Valor %c removido\n", val);
            }
            break;
        case 3:
            size(f, &op);
            printf("Quantidade de valores na fila: %d\n", op);
            break;
        case 4:
            op = lerInteiro("Tem certeza que deseja remover todos os valores? (1:sim, 2:nao): ");
            if(op == 1){
                if(clear(f)){
                    printf("Fila limpa com sucesso!!\n");
                }
            }
            break;
        case 5:
            mostrarFila(f);
            break;
        case 6:
            size(f, &op);
            printf("Quantidade de valores na fila: %d\n", op);
            if(clear(f)){
                    printf("Quantidade de elementos da fila a mostra e fila limpa com sucesso!!\n");
            }
            break;
        case 7:
            inverter(f);
            mostrarFila(f);
            if(clear(f)){
                printf("Fila invertida e clear com sucesso\n");
            }
            break;
        case 8:
            if (inverter(f)){
                printf("Fila invertida com sucesso!!\n");
            }
            break;
        case 9:
            printf("Digite a palavra para inserir na fila: ");
            char valorChar;
            while ((valorChar = getchar()) != '\n' && valorChar != EOF) { }
            while(true){
                scanf("%c", &valorChar);
                if(valorChar == '\n'){break;}
                inserir(f, valorChar);
            }
            printf("Palavra adicionada com sucesso! \n");
            break;
        case 10:
            printf("Saindo...\n");
            break;
        default:
            printf("!!Digite um numero de 1 a 10!!\n");
            break;
        }
    }
}