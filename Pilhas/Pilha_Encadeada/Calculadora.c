#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    float valor;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, float valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

float pop(Pilha *p) {
    if (p->topo == NULL) {
        return 0; 
    }
    No *temp = p->topo;
    float valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int main() {
    Pilha p;
    inicializar(&p);
    
    char expressao[100];
    char *token;

    printf("Digite a expressao pos-fixa(N1 N2 operador(+,-,*,/)): ");
    fgets(expressao, 100, stdin);

    token = strtok(expressao, " \n");

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
            float op2 = pop(&p); 
            float op1 = pop(&p);
            float resultado;

            if (strcmp(token, "+") == 0) resultado = op1 + op2;
            else if (strcmp(token, "-") == 0) resultado = op1 - op2;
            else if (strcmp(token, "*") == 0) resultado = op1 * op2;
            else if (strcmp(token, "/") == 0) {
                if (op2 != 0) resultado = op1 / op2;
                else {
                    printf("Erro: Divisao por zero!\n");
                    return 1;
                }
            }
            push(&p, resultado);
        } 
        else {
            push(&p, atof(token));
        }
        token = strtok(NULL, " \n");
    }

    printf("Resultado Final: %.2f\n", pop(&p));

    return 0;
}