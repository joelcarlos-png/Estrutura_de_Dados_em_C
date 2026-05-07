#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    char valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Fila;

Fila *criarFila(){
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}

void painel(){
    printf("============Fila_Encadeada===========\n");
    printf("1.  Inserir                          \n");
    printf("2.  Remover                          \n");
    printf("3.  Mostrar Quantidade               \n");
    printf("4.  Clear Fila                       \n");
    printf("5.  Mostrar elementos                \n");
    printf("6.  Mostrar Quanidade e remover      \n");
    printf("7.  Remover e mostrar inversa        \n");
    printf("8.  Inverter Valores sem remover     \n");
    printf("9.  Ler palavra e inserir caracteres \n");
    printf("10. Sair do Programa                 \n");
    printf("=====================================\n");
}

bool inserir(Fila *f, char valor){
    No *novoNo = malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if(isEmpty(f)){
        f->inicio = novoNo;
    }else{
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;

    f->qtd++;
    return true;
}

bool remover(Fila *f, char *valorRemovido){
    if(isEmpty(f)){printf("!!Fila Vazia!!\n"); return false;}
    No *noRemovido = f->inicio;
    *valorRemovido = noRemovido->valor;
    f->inicio = noRemovido->proximo;

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(noRemovido);
    f->qtd--;
    return true;
}

int isEmpty(Fila *f){
    if(f->fim == NULL && f->inicio == NULL){
        return 0;
    }
    return 1;
}

bool size(Fila *f, int *quantidadeDeElementos){
    Fila *aux = clonarFila(f);

    *quantidadeDeElementos = 0;

    while (!isEmpty(aux)){
        char valorRemovido;
        remover(aux, &valorRemovido);

        (*quantidadeDeElementos)++;
    }
    liberarFila(aux);
    return true;
}

Fila *clonarFila(Fila *orig){
    if (orig == NULL) return NULL;

    Fila *aux = criarFila();
    if (aux == NULL) return NULL;

    No *atual = orig->inicio;
    while (atual != NULL){
        inserir(aux, atual->valor);
        atual = atual->proximo;
    }

    return aux;
}

bool clear(Fila *f){
    if(isEmpty(f)){return false;}

    while (!isEmpty(f)){
        char valorRemovido;
        remover(f, &valorRemovido);
    }
    return true;
}

bool mostrarFila(Fila *f){
    if(isEmpty(f)){printf("!!Fila Vazia!!\n"); return false;}
    Fila *aux = clonarFila(f);

    printf("<-- ");
    while (!isEmpty(aux)){
        char valorRemovido;
        remover(aux, &valorRemovido);
        printf("%c ", valorRemovido);
    }
    printf("<--\n");
    liberarFila(aux);
    return true;
}

bool inverter(Fila *f){
    if(isEmpty(f)){printf("!!Fila Vazia!!"); return false;}
    PilhaChar aux;

    int quantidadeFila;
    size(f, &quantidadeFila);
    criarPilhaChar(&aux, quantidadeFila);

    while (!isEmpty(f)){
        char valorRemovido;
        remover(f, &valorRemovido);

        pushchar(&aux, valorRemovido);
    }

    while (!isEmptychar(&aux)){
        char valorRemovidPilha = popchar(&aux);
        inserir(f, valorRemovidPilha);
    }
    return true;
}

int lerInteiro(const char *pergunta){
    int x;
    printf("%s", pergunta);
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO INTEIRO!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

char lerChar(const char *pergunta){
    char x;
    printf("%s", pergunta);
    while (scanf(" %c", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO CARACTERE(CHAR)!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

void liberarFila(Fila *f){
    if (f == NULL){
        return;
    }

    No *atual = f->inicio;
    while (atual != NULL){
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    free(f);
}

int main(){
    Fila *f = criarFila();

    int op = 1, opcoes;
    char val;
    while (op != 10){
        painel();
        op = lerInteiro("Digite sua opcao: ");

        switch (op){
        case 1:
            opcoes = lerInteiro("Digite a quantidade de valores para adicionar: ");
            for(int i = 0; i < opcoes; i++){
                char pergunta[64];
                sprintf(pergunta, "Valor %d: ", i + 1);
                val = lerChar(pergunta);
                inserir(f, val);
            }
            printf("%d valores adicionados!\n", opcoes);
            break;
        case 2:
            op = lerInteiro("Digite a quantidade de valores para remover: ");
            for(int i = 0; i < op; i++){
                remover(f, &val);
                printf("Valor %c removido\n", val);
            }
            break;
        case 3:
            size(f, &op);
            printf("Quantidade de valores na fila: %d\n", op);
            break;
        case 4:
            op = lerInteiro("Tem certeza que deseja remover todos os valores? (1:sim, 2:nao): ");
            if(op == 1){
                if(clear(f)){
                    printf("Fila limpa com sucesso!!\n");
                }
            }
            break;
        case 5:
            mostrarFila(f);
            break;
        case 6:
            size(f, &op);
            printf("Quantidade de valores na fila: %d\n", op);
            if(clear(f)){
                    printf("Quantidade de elementos da fila a mostra e fila limpa com sucesso!!\n");
            }
            break;
        case 7:
            inverter(f);
            mostrarFila(f);
            if(clear(f)){
                printf("Fila invertida e clear com sucesso\n");
            }
            break;
        case 8:
            if (inverter(f)){
                printf("Fila invertida com sucesso!!\n");
            }
            break;
        case 9:
            printf("Digite a palavra para inserir na fila: ");
            char valorChar;
            while ((valorChar = getchar()) != '\n' && valorChar != EOF) { }
            while(true){
                scanf("%c", &valorChar);
                if(valorChar == '\n'){break;}
                inserir(f, valorChar);
            }
            printf("Palavra adicionada com sucesso! \n");
            break;
        case 10:
            printf("Saindo...\n");
            break;
        default:
            printf("!!Digite um numero de 1 a 10!!\n");
            break;
        }
    }
}
