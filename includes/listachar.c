#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listachar.h"
#include "controle.h"

Lista *criarLista(int tamanho){
    Lista *l = malloc(sizeof(Lista));
    l->valor = calloc(tamanho, sizeof(char));
    l->fim = -1;
    l->tam = tamanho;

    return l;
}

bool isFull(Lista *l){
    if(l->fim + 1 >= l->tam){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(Lista *l){
    if(l->fim <= -1){
        return true;
    }else{
        return false;
    }
}


bool inserirFinal(Lista *l, char valor){
    if(isFull(l)){return false;}

    l->fim++;
    l->valor[l->fim] = valor;

    return true;
}

bool inserirIndice(Lista *l, char valor, int indice){
    if(isFull(l) || indice < 0 || indice > l->fim + 1){return false;}

    l->fim++;
    for(int i = l->fim; i >= indice + 1; i--){
        l->valor[i] = l->valor[i - 1];
    }
 
    l->valor[indice] = valor;
    return true;
}

bool remover(Lista *l, int indice, char *valoreRemovido){
    if(isEmpty(l) || indice < 0 || indice > l->fim + 1){return false;}

    *valoreRemovido = l->valor[indice];

    l->fim--;
    for(int i = indice; i <= l->fim; i++){
        l->valor[i] = l->valor[i + 1];
    }
    return true;
}

void mostrarLista(Lista *l){
    printf("[ ");
    for(int i = 0; i < l->tam; i++){
        if(i > l->fim){
            printf(" 0");
        }else{
            printf(" %c", l->valor[i]);
        }

        if(i == l->fim){
            printf(" <-F");
        }

        if(i != l->tam -1){
            printf(",");
        }
    }
    printf(" ]\n");
}

bool mostarInversa(Lista *l){
    printf("[ ");
    for(int i = l->tam - 1; i >= 0; i--){
        if(i > l->fim){
            printf(" 0");
        }else{
            printf(" %c", l->valor[i]);
        }

        if(i == l->fim){
            printf(" <-F");
        }

        if(i != 0){
            printf(",");
        }
    }
    printf(" ]\n");
}


bool consultar(Lista *l, int indice){
    if(isEmpty(l) || indice < 0 || indice > l->fim){return false;}
    printf("Valor no indice %d: [ %c ]\n",indice, l->valor[indice]);
    return true;
}

bool sizeLista(Lista *l, int *tamanhoLista){
    *tamanhoLista = l->fim + 1;
    return true;
}

bool clearLista(Lista *l){
    while (!isEmpty(l)){
        char valor;
        remover(l, 0, &valor);
    }
    return true;
}

bool ordenar(Lista *l, int flag){
    Lista *aux = criarLista(l->fim + 1);

    while(!isEmpty(l)){
        char valorRemovido;
        remover(l, 0, &valorRemovido);
        inserirFinal(aux, valorRemovido);
    }

    char valorRemov;
    while (!isEmpty(aux)){
        int menorindice = 0;
        char menor = aux->valor[0];

        for(int i = 0; i < aux->fim + 1; i++){
            if(flag == 0){
                if(aux->valor[i] < menor){
                    menor = aux->valor[i];
                    menorindice = i;
                }
            }else if(flag == 1){
                if(aux->valor[i] > menor){
                    menor = aux->valor[i];
                    menorindice = i;
                }
            }
        }

        remover(aux, menorindice, &valorRemov);
        inserirFinal(l, valorRemov);
    }
    return true;
}

void painel(){
    printf("==---==<| OpcoesLista |>==---==\n");
    printf("1.Inserir pelo Indice          \n");
    printf("2.Remover pelo Indice          \n");
    printf("3.Mostrar quantidade           \n");
    printf("4.Clear na Lista               \n");
    printf("5.Mostrar Lista                \n");
    printf("6.Mostrar quantidade e Clear   \n");
    printf("7.Mostrar inversa e Clear      \n");      
    printf("8.Ler palavra e inserir        \n");      
    printf("9.Ordenar(A - Z)               \n");      
    printf("10.Ordenar(Z - A)              \n");      
    printf("11.Sair                        \n");      
    printf("==---==<|>===========<|>==---==\n");
}