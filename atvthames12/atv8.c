#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *vet;
    int fim;
    int inicio;
    int tam;
    int qtd;
}Fila;

typedef struct {
    int *vet;
    int top;
    int tam;
} Pilha;


void criarPilha(Pilha *p, int tamanho){
    p->vet = malloc(tamanho * sizeof(int));
    p->top = -1;
    p->tam = tamanho;
};

void push(Pilha *p, int valor){
    if(p->top < p->tam - 1){
        p->top++;
        p->vet[p->top] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
};


int pop(Pilha *p){
    if(p->top >= 0){
        int valor = p->vet[p->top];
        p->top--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
};

int isEmptypilha(Pilha *p){
    if(p->top == -1){
        return 1;
    }
    return 0;
};

int isFullpilha(Pilha *p){
    if(p->top == p->tam - 1){
        return 1;
    }
    return 0;
};

void mostrarPilha(Pilha *p){
    if(p->top == -1){
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha:\n");
        printf("   â†“â†“\n");
        for(int i = p->top; i >= 0; i--){
            printf("   %d\n", p->vet[i]);
        }
        printf("--base--\n");
    }
};

void liberarPilha(Pilha *p){
    free(p->vet);
    p->vet = NULL;
    p->top = -1;
    p->tam = 0;
}

Fila *criarFila(int tamanho){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = malloc(tamanho * sizeof(int));
    f->fim = -1;
    f->inicio = 0;
    f->tam = tamanho;
    f->qtd = 0;
    return f;
}

int inserir(Fila *f, int valor){
    if(isFull(f) == 1){return 0;}
    if(f->fim == f->tam - 1){
        f->fim = -1;
    }
    f->fim++;
    f->vet[f->fim] = valor;
    f->qtd++;
    return 1;
}

int remover(Fila *f){
    if(isEmpty(f) == 1){return 0;}
    int valorRemovido = f->vet[f->inicio];

    if(f->inicio == f->tam - 1){
        f->inicio = -1;
    }

    f->inicio++;

    f->qtd--;
    if(f->qtd <= 0){
        f->inicio = 0;
        f->fim = -1;
    }

    return valorRemovido;
}

int isEmpty(Fila *f){
    if(f->qtd <= 0){
        return 1;
    }
    return 0;
}

int isFull(Fila *f){
    if(f->qtd >= f->tam){
        return 1;
    }
    return 0;
}

void mostrarFila(Fila *f){
    Fila aux = *f;
    printf("Quantidade de elementos da fila: %d\n", aux.qtd);
    printf("<-- ");
    if (isEmpty(&aux) == 1){printf("!!Fila vazia!!");
    } else {
        int i = 0;
        int j = aux.qtd;
        while(i < j) {
            int valor = remover(&aux);

            printf("%d ", valor);
            i++;
        }
    }

    printf("<--\n\n");
}

void painel(){
    printf("====OPCOES-FILAS====\n1.Enfileirar\n2.Desenfileirar\n3.Mostrar Fila\n4.Exercicios de 5 a 8\n5.Sair\n====================\n\n");
}

void liberar(Fila *f){
    if (f == NULL) {
        return;
    }

    free(f->vet);
    free(f);
}

int lerInteiro(const char *pergunta){
    int x;
    printf("%s", pergunta);
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO INTEIROS!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

int inverter(Fila *f){
    Pilha aux;
    criarPilha(&aux, f->qtd);

    if(isEmpty(f)){
        printf("Fila vazia!");
        return 0;
    }

    int quantidade = f->qtd;

    for(int i = 0; i < quantidade; i++){
        int valor = remover(f);
        push(&aux, valor);
    }

    for(int i = 0; i < quantidade; i++){
        int valorpilha = pop(&aux);
        inserir(f, valorpilha);
    }
    liberarPilha(&aux);
    return 1;
}

int verificarMaior(Fila *f1, Fila *f2){
    Fila aux1 = *f1;
    Fila aux2 = *f2;

    int qnt1 = 0;
    int qnt2 = 0;

    while(!isEmpty(&aux1)){
        remover(&aux1);
        qnt1++;
    }
    while(!isEmpty(&aux2)){
        remover(&aux2);
        qnt2++;
    }
    printf("\n");

    if(qnt1 > qnt2){return 11;}
    else if(qnt1 < qnt2){return 22;}
    else{return 33;}
}

void organizarFilasCrescente(Fila *f1, Fila *f2, Fila *f3){
    int valor = verificarMaior(f1, f2);
    int qnt1 = f1->qtd;
    int qnt2 = f2->qtd;
    if(valor == 11){
        for(int i = 0; i < qnt1 ; i++){
            int valor1 = remover(f1);
            int valor2 = remover(f2);

            if(valor1 < valor2){
                inserir(f3, valor1);
                inserir(f3, valor2);
            }else{
                inserir(f3, valor2);
                inserir(f3, valor1);
            }

            if(qnt1 <= 0){
                for(int i = 0; i < qnt2; i++){
                    int valorsla = remover(f2);
                    inserir(f3, valorsla);
                }
            }
        }
    }else{
        for(int i = 0; i < qnt2 ; i++){
            int valor1 = remover(f1);
            int valor2 = remover(f2);

            if(valor1 < valor2){
                inserir(f3, valor1);
                inserir(f3, valor2);
            }else{
                inserir(f3, valor2);
                inserir(f3, valor1);
            }

            if(qnt2 <= 0){
                for(int i = 0; i < qnt1; i++){
                    int valorsla = remover(f2);
                    inserir(f3, valorsla);
                }
            }
        }
    }
}

void organizarFilasDecrescente(Fila *f1, Fila *f2, Fila *f3){
    int valor = verificarMaior(f1, f2);
    Pilha auxmaior, auxmenor;
    criarPilha(&auxmaior, f1->qtd);
    criarPilha(&auxmenor, f2->qtd);
    int qnt1 = f1->qtd;
    int qnt2 = f2->qtd;
    if(valor == 11){
        for(int i = 0; i < qnt1 ; i++){
            int valorRemovidoFila = remover(f1);
            push(&auxmaior, valorRemovidoFila);
        }
        for(int i = 0; i < qnt2 ; i++){
            int valorRemovidoFila = remover(f2);
            push(&auxmenor, valorRemovidoFila);
        }
    }else{
        for(int i = 0; i < qnt2 ; i++){
            int valorRemovidoFila = remover(f2);
            push(&auxmaior, valorRemovidoFila);
        }
        for(int i = 0; i < qnt1 ; i++){
            int valorRemovidoFila = remover(f1);
            push(&auxmenor, valorRemovidoFila);
        }

    }

    for(int i = 0; i < qnt1 ; i++){
        int valor1 = pop(&auxmaior);
        int valor2 = pop(&auxmenor);

        if(valor1 > valor2){
            inserir(f3, valor1);
            inserir(f3, valor2);
        }else{
            inserir(f3, valor2);
            inserir(f3, valor1);
        }

        if(auxmenor.top <= -1){
            while(!isEmptypilha(&auxmaior)){
                int valorsla = pop(&auxmaior);
                inserir(f3, valorsla);
            }
        }
    }
}

bool queueClear(Fila *f){
    if(isEmpty(f)){return false;}
    int a = f->qtd;
    for(int i = 0; i < a; i++){
        remover(f);
    }
    return true;
}

int mostrarDivisiveis(Fila *f, Fila *divisiveisPor3){
    Fila aux = *f;
    int qnt = f->qtd;
    if(divisiveisPor3->qtd > 0){queueClear(divisiveisPor3);}
    for(int i = 0; i < qnt; i++){
        int val = remover(&aux);
        if(val % 3 == 0){
            inserir(divisiveisPor3, val);
        }
    }
}

int mostrarAritimetica(Fila *f){
    //maior, o menor e a média
    Fila aux = *f;
    int valMaior = f->vet[f->inicio];
    int valMenor = f->vet[f->inicio];
    double somaTotal = 0;
    int qnt = f->qtd;
    for(int i = 0; i < qnt; i++){
        int valor = remover(&aux);
        if(valor > valMaior){
            valMaior = valor;
        }
        if(valor < valMenor){
            valMenor = valor;
        }
        somaTotal += valor;
    }

    double media = somaTotal / f->qtd;

    printf("Valor maior: %d\nValor menor: %d\nMedia dos valores: %.2f\n", valMaior, valMenor, media);
}

int main(){
    int tam, op, val;
    tam = lerInteiro("Digite o tamanho para a fila: ");
    Fila *f = criarFila(tam);
    Fila *f2 = criarFila(tam);
    Fila *f3 = criarFila(tam);

    do{
    painel();
    op = lerInteiro("Digite sua opcao: ");
    switch(op){
    case 1:
        op = lerInteiro("Qual fila vc quer adicionar(1 ou 2): ");
        if(op == 1){
            if(isFull(f) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para adicionar: ");
        if(op > f->tam - f->qtd){
            printf("Nao e possivel adicionar\nA fila so tem %d espaços vagos\n", f->tam - f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            char pergunta[64];
            sprintf(pergunta, "Valor %d: ", i + 1);
            val = lerInteiro(pergunta);
            inserir(f, val);
        }
        break;
        }else{
            if(isFull(f2) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para adicionar: ");
        if(op > f2->tam - f2->qtd){
            printf("Nao e possivel adicionar\nA fila so tem %d espaços vagos\n", f2->tam - f2->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            char pergunta[64];
            sprintf(pergunta, "Valor %d: ", i + 1);
            val = lerInteiro(pergunta);
            inserir(f2, val);
        }
        }

    case 2:
        op = lerInteiro("Qual fila vc quer remover(1 ou 2 ou 3): ");
        if(op == 1){
            if(isEmpty(f) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f);
            printf("\nValor %d removido\n", val);
        }
        break;
        }else if (op == 2){
            if(isEmpty(f2) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f2->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f2->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f2);
            printf("\nValor %d removido\n", val);
        }
        }else if(op == 3){
        if(isEmpty(f3) == 1){printf("\n"); break;}
        op = lerInteiro("Digite a quantidade de valores para remover: ");
        if(op > f3->qtd){
            printf("Nao e possivel remover\nA fila so tem %d valores\n", f3->qtd);
            break;
        }

        for(int i = 0; i < op; i++){
            val = remover(f3);
            printf("\nValor %d removido\n", val);
        }
        }else{
            printf("Digite de 1 a 3!!\n");
        }
        break;

    case 3:
        op = lerInteiro("Qual fila voce quer ver(1 ou 2 ou 3): ");
        printf("Fila: \n");
        if (op == 1){
            mostrarFila(f);
        }else if(op == 2){
            mostrarFila(f2);
        }else{
            mostrarFila(f3);
        }
        break;
    case 4:
        while(op != 3){
            printf("====OPCOES-EXERCICIOS-5a8====\n1.Adicionar valores padrao(f1 e f2)\n2.Organizar Filas\n3.Sair\n=============================\n\n");
            op = lerInteiro("Digite sua opcao: ");
            switch (op){
            case 1:
                queueClear(f);
                queueClear(f2);
                for(int i = 1; i <= f->tam; i++){
                    if(i % 2 == 0){
                        inserir(f, i);
                    }else{
                        inserir(f2, i);
                    }
                }
                mostrarFila(f);
                printf("Fila 2: \n");
                mostrarFila(f2);
                printf("\nValores padrao adicionados!!\n");
                break;
            case 2:
                if(isEmpty(f) == 1){printf("!!Fila 1 vazia!!"); break;}
                if(isEmpty(f2) == 1){printf("!!Fila 2 vazia!!"); break;}
                printf("\nValores de f1 e f2 estao organizados em f3!!\nFila 3:\n");
                organizarFilasDecrescente(f, f2, f3);
                mostrarFila(f3);
                break;
            case 3:
                printf("Voltando...\n");
                break;
            default:
                printf("Digite de 1 ou 2!!\n");
                break;
            }
        }
        break;
    case 5:
        liberar(f);
        exit(0);
    default:
        printf("Digite um valor de 1 a 4!!\n");
        break;
    }
    }while(1);

    return 0;
}
