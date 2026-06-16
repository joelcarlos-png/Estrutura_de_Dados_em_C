#include <stdio.h>
#include <stdlib.h>
#include "arvoreparci.h"

int main(){
    ARR *a = criarARR();

    int op;
    double ctr, val;

    while(op != 7){
        printf("=========================\n");
        printf("1. inserir \n");
        printf("2. Ver menor chave\n");
        printf("3. Ver maior chave\n");
        printf("4. Exibir percursos\n");
        printf("5. Procurar uma chave\n");
        printf("6. Excluir uma chave\n");
        printf("7. Sair\n");
        printf("=========================\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Digite o valor: ");
            scanf("%f", &ctr);
            inserir(&(a->raiz), ctr);
            break;
        case 2:
            val = verMenor(&(a->raiz));
            printf("Menor Valor: ", val);
            break;
        case 3:
            val = verMaior(&(a->raiz));
            printf("Maior Valor: ", val);
            break;
        case 4:
            exibirPercursos(&(a->raiz));
            printf("\n");
            break;
        case 5:
            printf("Digite a chave: ");
            scanf("%f", &ctr);
            procurar(&(a->raiz), ctr);
            break;
        case 6:
            printf("Digite a chave para excluir: ");
            scanf("%f", &ctr);
            excluir(&(a->raiz), ctr);
            break;
        case 7:
            printf("Saindo...");
            break;
        default:
            printf("Digite um numnero de 1 a 7!!\n");
            break;
        }
    }
}