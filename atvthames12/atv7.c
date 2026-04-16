#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

int main(){
    int tam, op, val;
    tam = lerInteiro("Digite o tamanho para a fila: ");
    Fila *f = criarFila(tam);
    Fila *f2 = criarFila(tam);
    Fila *f3 = criarFila(tam);

    do{
    painel();
    op = lerInteiro("Digite sua opcao: ");
    switch(op){
    case 1:
        op = lerInteiro("Qual fila vc quer adicionar(1 ou 2): ");
        if(op == 1){
            if(isFull(f) == 1){printf("\n"); break;}
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
        }else if(op == 2){
            if(isFull(f2) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para adicionar: ");
        if(op > f2->tam - f2->qtd){
            printf("Nao e possivel adicionar\nA fila so tem %d espaços vagos\n", f2->tam - f2->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            char pergunta[64];
            sprintf(pergunta, "Valor %d: ", i + 1);
            val = lerInteiro(pergunta);
            inserir(f2, val);
        }
        }else{
            printf("Digite 1 ou 2!!");
        }

        break;     
    case 2:
        op = lerInteiro("Qual fila vc quer remover(1 ou 2 ou 3): ");
        if(op == 1){
            if(isEmpty(f) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f);
            printf("\nValor %d removido\n", val);
        }
        }else if (op == 2){
            if(isEmpty(f2) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f2->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f2->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f2);
            printf("\nValor %d removido\n", val);
        } 
        }else if(op == 3){
        if(isEmpty(f3) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f3->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f3->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f3);
            printf("\nValor %d removido\n", val);
        }
        }else{
            printf("Digite de 1 a 3!!\n");
        }
        break;
        
    case 3:
        op = lerInteiro("Qual fila voce quer ver(1 ou 2 ou 3): ");
        printf("Fila: \n");
        if (op == 1){
            mostrarFila(f);
        }else if(op == 2){
            mostrarFila(f2);
        }else if(op == 3){
            mostrarFila(f3);
        }else{
            printf("Digite de 1 a 3!!");
        }
        break;
    case 4:
        while(op != 3){
            printf("====OPCOES-EXERCICIOS-5a8====\n1.Adicionar valores padrao\n2.Organizar Filas\n3.Sair\n=============================\n\n");
            op = lerInteiro("Digite sua opcao: ");
            switch (op){
            case 1:
                queueClear(f);
                queueClear(f2);
                for(int i = 1; i <= f->tam; i++){
                    if(i % 2 == 0){
                        inserir(f, i);
                    }else{
                        inserir(f2, i);
                    }
                }
                mostrarFila(f);
                printf("Fila 2: \n");
                mostrarFila(f2);
                printf("\nValores padrao adicionados!!\n");
                break;
            case 2:
                printf("\nValores de f1 e f2 estao organizados em f3!!\nFila 3:\n");
                organizarFilasCrescente(f, f2, f3);
                mostrarFila(f3);
                break;
            case 3:
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