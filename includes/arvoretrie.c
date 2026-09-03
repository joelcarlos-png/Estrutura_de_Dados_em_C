#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "arvoretrie.h"

No *criarNo(){
    No *new = malloc(sizeof(No));
    for(int i = 0; i < 26; i++) new->letras[i] = NULL;
    new->palavra = false;
    
    return new;
}

void inserir(No **raiz, char *palavra){
    int i = tolower((unsigned char)palavra[0]) - 'a';
    if(i < 0 || i >= 26) return;
    if((*raiz)->letras[i] == NULL) (*raiz)->letras[i] = criarNo();
    if(palavra[1] == '\0'){
        (*raiz)->letras[i]->palavra = true;
        return;
    }
    inserir(&(*raiz)->letras[i], palavra + 1);
}

static bool verifFrenteVazio(No *raiz[]){
    for(int in = 0; in < 26; in++){
        if((*raiz)->letras[in] != NULL) return false;
    }
    return true;
}

void excluir(No **raiz, char *palavra){
    int i = tolower(palavra[0]) - 'a';
    if(i < 0 || i >= 26 || (*raiz)->letras[i] == NULL) return;
    if(palavra[1] == '\0'){
        (*raiz)->letras[i]->palavra = false;
        if(verifFrenteVazio(&(*raiz)->letras[i])){
            free((*raiz)->letras[i]);
            (*raiz)->letras[i] = NULL;
        }
        return;
    }
    excluir(&(*raiz)->letras[i], palavra + 1);
    if((*raiz)->letras[i] != NULL && verifFrenteVazio(&(*raiz)->letras[i]) && (*raiz)->letras[i]->palavra == false){
        free((*raiz)->letras[i]);
        (*raiz)->letras[i] = NULL;
    }
}

bool procurar(No *raiz, char *palavra){
    if(palavra[0] == '\0') return false;
    int i = tolower(palavra[0]) - 'a';
    if(i < 0 || i >= 26 || raiz->letras[i] == NULL) return false;
    if(palavra[1] == '\0') return raiz->letras[i]->palavra;
    return procurar(raiz->letras[i], palavra + 1);
}

//funcoes feita com IA, somente para verificacao de integridade das funcoes acima
static void imprimirPalavras(No *raiz, char *buffer, int nivel){                                                                   
    if(raiz == NULL) return;                                                                                                       
    for(int i = 0; i < 26; i++){                                                                                                   
        if(raiz->letras[i] != NULL){                                                                                                                                                                              
            buffer[nivel] = 'a' + i;                                                                                               
            if(raiz->letras[i]->palavra == true){                                                                                  
                buffer[nivel + 1] = '\0';                                                                     
                printf("%s\n", buffer);                                                                                            
            }                                                                                                                      
            imprimirPalavras(raiz->letras[i], buffer, nivel + 1);                                                                  
        }                                                                                                                          
    }                                                                                                                              
}

void mostrarTodas(No *raiz){                                                                                                       
    char buffer[100];                                                                          
    imprimirPalavras(raiz, buffer, 0);                                                                                             
} 