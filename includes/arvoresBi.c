#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvoresBi.h"
#include "cores.h"

ABB *criarArvore(){
    ABB *a = malloc(sizeof(ABB));
    if(a == NULL){return NULL;}
    a->raiz = NULL;
    a->qtd = 0;

    return a;
}

No *criarNo(TIPO val){
    No *n = malloc(sizeof(No));
    n->val = val;
    n->esq = NULL;
    n->dir = NULL;

    return n;
}

bool inserir(ABB *a, TIPO val){
    if(a->raiz == NULL){
        No *novo = criarNo(val);
        a->raiz = novo;
        a->qtd++;
        return true;
    }

    No *atual = a->raiz;
    bool flag = false;

    while(1){
        if(val < atual->val){
            if(atual->esq == NULL){
                atual->esq = criarNo(val);
                a->qtd++;
                flag = true;
                break;
            }
            atual = atual->esq;
        }else if(val > atual->val){
            if(atual->dir == NULL){
                atual->dir = criarNo(val);
                a->qtd++;
                flag = true;
                break;
            }
            atual = atual->dir;
        }else{
            break;
        }
    }

    return flag;
}   

TIPO verifMenor(ABB *a){
	if(a->raiz == NULL){return -1;}
	No *atual = a->raiz;
	while(atual->esq != NULL){
		atual = atual->esq;
	}
	return atual->val;
}

TIPO verifMaior(ABB *a){
	if(a->raiz == NULL){return -1;}
	No *atual = a->raiz;
	while(atual->dir != NULL){
		atual = atual->dir;
	}
	return atual->val;
}

void preOrdem(No *n){
	if(n == NULL){return;}
	printf(T_ " ", n->val);
	preOrdem(n->esq);
	preOrdem(n->dir);
}

void emOrdem(No *n){
	if(n == NULL){return;}
	emOrdem(n->esq);
	printf(T_ " ", n->val);
	emOrdem(n->dir);
}

void posOrdem(No *n){
	if(n == NULL){return;}
	posOrdem(n->esq);
	posOrdem(n->dir);
	printf(T_ " ", n->val);
}

void exibirPercursos(ABB *a){
	if(a->raiz == NULL){printf(VERMELHO "Arvore vazia\n" RESET);return;}
	printf(AMARELO "Pre-Ordem: " RESET);
	preOrdem(a->raiz);
	printf("\n");
	printf(AMARELO "Em-Ordem:  " RESET);
	emOrdem(a->raiz);
	printf("\n");
	printf(AMARELO "Pos-Ordem: " RESET);
	posOrdem(a->raiz);
	printf("\n");
}

void exibirPercursosIterativo(ABB *a){
	if(a->raiz == NULL){printf(VERMELHO "Arvore vazia\n" RESET);return;}

	No *pilha[1000];
	int topo = 0;

	printf(AMARELO "Pre-Ordem (Iterativo): " RESET);
	pilha[topo++] = a->raiz;
	while(topo > 0){
		No *atual = pilha[--topo];
		printf(T_ " ", atual->val);
		if(atual->dir != NULL){pilha[topo++] = atual->dir;}
		if(atual->esq != NULL){pilha[topo++] = atual->esq;}
	}
	printf("\n");

	printf(AMARELO "Em-Ordem (Iterativo):  " RESET);
	{
		No *pilha2[1000];
		int topo2 = 0;
		No *atual = a->raiz;
		while(topo2 > 0 || atual != NULL){
			while(atual != NULL){
				pilha2[topo2++] = atual;
				atual = atual->esq;
			}
			atual = pilha2[--topo2];
			printf(T_ " ", atual->val);
			atual = atual->dir;
		}
	}
	printf("\n");

	printf(AMARELO "Pos-Ordem (Iterativo): " RESET);
	{
		No *pilha3[1000];
		int topo3 = 0;
		No *ultimoVisitado = NULL;
		No *atual = a->raiz;
		while(topo3 > 0 || atual != NULL){
			if(atual != NULL){
				pilha3[topo3++] = atual;
				atual = atual->esq;
			}else{
				No *topoNo = pilha3[topo3 - 1];
				if(topoNo->dir != NULL && topoNo->dir != ultimoVisitado){
					atual = topoNo->dir;
				}else{
					printf(T_ " ", topoNo->val);
					ultimoVisitado = topoNo;
					topo3--;
				}
			}
		}
	}
	printf("\n");
}