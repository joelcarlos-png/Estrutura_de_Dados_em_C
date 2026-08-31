#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "arvoretrie.h"

No *criarNo(){
    No *new = malloc(sizeof(No));
    for(int i = 0; i < 26; i++) new->letras[i] = NULL;
    new->palavra = false;
    
    return new;
}

void inserir(No **raiz, char *palavra){
    int i = palavra[0] - 'a';
    if((*raiz)->letras[i] == NULL) (*raiz)->letras[i] = criarNo();
    if(palavra[1] == '\0'){
        (*raiz)->letras[i]->palavra = true;
        return;
    }
    inserir((*raiz)->letras[i], palavra + 1);
}

bool verifFrenteVazio(No *raiz[]){
    for(int in = 0; in < 26; in++){
        if((*raiz)->letras[in] != NULL) return true;
    }
    return false;
}

static void excluirParci(No **raiz, char *palavraParci, No *ultimofim){
    if((*raiz) == ultimofim) return;
    No *pai;
    for(int i = 0; palavraParci[2] != '\0'; i ++){
        pai = ultimofim->letras[palavraParci[i] - 'a'];
    }
}

void excluir(No **raiz, char *palavra){
    No *ultimofim;
    char *palavraParci;
    int i = palavra[0] - 'a';
    if(palavra[0] == '\0') return;
    if(palavra[1] == '/0'){
        if(verifFrenteVazio(raiz)){
            (*raiz)->palavra = false;
            return;
        }
        

    }
    if((*raiz)->palavra == true){
        ultimofim = raiz;
        palavraParci = palavra;
    }
    excluir((*raiz)->letras[i], palavra + 1);
}

void procurar(No *raiz);