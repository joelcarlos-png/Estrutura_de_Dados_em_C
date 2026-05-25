#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "controle.h"
#include "ListaDupla.h"
#include "cores.h"

//funcao array list
void mostrarTodasListas(ArrayListas *listas, int qntListas){
    for(int i = 0; i < qntListas; i++){
        if(listas[i].list != NULL){ 
            printf(AZUL "Lista %c: " RESET, listas[i].nome);
            mostrarLista(listas[i].list);
        }
    }
}

ArrayListas *escolherLista(ArrayListas *listas, int qntListas){
    mostrarTodasListas(listas, qntListas);
    char ctrc = lerChar("Digite qual Lista voce quer Usar (exm: A, B, C): ");
    
    bool encontrado = false;
    int indice;
    for(int i = 0; i < qntListas; i++){
        if(ctrc == listas[i].nome){
            printf(VERDE "LISTA %c ESCOLHIDA\n" RESET, listas[i].nome);
            encontrado = true;
            indice = i;
            break;
        }
    }
    if(encontrado == false){
        printf(VERMELHO "Lista nao encontrada\n" RESET);
        return NULL;
    }

    return &listas[indice];
}

//Funcoes Maes
Lista *criarLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL) return NULL;
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

No *criarNo(TIPO valor){
    No *novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return NULL;
    novoNo->ante = NULL;
    novoNo->prox = NULL;
    novoNo->val = valor;

    return novoNo;
}

bool inserir(Lista *l, TIPO valor){
    if(l == NULL) return false;
    No *novoNo = criarNo(valor);
    if(novoNo == NULL) return false;
    
    if(isEmpty(l)){
        l->inicio = novoNo;
    }else{
        l->fim->prox = novoNo;
        novoNo->ante = l->fim;
    }
    l->fim = novoNo;

    l->qtd++;

    return true;
}


bool inserirPosicao(Lista *l, TIPO valor, int indice){
    if(l == NULL || indice < 0  || indice > l->qtd){return false;}
    
    if(indice == 0){
        if(isEmpty(l)){
            if(!inserir(l, valor)) return false;
            return true;
        }
        No *novoNo = criarNo(valor);

        l->inicio->ante = novoNo;
        novoNo->prox = l->inicio;
        l->inicio = novoNo;
        l->qtd++;
        return true;
    }
    
    No *aux = l->inicio;
    No *aux2 = l->inicio->prox;
    for(int i = 0; i != indice - 1; i++){
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    No *novoNo = criarNo(valor);
    
    novoNo->ante = aux;
    novoNo->prox = aux2;
    aux->prox = novoNo;
    if(aux2 != NULL){
        aux2->ante = novoNo;
    }
    
    if(novoNo->prox == NULL){
        l->fim = novoNo;
    }

    l->qtd++;
    return true;
}

bool remover(Lista *l, int indice, TIPO *valorRemovido){
    if(l == NULL || valorRemovido == NULL ||isEmpty(l) || indice < 0 || indice >= l->qtd) return false;
    
    No *aux = l->inicio;
    if(indice == 0){
        *valorRemovido = aux->val;
        if(l->qtd == 1){
            l->inicio = l->fim = NULL;
        }else{
            aux->prox->ante = NULL;
            l->inicio = aux->prox;
        }
        free(aux);
        l->qtd--;
        return true;
    }
    
    for(int i = 0; i < indice; i++){
        aux = aux->prox;
    }

    *valorRemovido = aux->val;
    if(aux->prox == NULL){
        aux->ante->prox = NULL;
        l->fim = aux->ante;
    }else{
        aux->ante->prox = aux->prox;
        aux->prox->ante = aux->ante;
    }
    free(aux);
    l->qtd--;
    return true;
}

bool isEmpty(Lista *l){
    if(l->inicio == NULL && l->fim == NULL){
        return true;
    }
    return false;
}

bool get(Lista *l, int indice, TIPO *valorGet){
    if(l == NULL || isEmpty(l) || indice < 0  || indice >= l->qtd ){return false;}
    No *aux = l->inicio;
    for(int i = 0; i != indice; i++){
        aux = aux->prox;
    }
    
    *valorGet = aux->val;
    return true;
}

//Funcoes a parte
bool mostrarLista(Lista *l){
    if(l == NULL) return false;
    printf(AMARELO "[" RESET);
    for(No *aux = l->inicio; aux != NULL; aux = aux->prox){
        printf(VERDE T_PRI RESET, aux->val);
        if(aux->prox != NULL){
            printf(AMARELO ", " RESET);
        }
    }
    if(isEmpty(l)){
        printf(MAGENTA "--vazia--" RESET);
    }
    printf(AMARELO "]" RESET "\n");
    return true;
}

void painel(int flag){
    if(flag == 1){
        printf("===========Lista===========\n");
        printf("1.Criar nova lista         \n"); 
        printf("2.Inserir                  \n");
        printf("3.Remover                  \n"); 
        printf("4.Ver Listas               \n");
        printf("5.Opcoes Exercicio         \n"); 
        printf("6.Sair                     \n");
        printf("===========================\n");
    }else if(flag == 2){
        printf("========OpcoesExercicio========\n");
        printf("1.Size                         \n");
        printf("2.Clear                        \n"); 
        printf("3.Ver Pares                    \n");
        printf("4.Ver Maiores                  \n"); 
        printf("5.Ver Primos                   \n");
        printf("6.Retornas lista com pares     \n");
        printf("7.Ordenar duas listas          \n");
        printf("8.Ver Inversa                  \n");
        printf("9.Remover Pares                \n");
        printf("10.Retornar lista com impares  \n");
        printf("11.Ver maior elemento          \n");
        printf("12.Ver menor elemento          \n");
        printf("13.Trocar posicao              \n");
        printf("14.Verif listas iguais         \n");
        printf("15.Voltar                      \n");
        printf("===============================\n");
    }else{
        return;
    }
}

bool verificarPrimo(int valor){
    if(valor <= 1) return false;
    int flag = 0;
    for(int i = 1; i <= valor; i++){
        if(valor % i == 0) flag++;
        if(flag > 2) break;
    }
    if(flag == 2) return true;
    return false;
}

//Funcoes do exercicio
int sizeLista(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;
    int qtd = 0;
    for(No *aux = l->inicio; aux != NULL; aux = aux->prox) qtd++;
    return qtd;
}//b

bool clearLista(Lista *l){
    if(l == NULL || isEmpty(l)) return true;
    TIPO v;
    while(remover(l, 0, &v));
    return true;
}//c

int verQntPares(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;
    TIPO valor;
    int indice = 0;
    int qnt = 0;
    while (get(l, indice, &valor)){
        if(valor % 2 == 0) qnt++;
        indice++;
    }

    return qnt;
}//d

int verQntMaiores(Lista *l, TIPO numero){
    if(l == NULL || isEmpty(l)) return 0;
    TIPO valor;
    int indice = 0, qnt = 0;
    while (get(l, indice, &valor)){
        if(valor > numero) qnt++;
        indice++;
    }

    return qnt;
}//e

int verQntPrimos(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;
    TIPO valor;
    int indice = 0, qnt = 0;
    while (get(l, indice, &valor)){
        if(verificarPrimo(valor)) qnt++;
        indice++;
    }

    return qnt;
}//f

Lista *listaComPares(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;
    Lista *aux = criarLista();
    TIPO valor;
    int indice = 0;
    while (get(l, indice, &valor)){
        if(valor % 2 == 0){
            inserir(aux, valor);
        }
        indice++;
    }

    return aux;
}//g

Lista *ordenarDuasListas(Lista *l1, Lista *l2){
    if(l1 == NULL && l2 == NULL) return NULL;

    Lista *l3 = criarLista();
    if(l3 == NULL) return NULL;

    TIPO valor1, valor2;
    int ind1 = 0, ind2 = 0;
    bool certo1 = get(l1, ind1, &valor1);
    bool certo2 = get(l2, ind2, &valor2);

    while (certo1 || certo2){
        if (!certo1){
            inserir(l3, valor2);
            ind2++;
            certo2 = get(l2, ind2, &valor2);
            continue;
        }

        if (!certo2){
            inserir(l3, valor1);
            ind1++;
            certo1 = get(l1, ind1, &valor1);
            continue;
        }

        if (valor1 < valor2){
            inserir(l3, valor1);
            ind1++;
            certo1 = get(l1, ind1, &valor1);
        } else if (valor1 > valor2) {
            inserir(l3, valor2);
            ind2++;
            certo2 = get(l2, ind2, &valor2);
        } else {
            inserir(l3, valor1);
            inserir(l3, valor2);
            ind1++; ind2++;
            certo1 = get(l1, ind1, &valor1);
            certo2 = get(l2, ind2, &valor2);
        }
    }

    return l3;
}//h

void mostrarListaInversa(Lista *l){
    if(l == NULL || isEmpty(l)) return;
    TIPO valor;
    int indice = sizeLista(l) - 1;
    printf("Lista Inversa: [");
    while (get(l, indice, &valor)){
        printf(T_PRI, valor);
        if(indice != 0){
            printf(", ");
        }
        indice--;
    }
    printf("]\n");
}//i

bool removerPares(Lista *l){
    if(l == NULL || isEmpty(l)) return false;
    TIPO valorRemovido;
    int i = 0;
    while(get(l, i, &valorRemovido)){
        if(valorRemovido % 2 == 0){
            remover(l, i, &valorRemovido);
            printf("Valor " AMARELO T_PRI VERMELHO" Removido\n" RESET, valorRemovido);
        }else{
            i++;
        }
    }
    return true;
}//j

Lista *listaComImpares(Lista *l){
    if(l == NULL || isEmpty(l)) return NULL;
    Lista *aux = criarLista();
    if(aux == NULL) return NULL;

    int indice = 0;
    TIPO valor;
    while (get(l, indice, &valor)){
        if(valor % 2 != 0){
            inserir(aux, valor);
        }
        indice++;
    }

    return aux;
}//k

TIPO verMaior(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;

    int indice = 1;
    TIPO valor;
    TIPO maior; 
    if(!get(l, 0, &maior)) return 0;
    while (get(l, indice, &valor)){
        if(valor > maior){
            maior = valor;
        }
        indice++;
    }

    return maior;
}//l

TIPO verMenor(Lista *l){
    if(l == NULL || isEmpty(l)) return 0;

    int indice = 1;
    TIPO valor;
    TIPO menor; 
    if(!get(l, 0, &menor)) return 0;
    while (get(l, indice, &valor)){
        if(valor < menor){
            menor = valor;
        }
        indice++;
    }

    return menor;
}//m

bool trocarPosicao(Lista *l, int indice1, int indice2){
    if(l == NULL || isEmpty(l)) return false;

    if(indice1 == indice2) return true;

    TIPO v1;
    if(!remover(l, indice1, &v1)) return false;
    if(!inserirPosicao(l, v1, indice2)) return false;
    if(indice1 < indice2){
        if(!remover(l, indice2 - 1, &v1)) return false;
    }else{
        if(!remover(l, indice2 + 1, &v1)) return false;
    }
    if(!inserirPosicao(l, v1, indice1)) return false;
    
    return true;
}//n

bool verificarIgualdade(Lista *l1, Lista *l2){
    if(l1 == NULL || l2 == NULL) return false;
    if(isEmpty(l1) && isEmpty(l2)) return true;
    if(sizeLista(l1) != sizeLista(l2)) return false;

    int i1 = 0, i2 = 0;
    TIPO v1, v2;
    while (get(l1, i1, &v1) && get(l2, i2, &v2)){
        if(v1 != v2) return false;
        i1++; i2++;
    }

    return true;
}//o 