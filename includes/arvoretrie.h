#ifndef ARVORETRIE_H
#define ARVORETRIE_H

#include <stdbool.h>

typedef struct no{
    struct no *letras[26]; 
    bool palavra;
}No;

No *criarNo();

void inserir(No **raiz, char *palavra);
bool procurar(No *raiz, char *palavra);
void excluir(No **raiz, char *palavra);
void mostrarTodas(No *raiz);

#endif