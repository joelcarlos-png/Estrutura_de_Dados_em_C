#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filacharE.h"

Fila *criarFila(){
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}

bool inserir(Fila *f, char valor);
bool remover(Fila *f, char *valorRemovido);
bool isEmpty(Fila *f);
int size(Fila *f);
void clear(Fila *f);
void mostrarFila(Fila *f);
void inverter(Fila *f);

int lerInteiro(const char *pergunta){
    int x;
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO INTEIRO!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

int lerChar(const char *pergunta){
    char x;
    while (scanf("%c", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO CARACTERE(CHAR)!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

void liberarFila(Fila *f);