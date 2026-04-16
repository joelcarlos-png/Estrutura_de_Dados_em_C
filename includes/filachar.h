#ifndef FILACHAR_H
#define FILACHAR_H

typedef struct{
    char *vet;
    int fim;
    int inicio;
    int tam;
    int qtd;
}Fila;

Fila *criarFila(int tamanho);
bool inserir(Fila *f, char valor);
bool remover(Fila *f, char *valorRemovido);
bool isEmpty(Fila *f);
bool isFull(Fila *f);
void mostrarFila(Fila *f);
void painel(const char *tipo);
void liberar(Fila *f);
char lerChar(const char *pergunta);
double lerDouble(const char *pergunta);
int lerInteiro(const char *pergunta);
int queueSize(Fila *f);
bool queueClear(Fila *f);
void furarFila(Fila *f, char valor, int posicao);
int inverter(Fila *f);

#endif