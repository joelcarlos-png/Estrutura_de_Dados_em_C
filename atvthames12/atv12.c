#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

int main(){
    int tam, op, val;
    tam = lerInteiro("Digite o tamanho para a fila: ");
    Fila *f = criarFila(tam);

    do{
    printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Exercicio 12\n5.Sair\n====================\n\n");
    op = lerInteiro("Digite sua opcao: ");
    switch(op){
    case 1:
        if(isFull(f) == 1){printf("!!Fila Cheia!!\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para adicionar: ");
        if(op > f->tam - f->qtd){
            printf("Nao e possivel adicionar\nA fila so tem %d espaços vagos\n", f->tam - f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            char pergunta[64];
            sprintf(pergunta, "Valor %d: ", i + 1);
            val = lerInteiro(pergunta);
            inserir(f, val);
        }
        break;   
    case 2:
        if(isEmpty(f) == 1){printf("!!Fila Vazia!!\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f);
            printf("\nValor %d removido\n", val);
        }
        break;
    case 3:
        printf("Fila: \n");
        mostrarFila(f);  
        break;
    case 4:
        while(op != 2){
            printf("====OPCOES-EXERCICIO-12====\n1.Ver aritmetica da Fila\n2.Sair\n====================\n\n");
            op = lerInteiro("Digite sua opcao: ");
            switch (op){
            case 1:
                if(isEmpty(f)){printf("!!Fila Vazia!!\n");break;}
                mostrarAritimetica(f);
                break;
            case 2:
                printf("Voltando...\n");
                break;
            default:
                printf("Digite de 1 ou 2!!\n");
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
    }while(1);
    
    return 0;
}