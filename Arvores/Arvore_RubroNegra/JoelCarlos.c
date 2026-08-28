#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/arvorerb.h"
#include "../includes/cores.h"
#include "../includes/controle.h"

static void liberarArvore(No *raiz){
	if(raiz == NULL) return;
	liberarArvore(raiz->esq);
	liberarArvore(raiz->dir);
	free(raiz);
}

void painel(){
	printf("============Arvore Rubro-Negra============"  "\n");
	printf("1. Inserir\n");
	printf("2. Exibir Percursos\n");
	printf("3. Mostrar Pares Pretos\n");
	printf("4. Quantidade de Impares Vermelhos\n");
	printf("5. Sair\n");
	printf("=========================================="  "\n");
}

int main(){
	No *raiz = NULL;

	int op = -1;
	while(op != 5){
		painel();
		op = lerInteiro("Digite sua opcao: ");

		switch(op){
		case 1:{
			int qtd = lerInteiro("Quantos valores deseja inserir: ");
			for(int i = 0; i < qtd; i++){
				char pergunta[64];
				sprintf(pergunta, "Valor %d: ", i + 1);
				int val = lerInteiro(pergunta);
				inserir(&raiz, val);
				printf(VERDE "Valor %d inserido com sucesso\n" RESET, val);
			}
			break;
		}
		case 2:
			percursos(raiz);
			printf("\n");
			break;
		case 3:
			parPreto(raiz);
			printf("\n");
			break;
		case 4:
			qntImparVermelho(raiz);
			printf("\n");
			break;
		case 5:
			printf(AMARELO "Saindo...\n" RESET);
			break;
		default:
			printf(VERMELHO "Digite um numero de 1 a 5\n" RESET);
			break;
		}
	}

	liberarArvore(raiz);
	return 0;
}