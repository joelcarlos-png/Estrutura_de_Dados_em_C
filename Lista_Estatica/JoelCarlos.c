#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int fim, tam;
    char *valor;
}Lista;

Lista *criarLista(int tamanho){
    Lista *l = malloc(sizeof(Lista));
    l->valor = calloc(tamanho, sizeof(char));
    l->fim = -1;
    l->tam = tamanho;

    return l;
}

bool isFull(Lista *l){
    if(l->fim + 1 >= l->tam){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(Lista *l){
    if(l->fim <= -1){
        return true;
    }else{
        return false;
    }
}


bool inserirFinal(Lista *l, char valor){
    if(isFull(l)){return false;}

    l->fim++;
    l->valor[l->fim] = valor;

    return true;
}

bool inserirIndice(Lista *l, char valor, int indice){
    if(isFull(l) || indice < 0 || indice > l->fim + 1){return false;}

    l->fim++;
    for(int i = l->fim; i >= indice + 1; i--){
        l->valor[i] = l->valor[i - 1];
    }

    l->valor[indice] = valor;
    return true;
}

bool remover(Lista *l, int indice){
    if(isEmpty(l) || indice < 0 || indice > l->fim + 1){return false;}

    l->fim--;
    for(int i = indice; i <= l->fim; i++){
        l->valor[i] = l->valor[i + 1];
    }
    return true;
}

void mostrarLista(Lista *l){
    printf("[ ");    for(int i = 0; i < l->tam; i++){
        if(i > l->fim){
            printf(" 0");
        }else{
            printf(" %c", l->valor[i]);
        }

        if(i == l->fim){
            printf(" <-F");
        }

        if(i != l->tam -1){
            printf(",");
        }
    }
    printf(" ]\n");
}

void consultar(Lista *l, int indice){
    if(isEmpty(l) || indice < 0 || indice > l->fim){return false;}
    printf("[ %c ]", l->valor[indice]);
}

int main(){
    Lista *l = criarLista(10);
    inserirFinal(l, 'j');
    inserirFinal(l, 'e');
    inserirFinal(l, 'l');
    inserirFinal(l, 'c');
    mostrarLista(l);
    inserirIndice(l, 'o', 1);
    consultar(l, 1);
}
