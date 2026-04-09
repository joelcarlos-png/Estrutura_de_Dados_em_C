
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vet;
    int fim;
    int inicio;
    int tam;
}Fila;

Fila *criarFila(int tamanho){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = malloc(tamanho * sizeof(int));
    f->fim = -1;
    f->inicio = 0;
    f->tam = tamanho;

    return f;
}

void queueIn(Fila *f, int valor){
    if(((f->fim - f->inicio) + 1) >= f->tam){printf("!!Fila Cheia!!"); return 0;}
    f->fim++;
    f->vet[f->fim] = valor;
}

int queueOut(Fila *f){
    if(f->fim < f->inicio){printf("!!Fila Vazia!!"); return 0;}
    return f->vet[f->inicio++];
}

int isEmpty(Fila *f){
    if(f->fim < f->inicio){
        printf("!!Fila Vazia!!");
        return 1;
    }
    return 0;
}

int isFull(Fila *f){
    if(((f->fim - f->inicio) + 1) >= f->tam){
        printf("!!Fila Cheia!!");
        return 1;
    }
    return 0;
}

void mostrarFila(Fila *f){
    printf("<-- ");
    if (isEmpty(f) == 1){
    }
    for(int i = f->inicio; i <= f->fim; i++){
        printf("%d ", f->vet[i]);
    }
    printf("<--\n\n");
}

void painel(){
    printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Sair\n====================\n\nDigite sua opcao: ");
}


int main(){
    int tam, op, val;
    printf("Digite o tamanho para a fila: ");
    scanf("%d", &tam);
    Fila *f = criarFila(tam);


    do{
    painel();
    scanf("%d", &op);
    switch(op){
    case 1:
        printf("Digite a quantidade de valores para adicionar: ");
        scanf("%d", &op);

        for(int i = 0; i < op; i++){
            printf("Valor %d: ", i + 1);
            scanf("%d", &val);
            printf("\n");
            queueIn(f, val);
        }
        break;
    case 2:
        printf("Digite a quantidade de valores para remover: ");
        scanf("%d", &op);

        for(int i = 0; i < op; i++){
            val = queueOut(f);
            printf("\nValor %d removido\n", val);
        }
        break;
    case 3:
        printf("Fila: \n");
        mostrarFila(f);
        break;
    case 4:
        exit(0);
    }
    }while(1);

    return 0;
}
