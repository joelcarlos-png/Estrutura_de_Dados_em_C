#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/arvoreavl.h"
#include "../includes/cores.h"
#include "../includes/controle.h"

void painel(){
	printf("============Arvore AVL============"  "\n");
	printf("1. Inserir\n");
	printf("2. Remover\n");
	printf("3. Buscar\n");
	printf("4. Menor\n");
	printf("5. Maior\n");
	printf("6. Altura\n");
	printf("7. Fator\n");
	printf("8. Qtd\n");
	printf("9. Sair\n");
	printf("==================================="  "\n");
}

int main(){
	ARR *a = criarArvore();
	if(a == NULL){
		printf(VERMELHO "Nao foi possivel alocar memoria!!\n" RESET);
		exit(0);
	}

	int op = -1;
	while(op != 9){
		painel();
		op = lerInteiro("Digite sua opcao: ");

		switch(op){
		case 1:{
			int qtd = lerInteiro("Quantos valores deseja inserir: ");
			for(int i = 0; i < qtd; i++){
				char pergunta[64];
				sprintf(pergunta, "Chave %d: ", i + 1);
				int chave = lerInteiro(pergunta);

				printf("Nome %d: ", i + 1);
				while(getchar() != '\n');
				char nome[50];
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = '\0';

				inserir(&a->raiz, chave, nome);
				printf(VERDE "Valor %d inserido com sucesso\n" RESET, chave);
			}
			break;
		}
		case 2:{
			int chave = lerInteiro("Chave para remover: ");
			if(get(a->raiz, chave) != NULL){
				remover(&a->raiz, chave);
				printf(VERDE "Valor %d removido com sucesso\n" RESET, chave);
			}else{
				printf(VERMELHO "Chave %d nao existe na arvore\n" RESET, chave);
			}
			break;
		}
		case 3:{
			int chave = lerInteiro("Chave para buscar: ");
			const char *nome = get(a->raiz, chave);
			if(nome != NULL){
				printf(VERDE "Chave %d -> Nome: %s\n" RESET, chave, nome);
			}else{
				printf(VERMELHO "Chave %d nao existe na arvore\n" RESET, chave);
			}
			break;
		}
		case 4:{
			if(a->raiz == NULL){
				printf(VERMELHO "Arvore vazia\n" RESET);
			}else{
				printf(VERDE "Menor valor: %d\n" RESET, verMenor(a->raiz));
			}
			break;
		}
		case 5:{
			if(a->raiz == NULL){
				printf(VERMELHO "Arvore vazia\n" RESET);
			}else{
				printf(VERDE "Maior valor: %d\n" RESET, verMaior(a->raiz));
			}
			break;
		}
		case 6:
			printf(VERDE "Altura da arvore: %d\n" RESET, altura(a->raiz));
			break;
		case 7:
			printf(VERDE "Fator de balanceamento: %d\n" RESET, fatorBalanceamento(a->raiz));
			break;
		case 8:
			printf(VERDE "Quantidade de nos: %d\n" RESET, a->qtd);
			break;
		case 9:
			printf(AMARELO "Saindo...\n" RESET);
			break;
		default:
			printf(VERMELHO "Digite um numero de 1 a 9\n" RESET);
			break;
		}
	}

	free(a);
	return 0;
}