#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaECircularSimples.h"
#include "controle.h"
#include "cores.h"

int main(){ 
    Lista *l = criarLista();

    TIPO val;
    int op = -1, ctr, ctri;
    while (op != 8){
        painel();
        op = lerInteiro("Digite sua opocao: ");
        switch(op){
            case 1:
                if(lerInteiro("Inserir no final ou no indice: (1: final | 0: indice): ")){
                    ctr = lerInteiro("Digite a quantidade de elementos para inserir: ");
                    for(int i = 0; i < ctr; i++){
                        char pergunta[64];
                        sprintf(pergunta, "Valor %d: ", i + 1);
                        val = lerDouble(pergunta);
                        if(inserirFinal(l, val)) printf(VERDE "Valor " T_TIP " Inserido na lista!!\n" RESET, val);                  
                    }
                    break;
                }
                    ctr = lerInteiro("Digite a quantidade de elementos para INSERIR: ");
                    for(int i = 0; i < ctr; i++){
                        char pergunta[64];
                        sprintf(pergunta, "Valor %d: ", i + 1);
                        val = lerDouble(pergunta);
                        sprintf(pergunta, "Indice %d: ", i + 1);
                        ctri = lerInteiro(pergunta);
                        if(inserirPos(l, val, ctri)) printf(VERDE "Valor " T_TIP " Inserido na lista!!\n" RESET, val);   
                        else {
                            printf(VERMELHO "Indice incorreto!!\n" RESET);
                            i--;
                        }               
                    }
                break;
            case 2:
                ctr = lerInteiro("Digite a quantidade de elementos para REMOVER: ");
                    for(int i = 0; i < ctr; i++){
                        char pergunta[64];
                        sprintf(pergunta, "Indice %d: ", i + 1);
                        ctri = lerInteiro(pergunta);
                        if(remover(l, ctri, &val)){
                            printf(VERDE "Valor " T_TIP " REMOVIDO da lista!!\n" RESET, val);    
                            mostrarLista(l);
                        }else{
                            printf(VERMELHO "Indice incorreto!!\n" RESET);
                            i--;
                        }              
                    }
                break;
            case 3:
                ctr = lerInteiro("Digite um indice para consultar: ");
                if(get(l, ctr, &val)){
                    printf(AZUL "Valor na posicao %d: " VERDE T_TIP "\n" RESET, ctr, val);
                }else{
                    printf(VERMELHO "Indice incorreto!!\n" RESET);
                }
                break;
            case 4:
                printf("Tamanho da lista: %d\n", sizeLista(l));
                break;
            case 5:
                if(lerInteiro("Tem certeza? (1: sim | 0: nao): ")){
                    clearLista(l);
                    printf(VERDE "Lista limpa com sucesso!!\n" RESET);
                }else{
                    printf(AMARELO "Voltando...\n" RESET);
                }
                break;
            case 6:
                mostrarLista(l);
                break;
            case 7:
                if(lerInteiro("Tem certeza? (1: sim | 0: nao): ")){
                    ordenarLista(l);
                    printf(VERDE "Lista ordenada com sucesso!!\n" RESET);
                }else{
                    printf(AMARELO "Voltando...\n" RESET);
                }
                break;
            case 8:
                if(lerInteiro("Tem certeza? (0: nao | 1: sim): ")) printf(AMARELO "SAINDO...\n" RESET);
                else op = -1;
                break;
            default:
                printf(AMARELO "Digite um numero de 1 a 9!!\n" RESET);
                break;
        }
    }
    
}
