#ifndef FILAREAL_H
#define FILAREAL_H

typedef struct{
    double *vet;
    int fim;
    int inicio;
    int tam;
    int qtd;
}Fila;

Fila *criarFila(int tamanho);
bool inserir(Fila *f, double valor);
bool remover(Fila *f, double *valorRemovido);
bool isEmpty(Fila *f);
bool isFull(Fila *f);
void mostrarFila(Fila *f);
void painel(const char *tipo);
void liberar(Fila *f);
double lerDouble(const char *pergunta);
int lerInteiro(const char *pergunta);
int queueSize(Fila *f);
bool queueClear(Fila *f);
void mostrarInversa(Fila *f);

#endif