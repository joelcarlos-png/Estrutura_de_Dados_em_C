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

void excluir(No **raiz, char *palavra){
    int i = palavra[0] - 'a';
    if(palavra[1] != '\0') excluir((*raiz)->letras[i], palavra + 1);
    bool vazio = true;
    for(int in = 0; in < 26; in++){
        if((*raiz)->letras[i]->letras[in] != NULL) vazio = false;
    }
    if(!(*raiz)->letras[i]->palavra);
    if((*raiz)->letras[i]->palavra) ;

}

void procurar(No *raiz);