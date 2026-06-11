#ifndef ARVOREPARCI_H
#define ARVOREPARCI_H

typedef struct no{
    struct no *esq, *dir;
    double chave;
}No;

typedef struct{
    No *raiz;
    int qtd;
}ARR;


/*
a. Inserir uma chave.
b. Retornar a menor chave.
c. Retornar a maior chave.
d. Exibir as chaves com os percursos pré-ordem, em-ordem e pósordem.
e. Procurar uma chave.
f. Excluir uma chave.
*/

ARR *criarARR();
No *criarNo(double val);

void inserir(No **raiz, double val);
double verMenor(No **raiz);
double verMaior(No **raiz);
void exibirPercursos(No **raiz);
    void preordem(No **raiz);
    void emordem(No **raiz);
    void posordem(No **raiz);
void procurar(No **raiz, double busca);
void excluir(No **raiz, double valor);

#endif