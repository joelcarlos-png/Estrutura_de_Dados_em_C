#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filachar.h"

int main(){
    int tam, op;
    char val;
    tam = lerInteiro("Digite o tamanho para a fila: ");
    Fila *f = criarFila(tam);

    do{
    bool sairsubwitch = true;
    printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Exercicio 9\n5.Sair\n====================\n\n");
    op = lerInteiro("Digite sua opcao: ");
    switch(op){
    case 1:
        if(isFull(f) == true){printf("!!Fila Cheia!!\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para adicionar: ");
        if(op > f->tam - f->qtd){
            printf("Nao e possivel adicionar\nA fila so tem %d espaços vagos\n", f->tam - f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            char pergunta[64];
            sprintf(pergunta, "Valor %d: ", i + 1);
            val = lerChar(pergunta);
            inserir(f, val);
        }
        printf("\n");
        break;
    case 2:
        if(isEmpty(f) == true){printf("!!Fila Vazia!!\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            remover(f, &val);
            printf("\nValor %c removido\n", val);
        }
        break;
    case 3:
        if(isEmpty(f)){printf("!!Fila Vazia!!\n"); break;}
        printf("Fila: \n");
        mostrarFila(f);
        break;
    case 4:
        while(sairsubwitch){
            printf("====OPCOES-EXC9====\n1.Inverter Fila\n2.Voltar\n====================\n\n");
            op = lerInteiro("Digite sua opcao: ");

            switch (op){
            case 1:
                inverter(f);
                printf("Fila invertida com sucesso!!\n");
                break;
            case 2:
                printf("Voltando...\n");
                sairsubwitch = false;
                break;
            default:
                printf("Digite um valor de 1 a 4!!\n");
                break;
            }
        }
        break;
    case 5:
        liberar(f);
        exit(0);
    default:
        printf("Digite um valor de 1 a 4!!\n");
        break;
    }
    }while(true);
    
    return 0;
}