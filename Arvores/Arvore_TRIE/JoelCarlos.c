#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../../includes/arvoretrie.h"
#include "../../includes/cores.h"
#include "../../includes/controle.h"

static void paraMinusculo(char *str){
	for(int i = 0; str[i]; i++){
		str[i] = tolower((unsigned char)str[i]);
	}
}

static void liberarArvore(No *raiz){
	if(raiz == NULL) return;
	for(int i = 0; i < 26; i++){
		liberarArvore(raiz->letras[i]);
	}
	free(raiz);
}

void painel(){
	printf("============Arvore TRIE============" "\n");
	printf("1. Inserir Palavra(s)\n");
	printf("2. Buscar Palavra\n");
	printf("3. Remover Palavra\n");
	printf("4. Listar Todas as Palavras\n");
	printf("5. Sair\n");
	printf("====================================" "\n");
}

int main(){
	No *raiz = criarNo(); 
	if(raiz == NULL){
		printf(VERMELHO "Nao foi possivel alocar memoria para a raiz!\n" RESET);
		exit(1);
	}

	int op = -1;
	while(op != 5){
		painel();
		op = lerInteiro("Digite sua opcao: ");

		switch(op){
		case 1:{
			int qtd = lerInteiro("Quantas palavras deseja inserir: ");
			for(int i = 0; i < qtd; i++){
				char pergunta[64];
				sprintf(pergunta, "Palavra %d: ", i + 1);
				printf("%s", pergunta);
				char palavra[64];
				scanf("%63s", palavra);
				paraMinusculo(palavra);

                if(procurar(raiz, palavra)){
                    printf(VERMELHO "Palavra \"%s\" Ja EXISTE na Arvore\n" RESET, palavra);
                    break;
                }

				inserir(&raiz, palavra);
				printf(VERDE "Palavra \"%s\" inserida com sucesso!\n" RESET, palavra);
			}
			printf("\n");
			break;
		}
		case 2:{
			printf("Digite a palavra para buscar: ");
			char palavra[64];
			scanf("%63s", palavra);
			paraMinusculo(palavra);

			if(procurar(raiz, palavra)){
				printf(VERDE "A palavra \"%s\" EXISTE na arvore!\n" RESET, palavra);
			}else{
				printf(VERMELHO "A palavra \"%s\" NAO existe na arvore!\n" RESET, palavra);
			}
			printf("\n");
			break;
		}
		case 3:{
			printf("Digite a palavra para remover: ");
			char palavra[64];
			scanf("%63s", palavra);
			paraMinusculo(palavra);

			if(procurar(raiz, palavra)){
				excluir(&raiz, palavra);
				printf(VERDE "Palavra \"%s\" removida com sucesso!\n" RESET, palavra);
			}else{
				printf(VERMELHO "A palavra \"%s\" nao existe na arvore para remover!\n" RESET, palavra);
			}
			printf("\n");
			break;
		}
		case 4:{
			printf(CIANO "=== Palavras na Arvore TRIE ===\n" RESET);
			mostrarTodas(raiz);
			printf(CIANO "===============================\n" RESET);
			printf("\n");
			break;
		}
		case 5:
			printf(AMARELO "Saindo...\n" RESET);
			break;
		default:
			printf(VERMELHO "Digite um numero de 1 a 5\n" RESET);
			printf("\n");
			break;
		}
	}

	liberarArvore(raiz);
	return 0;
}
