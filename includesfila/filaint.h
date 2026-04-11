#ifndef FILAINT_H
#define FILAINT_H

typedef struct{
    int *vet;
    int fim;
    int inicio;
    int tam;
    int qtd;
}Fila;

Fila *criarFila(int tamanho);
int inserir(Fila *f, int valor);
int remover(Fila *f);
int isEmpty(Fila *f);
int isFull(Fila *f);
void mostrarFila(Fila *f);
void painel();
void liberar(Fila *f);
int lerInteiro(const char *pergunta);

#endif