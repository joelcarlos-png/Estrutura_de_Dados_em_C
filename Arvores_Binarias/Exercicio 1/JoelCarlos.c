#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/arvoresBi.h"
#include "../includes/cores.h"
#include "../includes/controle.h"

void painel(){
	printf("============Arvore Binaria============"  "\n");
	printf("1. Inserir\n");
	printf("2. Verificar Menor\n");
	printf("3. Verificar Maior\n");
	printf("4. Exibir Percursos (Recursivo)\n");
	printf("5. Exibir Percursos (Iterativo)\n");
	printf("6. Quantidade de Nos\n");
	printf("7. Sair\n");
	printf("======================================="  "\n");
}

int main(){
	ABB *a = criarArvore();
	if(a == NULL){
		printf(VERMELHO "Nao foi possivel alocar memoria!!\n" RESET);
		exit(0);
	}

	int op = -1;
	while(op != 7){
		painel();
		op = lerInteiro("Digite sua opcao: ");

		switch(op){
		case 1:{
			int qtd = lerInteiro("Quantos valores deseja inserir: ");
			for(int i = 0; i < qtd; i++){
				char pergunta[64];
				sprintf(pergunta, "Valor %d: ", i + 1);
				int val = lerInteiro(pergunta);
				if(inserir(a, val)){
					printf(VERDE "Valor %d inserido com sucesso\n" RESET, val);
				}else{
					printf(VERMELHO "Valor %d ja existe na arvore\n" RESET, val);
				}
			}
			break;
		}
		case 2:{
			int menor = verifMenor(a);
			if(menor == -1){
				printf(VERMELHO "Arvore vazia\n" RESET);
			}else{
				printf(VERDE "Menor valor: %d\n" RESET, menor);
			}
			break;
		}
		case 3:{
			int maior = verifMaior(a);
			if(maior == -1){
				printf(VERMELHO "Arvore vazia\n" RESET);
			}else{
				printf(VERDE "Maior valor: %d\n" RESET, maior);
			}
			break;
		}
		case 4:
			exibirPercursos(a);
			break;
		case 5:
			exibirPercursosIterativo(a);
			break;
		case 6:
			printf(VERDE "Quantidade de nos: %d\n" RESET, a->qtd);
			break;
		case 7:
			printf(AMARELO "Saindo...\n" RESET);
			break;
		default:
			printf(VERMELHO "Digite um numero de 1 a 7\n" RESET);
			break;
		}
	}

	free(a);
	return 0;
}