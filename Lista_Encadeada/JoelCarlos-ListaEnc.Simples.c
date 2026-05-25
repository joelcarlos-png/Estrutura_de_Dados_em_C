#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "listacharE.h"
#include "controle.h"
#include "cores.h"

int main(){
    Lista *l = criarLista();
    if(l == NULL){
        printf("Nao foi possivel alocar memoria!!\n");
        exit(0);
    }
    
    int ctr, op = -1, ctr2;
    char ctrc;
    char val;

    while (op != 5){
        painel(1);
        op = lerInteiro("Digite sua opcao: ");

        switch(op){
            case 1:
                char pergunta[64];
                ctr = lerInteiro("Inserir por indice ou no Fim: (1: indice | 2: final): ");
                if(ctr == 1){
                    ctr = lerInteiro("Digite quandos caracteres quer inserir: ");
                    for(int i = 0; i < ctr; i++){
                        sprintf(pergunta, "Valor %d: ", i + 1);
                        val = lerChar(pergunta);
                        sprintf(pergunta, "Indice %d: ", i + 1);
                        ctr = lerInteiro(pergunta);
                        if(inserirPosicao(l, val, ctr)) printf(VERDE "Insersao bem sucedida\n" RESET);
                        else printf(VERMELHO "Indice errado ou erro na alocacao de memoria\n" RESET);
                    }
                }else if(ctr == 2){
                    ctr = lerInteiro("Digite quandos caracteres quer inserir: ");
                    for(int i = 0; i < ctr; i++){
                        sprintf(pergunta, "valor %d: ", i + 1);
                        val = lerChar(pergunta);
                        if(inserir(l, val)) printf(VERDE "Insersao bem sucedida\n" RESET);
                    }
                }
                break;
            case 2:
                ctr = lerInteiro("Indice: ");
                if(remover(l, ctr, &val)) printf(VERDE "Valor %c Removido\n" RESET,  val);
                break;
            case 3:
                mostrarLista(l);
                printf("\n");
                break;
                case 4:
                ctr = -1;
                while (ctr != 5){
                    painel(2);
                    ctr = lerInteiro("Digite sua opcao: ");
                    switch(ctr){
                        case 1:
                            ctr2 = sizeLista(l);
                            printf("Tamanho da lista: %d\n", ctr2);
                            break;
                        case 2:
                            if(tolower(lerChar("Tem certeza? (s ou n)")) == 's') clearLista(l);
                            else printf("Voltando...\n");
                            break;
                        case 3:
                            mostrarLista(l);
                            printf("\n");
                            break;
                        case 4:
                            if(tolower(lerChar("Tem certeza? (s ou n)")) == 's') ordenarLista(l);
                            else printf("Voltando...\n");
                            break;
                        case 5:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Digite um numero de 1 a 5!!\n");
                            break;
                    }
                }
                break;
            case 5:
                ctrc = lerChar("Tem certeza? (n ou s): ");
                if(tolower(ctrc) == 's'){
                    printf("Saindo...\n");
                }else{
                    op = -1;
                }
                break;
            default:
                printf("Digite um numero de 1 a 5!!\n");
                break;   
        }
    }   
}