#ifndef ARVORETRIE_H
#define ARVORETRIE_H

#include <stdbool.h>

typedef struct no{
    struct no *letras[26]; 
    bool palavra;
}No;

No *criarNo();

bool verifFrenteVazio(No *raiz[]);

void inserir(No **raiz, char *palavra);
void procurar(No **raiz, char *palavra);
void excluir(No **raiz);

#endif