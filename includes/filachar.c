#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "filachar.h"
#include "pilhafloat.h"
#include "pilhaChar.h"


Fila *criarFila(int tamanho){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = malloc(tamanho * sizeof(char));
    f->fim = -1;
    f->inicio = 0;
    f->tam = tamanho;
    f->qtd = 0;
    return f;
}

bool inserir(Fila *f, char valor){
    if(isFull(f)){printf("!!Fila Cheia!!\n");return false;}
    if(f->fim == f->tam - 1){
        f->fim = -1;
    }
    f->fim++;
    f->vet[f->fim] = valor;
    f->qtd++;
    return true;
}

bool remover(Fila *f, char *valorRemovido){
    if(isEmpty(f)){printf("!!Fila Vazia!!\n");return false;}
    *valorRemovido = f->vet[f->inicio];
    
    if(f->inicio == f->tam - 1){
        f->inicio = -1;
    }
    
    f->inicio++;

    f->qtd--;
    if(f->qtd <= 0){
        f->inicio = 0;
        f->fim = -1;
    }

    return true;
}

bool isEmpty(Fila *f){
    if(f->qtd <= 0){
        return true;
    }
    return false;
}

bool isFull(Fila *f){
    if(f->qtd >= f->tam){
        return true;
    }
    return false;
}

void mostrarFila(Fila *f){
    Fila aux = *f;
    printf("Quantidade de elementos da fila: %d\n", aux.qtd);
    printf("<-- ");
    if (isEmpty(&aux)){
    } else {
        int i = 0;
        int j = aux.qtd;
        while(i < j) {
            char valor;
            remover(&aux, &valor);

            printf("%c ", valor);
            i++;
        }
    }
    
    printf("<--\n\n");
}

void painel(const char *tipo){
    if(strcmp(tipo, "geral") == 0){
        printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Exercicio 4\n5.Sair\n====================\n\n");
    }else if(strcmp(tipo, "exercicio3") == 0){
        printf("====OPCOES-EXC3====\n1.Retorna Quantidade\n2.Clear na Fila\n3.Pular fila\n4.Voltar\n====================\n\n");
    }
}

void liberar(Fila *f){
    if (f == NULL) {
        return;
    }

    free(f->vet);
    free(f);
}

char lerChar(const char *pergunta){
    char x;
    printf("%s", pergunta);
    while (scanf(" %c", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO CHAR!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

double lerDouble(const char *pergunta){
    double x;
    printf("%s", pergunta);
    while (scanf("%lf", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO DOUBLE!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

int lerInteiro(const char *pergunta){
    int x;
    printf("%s", pergunta);
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO INTEIRO!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

int queueSize(Fila *f){
    Fila aux = *f;
    char valor;
    int quantidade = 0;

    while (remover(&aux, &valor)){
        quantidade++;
    }
    
    printf("\n");
    return quantidade;
}

bool queueClear(Fila *f){
    if(isEmpty(f)){return false;}
    int a = f->qtd;
    for(int i = 0; i < a; i++){
        char valorRemovido;
        remover(f,&valorRemovido);
    }
    return true;
}

void furarFila(Fila *f, char valor, int posicao){
    Fila *aux = criarFila(f->tam);
    int quantidade = f->qtd;

        if(posicao < 1 || posicao > f->qtd + 1){
            printf("posicao invalida\nUse de 1 ate %d.\n", f->qtd + 1);
            false;
        }

        for(int i = 0; i < quantidade; i++){
            char valorRemovido;
            remover(f, &valorRemovido);
            if(i == posicao - 1){inserir(aux, valor);}
            inserir(aux, valorRemovido);
        }

        if(posicao - 1 == quantidade){
            inserir(aux, valor);
        }

        while (!isEmpty(aux)){
            char valorRemovido;
            remover(aux, &valorRemovido);
            inserir(f, valorRemovido);
        }
        printf("\n");
        liberar(aux);

        mostrarFila(f);
}

int inverter(Fila *f){
    PilhaChar aux;
    criarPilhaChar(&aux, f->qtd);

    if(isEmpty(f)){
        printf("Fila vazia!");
        return 0;
    }

    int quantidade = f->qtd;

    for(int i = 0; i < quantidade; i++){
        char valor;
        remover(f, &valor);
        pushchar(&aux, valor);
    }

    for(int i = 0; i < quantidade; i++){
        char valorpilha = popchar(&aux);
        inserir(f, valorpilha);
    }
    liberarPilhachar(&aux);
    return 1;
}
