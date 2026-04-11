#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

Fila *criarFila(int tamanho){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = malloc(tamanho * sizeof(int));
    f->fim = -1;
    f->inicio = 0;
    f->tam = tamanho;
    f->qtd = 0;
    return f;
}

int inserir(Fila *f, int valor){
    if(isFull(f) == 1){return 0;}
    if(f->fim == f->tam - 1){
        f->fim = -1;
    }
    f->fim++;
    f->vet[f->fim] = valor;
    f->qtd++;
    return 1;
}

int remover(Fila *f){
    if(isEmpty(f) == 1){return 0;}
    int valorRemovido = f->vet[f->inicio];
    
    if(f->inicio == f->tam - 1){
        f->inicio = -1;
    }
    
    f->inicio++;

    f->qtd--;
    if(f->qtd <= 0){
        f->inicio = 0;
        f->fim = -1;
    }

    return valorRemovido;
}

int isEmpty(Fila *f){
    if(f->qtd <= 0){
        printf("!!Fila Vazia!!");
        return 1;
    }
    return 0;
}

int isFull(Fila *f){
    if(f->qtd >= f->tam){
        printf("!!Fila Cheia!!");
        return 1;
    }
    return 0;
}

void mostrarFila(Fila *f){
    Fila aux = *f;
    printf("Quantidade de elementos da fila: %d\n", aux.qtd);
    printf("<-- ");
    if (isEmpty(&aux) == 1){
    } else {
        int i = 0;
        int j = aux.qtd;
        while(i < j) {
            int valor = remover(&aux);

            printf("%d ", valor);
            i++;
        }
    }
    
    printf("<--\n\n");
}

void painel(){
    printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Sair\n====================\n\nDigite sua opcao: ");
}

void liberar(Fila *f){
    if (f == NULL) {
        return;
    }

    free(f->vet);
    free(f);
}

int lerInteiro(const char *pergunta){
    int x;
    printf("%s", pergunta);
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO INTEIROS!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}