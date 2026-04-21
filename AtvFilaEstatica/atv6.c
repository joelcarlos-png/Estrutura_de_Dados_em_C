#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

int main(){
    int tam, op, val;
    tam = lerInteiro("Digite o tamanho para a fila: ");
    Fila *f = criarFila(tam);
    Fila *f2 = criarFila(tam);

    do{
    painel();
    op = lerInteiro("Digite sua opcao: ");
    switch(op){
    case 1:
        op = lerInteiro("Qual fila vc quer adicionar(1 ou 2): ");
        if(op == 1){
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
        }else if(op == 2){
            if(isFull(f2) == 1){printf("!!Fila Cheia!!\n"); break;}
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
        }else{printf("Digite 1 ou 2!!\n");}
        break;
        
    case 2:
        op = lerInteiro("Qual fila vc quer remover(1 ou 2): ");
        if(op == 1){
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
        }else if(op == 2){
        if(isEmpty(f2) == 1){printf("!!Fila Vazia!!\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f2->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f2->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f2);
            printf("\nValor %d removido\n", val);
        }
        }else{printf("Digite 1 ou 2!!\n");}
        break;

    case 3:
        op = lerInteiro("Qual fila voce quer ver(1 ou 2): ");
        printf("Fila: \n");
        if (op == 1){
            mostrarFila(f);
        }else if(op == 2){
            mostrarFila(f2);
        }else{
            printf("Digite 1 ou 2!!\n");
        }
        break;
    case 4:
        while(op != 2){
            printf("====OPCOES-EXERCICIOS-5a8====\n1.Verificar maior\n2.Sair\n====================\n\n");
            op = lerInteiro("Digite sua opcao: ");
            switch (op){
            case 1:
                if(verificarMaior(f, f2) == 11){
                    printf("Fila 1 e maior!!\n");
                }else if(verificarMaior(f, f2) == 22){
                    printf("Fila 2 e maior!!\n");
                }else if(verificarMaior(f, f2) == 33){
                    printf("As filas sao iguais!!\n");
                }
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
        printf("Digite um valor de 1 a 5!!\n");
        break;
    }
    }while(1);
    
    return 0;
}