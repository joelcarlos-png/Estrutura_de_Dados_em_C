#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filacharE.h"
#include "pilhaChar.h"

Fila *criarFila(){
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}

void painel(){
    printf("=====================================\n");
    printf("1.  Inserir                          \n");
    printf("2.  Remover                          \n");
    printf("3.  Mostrar Quantidade               \n");
    printf("4.  Clear Fila                       \n");
    printf("5.  Mostrar elementos                \n");
    printf("6.  Mostrar Quanidade e remover      \n");
    printf("7.  Remover e mostrar inversa        \n");
    printf("8.  Inverter Valores sem remover     \n");
    printf("9.  Ler palavra e inserir caracteres \n");
    printf("10. Sair do Programa                 \n");
    printf("=====================================\n");
}

bool inserir(Fila *f, char valor){
    No *novoNo = malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if(isEmpty(f)){
        f->inicio = novoNo;
    }else{
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;

    f->qtd++;
    return true;
}

bool remover(Fila *f, char *valorRemovido){
    if(isEmpty(f)){printf("!!Fila Vazia!!\n"); return false;}
    No *noRemovido = f->inicio;
    *valorRemovido = noRemovido->valor;
    f->inicio = noRemovido->proximo;

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(noRemovido);
    f->qtd--;
    return true;
}

bool isEmpty(Fila *f){
    if(f->fim == NULL && f->inicio == NULL){
        return true;
    }
    return false;
}

bool size(Fila *f, int *quantidadeDeElementos){
    Fila *aux = clonarFila(f);

    *quantidadeDeElementos = 0;

    while (!isEmpty(aux)){
        char valorRemovido;
        remover(aux, &valorRemovido);

        (*quantidadeDeElementos)++;
    }
    liberarFila(aux);
    return true;
}

Fila *clonarFila(Fila *orig){
    if (orig == NULL) return NULL;

    Fila *aux = criarFila();
    if (aux == NULL) return NULL;

    No *atual = orig->inicio;
    while (atual != NULL){
        inserir(aux, atual->valor);
        atual = atual->proximo;
    }

    return aux;
}

bool clear(Fila *f){
    if(isEmpty(f)){return false;}

    while (!isEmpty(f)){
        char valorRemovido;
        remover(f, &valorRemovido);
    }
    return true;
}

bool mostrarFila(Fila *f){
    if(isEmpty(f)){printf("!!Fila Vazia!!\n"); return false;}
    Fila *aux = clonarFila(f);

    printf("<-- ");
    while (!isEmpty(aux)){
        char valorRemovido;
        remover(aux, &valorRemovido);
        printf("%c ", valorRemovido);
    }
    printf("<--\n");
    liberarFila(aux);
    return true;
}

bool inverter(Fila *f){
    if(isEmpty(f)){printf("!!Fila Vazia!!"); return false;}
    PilhaChar aux;

    int quantidadeFila;
    size(f, &quantidadeFila);
    criarPilhaChar(&aux, quantidadeFila);

    while (!isEmpty(f)){
        char valorRemovido;
        remover(f, &valorRemovido);

        pushchar(&aux, valorRemovido);
    }

    while (!isEmptychar(&aux)){
        char valorRemovidPilha = popchar(&aux);
        inserir(f, valorRemovidPilha);
    }
    return true;
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

char lerChar(const char *pergunta){
    char x;
    printf("%s", pergunta);
    while (scanf(" %c", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO CARACTERE(CHAR)!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

void liberarFila(Fila *f){
    if (f == NULL){
        return;
    }

    No *atual = f->inicio;
    while (atual != NULL){
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    free(f);
}