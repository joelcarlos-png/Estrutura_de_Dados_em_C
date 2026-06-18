#ifndef ARVORESBI_H
#define ARVORESBI_H

typedef int TIPO;
#define T_ "%d"

typedef struct no{
    TIPO val;
    struct no *dir, *esq;
}No;

typedef struct{ 
    No *raiz;
    int qtd;
}ABB;

ABB *criarArvore();
bool inserir(ABB *a, TIPO val);
TIPO verifMenor(ABB *a);
TIPO verifMaior(ABB *a);
void exibirPercursos(ABB *a);
void exibirPercursosIterativo(ABB *a);

//lista revisao


#endif