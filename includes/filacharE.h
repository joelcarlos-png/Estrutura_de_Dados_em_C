#ifndef FILACHARE_H
#define FILACHARE_H

typedef struct{
    char valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Fila;

Fila *criarFila();
bool inserir(Fila *f, char valor);
bool remover(Fila *f, char *valorRemovido);
bool isEmpty(Fila *f);
int size(Fila *f);
void clear(Fila *f);
void mostrarFila(Fila *f);
void inverter(Fila *f);
int lerInteiro(const char *pergunta);
char lerChar(const char *pergunta);
void liberarFila(Fila *f);

#endif