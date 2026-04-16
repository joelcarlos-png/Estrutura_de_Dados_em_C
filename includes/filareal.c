#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "filareal.h"
#include "pilhafloat.h"


Fila *criarFila(int tamanho){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = malloc(tamanho * sizeof(double));
    f->fim = -1;
    f->inicio = 0;
    f->tam = tamanho;
    f->qtd = 0;
    return f;
}

bool inserir(Fila *f, double valor){
    if(isFull(f)){return false;}
    if(f->fim == f->tam - 1){
        f->fim = -1;
    }
    f->fim++;
    f->vet[f->fim] = valor;
    f->qtd++;
    return true;
}

bool remover(Fila *f, double *valorRemovido){
    if(isEmpty(f)){return false;}
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
        printf("!!Fila Vazia!!");
        return true;
    }
    return false;
}

bool isFull(Fila *f){
    if(f->qtd >= f->tam){
        printf("!!Fila Cheia!!");
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
            double valor;
            remover(&aux, &valor);

            printf("%.2f ", valor);
            i++;
        }
    }
    
    printf("<--\n\n");
}

void painel(const char *tipo){
    if(strcmp(tipo, "geral") == 0){
        printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Exercicio 3\n5.Sair\n====================\n\n");
    }else if(strcmp(tipo, "exercicio3") == 0){
        printf("====OPCOES-EXC3====\n1.Retorna Quantidade\n2.Clear na Fila\n3.Ver Fila inversa\n4.Voltar\n====================\n\n");
    }
    
}

void liberar(Fila *f){
    if (f == NULL) {
        return;
    }

    free(f->vet);
    free(f);
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
    double valor;
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
        double valorRemovido;
        remover(f,&valorRemovido);
    }
    printf("!!Fila limpa com sucesso!!\n");
    return true;
}

void mostrarInversa(Fila *f){
    Fila faux = *f;
    Pilha paux;
    criarPilha(&paux, f->qtd);

    int a = faux.qtd;
    for(int i = 0; i < a; i++){
        double valorRemovidoFila; 
        remover(&faux, &valorRemovidoFila);
        push(&paux, valorRemovidoFila);
    }

    printf("Fila Inversa:\n -->");
    for(int i = 0; i < f->qtd; i++){
        double valor = pop(&paux);
        printf("%.2lf ", valor);
    }
    printf("-->\n");

    liberarPilha(&paux);
}