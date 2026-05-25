#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.h"
#include "controle.h"
#include "cores.h"

int main(void){
    int qntListas = lerInteiro("Digite quantas listas vc quer ter espaço em um Array (maximo de 26): ");
    while (qntListas > 26){
        printf("Voce SÓ pode escolher ate 26 listas\n");
        qntListas = lerInteiro("Digite quantas listas vc quer ter espaço em um Array(maximo de 26): ");
    }
    ArrayListas listas[qntListas];
    int listasRestantes = qntListas; 
    int quantidadeListas = qntListas - listasRestantes;

    for(int i=0;i<qntListas;i++){
        listas[i].list = NULL;
    }

    char ctrc;
    int ctri;
    int op = -1;
    while(op != 6){
        painel(1);
        op = lerInteiro("Digite sua opcao: ");
        switch (op){
        case 1: {
            int indice = -1;
            for(int i = 0; i < qntListas; i++){
                if(listas[i].list == NULL){
                    indice = i;
                    break;
                }
            }
            if(indice == -1){
                printf(VERMELHO "Voce ja encheu seu espaco para listas!!\n" RESET);
            }else{
                listas[indice].nome = 'A' + quantidadeListas;
                listas[indice].list = criarLista();
                listasRestantes--;
                quantidadeListas++;
                printf(VERDE "!!Lista Criada com sucesso!!\n" AMARELO "Voce tem %d espacos para lista sobrando!!\n" RESET, listasRestantes);
            }
            break;
        }
        case 2: {
            if(quantidadeListas <= 0){
                printf("Voce ainda nao criou nenhuma lista!!\n");
            }else{
                ArrayListas *lista = escolherLista(listas, quantidadeListas);
                if(lista == NULL) break;
                Lista *escolhido = lista->list;
                char nomeEscolhido = lista->nome;
                
                ctrc = lerChar("Inserir No final ou indice(f: final | i: indice): ");
                if(ctrc == 'i'){
                    ctri = lerInteiro("Digite quantos numeros voce quer adicionar: ");
                    int valor, indice;
                    for(int i = 0; i < ctri; i++){
                        char pergunta[64];
                        sprintf(pergunta, "Valor %d: ", i + 1);
                        valor = lerInteiro(pergunta);
                        sprintf(pergunta, "Indice %d: ", i + 1);
                        indice = lerInteiro(pergunta);
                        while(!inserirPosicao(escolhido, valor, indice)){
                            printf(VERMELHO"!!Indice invalido!!\n" RESET);
                            indice = lerInteiro(pergunta);
                        }
                        printf(VERDE "valor inserido com sucesso\n" RESET);
                    }
                }else if(ctrc == 'f'){
                    ctri = lerInteiro("Digite quantos numeros voce quer adicionar: ");
                    int valor;
                    for(int i = 0; i < ctri; i++){
                        char pergunta[64];
                        sprintf(pergunta, "Valor %d: ", i + 1);
                        valor = lerInteiro(pergunta);
                        inserir(escolhido, valor);
                    }
                }else{
                    printf("letra invalida\n");
                }
                
                printf(AZUL "Lista %c: " RESET, nomeEscolhido);
                mostrarLista(escolhido);
            }
            break;    
        }
        case 3: {
            if(quantidadeListas <= 0){
                printf("Voce ainda nao criou nenhuma lista!!\n");
            }else{
                ArrayListas *lista = escolherLista(listas, quantidadeListas);
                if(lista == NULL) break;
                Lista *escolhido = lista->list;
                char nomeEscolhido = lista->nome;

                if(isEmpty(escolhido)){
                    printf(AMARELO"!!Lista vazia!!\n"RESET);
                    break;
                }

                ctri = lerInteiro("Digite quantos numeros voce quer remover: ");
                int valor, indice;
                for(int i = 0; i < ctri; i++){
                    printf(AZUL "Lista %c: " RESET, nomeEscolhido);
                    mostrarLista(escolhido);
                    char pergunta[64];
                    sprintf(pergunta, "Indice %d: ", i + 1);
                    indice = lerInteiro(pergunta);
                    while(!remover(escolhido, indice, &valor)){
                        printf(VERMELHO"!!Indice invalido!!\n" RESET);
                        indice = lerInteiro(pergunta);
                    }
                    printf(VERDE "valor " T_PRI " removido com sucesso\n" RESET, valor);
                }
                printf(AZUL "Lista %c: " RESET, nomeEscolhido);
                mostrarLista(escolhido);
            }
            break;
        }
        case 4:
            mostrarTodasListas(listas, quantidadeListas);
            break;
        case 5: {
            char ctrcEx;
            int ctriEx;
            int opEx = -1;
            while (opEx != 15){
                painel(2);
                opEx = lerInteiro("Digite sua opcao: ");
                switch(opEx){
                    case 1: {
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        char nomeEscolhido = lista->nome;
                        int tam = sizeLista(escolhido);
                        printf(VERDE "Tamanho da lista %c:" T_PRI RESET "\n", nomeEscolhido, tam);
                        break;
                    }
                    case 2: {
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        ctrcEx = lerChar("Tem certeza? (s ou n)");
                        if(ctrcEx == 's'){
                            clearLista(escolhido);
                        }else if(ctrcEx == 'n'){
                            printf("Voltando...\n");
                        }
                        break;
                    }
                    case 3: {
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        char nomeEscolhido = lista->nome;
                        int qnt = verQntPares(escolhido);
                        printf(VERDE "Quantidade de Pares na lista %c: " T_PRI RESET "\n", nomeEscolhido, qnt);
                        break;
                    }
                    case 4:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        char nomeEscolhido = lista->nome;
                        int num = lerInteiro("Digite um numero para verificacao: ");
                        int qnt = verQntMaiores(escolhido, num);
                        printf(VERDE "Quantidade de Maiores que %d na lista %c: " T_PRI RESET "\n",num, nomeEscolhido, qnt);
                        break;
                    }
                    case 5:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        char nomeEscolhido = lista->nome;
                        int qnt = verQntPrimos(escolhido);
                        printf(VERDE "Quantidade de Primos na lista %c: " T_PRI RESET "\n", nomeEscolhido, qnt);
                        break;
                    }
                    case 6:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        int indice = -1;
                        for(int i = 0; i < qntListas; i++){
                            if(listas[i].list == NULL){
                                indice = i;
                                break;
                            }
                        }
                        if(indice == -1){
                            printf(VERMELHO "Voce ja encheu seu espaco para listas!!\n" RESET);
                        }else{
                            ArrayListas *lista = escolherLista(listas, quantidadeListas);
                            if(lista == NULL) break;
                            listas[indice].nome = 'A' + quantidadeListas;
                            listas[indice].list = listaComPares(lista->list);
                            listasRestantes--;
                            quantidadeListas++;
                            printf(VERDE "!!Lista Com PARES[Lista %c] criada com sucesso!!\n" AMARELO "Voce tem %d espacos para lista sobrando!!\n" RESET,listas[indice].nome, listasRestantes);
                        }
                        break;
                    }
                    case 7:
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        int indice = -1;
                        for(int i = 0; i < qntListas; i++){
                            if(listas[i].list == NULL){
                                indice = i;
                                break;
                            }
                        }
                        if(indice == -1){
                            printf(VERMELHO "Voce ja encheu seu espaco para listas!!\n" RESET);
                        }else{
                            ArrayListas *lista1 = escolherLista(listas, quantidadeListas);
                            if(lista1 == NULL) break;
                            ArrayListas *lista2 = escolherLista(listas, quantidadeListas);
                            if(lista2 == NULL) break;
                            listas[indice].nome = 'A' + quantidadeListas;
                            listas[indice].list = ordenarDuasListas(lista1->list, lista2->list);
                            listasRestantes--;
                            quantidadeListas++;
                            printf(VERDE "!!Lista Ordenada[Lista %c] criada com sucesso!!\n" AMARELO "Voce tem %d espacos para lista sobrando!!\n" RESET,listas[indice].nome, listasRestantes);
                        }
                        break;
                    case 8:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        mostrarListaInversa(escolhido);
                        break;
                    }
                    case 9:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        ctrcEx = lerChar("Tem certeza? (s ou n)");
                        if(ctrcEx == 's'){
                            if(removerPares(escolhido)) printf("Pares removidos\n");
                        }else if(ctrcEx == 'n'){
                            printf("Voltando...\n");
                        }
                        break;
                    }
                    case 10:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        int indice = -1;
                        for(int i = 0; i < qntListas; i++){
                            if(listas[i].list == NULL){
                                indice = i;
                                break;
                            }
                        }
                        if(indice == -1){
                            printf(VERMELHO "Voce ja encheu seu espaco para listas!!\n" RESET);
                        }else{
                            ArrayListas *lista = escolherLista(listas, quantidadeListas);
                            if(lista == NULL) break;
                            listas[indice].nome = 'A' + quantidadeListas;
                            listas[indice].list = listaComImpares(lista->list);
                            listasRestantes--;
                            quantidadeListas++;
                            printf(VERDE "!!Lista Com IMPARES[Lista %c] criada com sucesso!!\n" AMARELO "Voce tem %d espacos para lista sobrando!!\n" RESET,listas[indice].nome, listasRestantes);
                        }
                        break;
                    }
                    case 11:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        int num = verMaior(escolhido);
                        printf("Numero maior na lista %c: %d\n", lista->nome, num);
                        break;
                    }
                    case 12:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        int num = verMenor(escolhido);
                        printf("Numero menor na lista %c: %d\n", lista->nome, num);
                        break;
                    }
                    case 13:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista = escolherLista(listas, quantidadeListas);
                        if(lista == NULL) break;
                        Lista *escolhido = lista->list;
                        int ind1 = lerInteiro("Digite o primeiro indice: ");
                        int ind2 = lerInteiro("Digite o segundo indice: ");
                        if(!trocarPosicao(escolhido, ind1, ind2)) printf("indice invalido!!\n");
                        else printf("Posicao trocada!!\n");
                        break;
                    }
                    case 14:{
                        if(quantidadeListas <= 0) {
                            printf("Voce ainda nao criou nenhuma lista\n");
                            break;
                        }
                        ArrayListas *lista1 = escolherLista(listas, quantidadeListas);
                        if(lista1 == NULL) break;
                        Lista *escolhido1 = lista1->list;
                        ArrayListas *lista2 = escolherLista(listas, quantidadeListas);
                        if(lista2 == NULL) break;
                        Lista *escolhido2 = lista2->list;
                        if(verificarIgualdade(escolhido1, escolhido2)) printf(VERDE "As listas sao IGUAIS!!\n"RESET);
                        else printf(VERMELHO "As listas sao DIFERENTES!!\n" RESET);
                        break;
                    }
                    case 15:
                        printf("Voltando...\n");
                        break;
                    default:
                        printf("Digite um numero entre 1 e 14!!\n");
                        break;
                }
            }
            break;
        }
        case 6:
            printf("Saindo...");
            break;
        default:
            printf("Numero invalido\n");
            break;
        }
    }
}