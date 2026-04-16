#ifndef PILHACHAR_H
#define PILHACHAR_H

typedef struct {
    char *vet;
    int top;
    int tam;
} PilhaChar;

void criarPilhaChar(PilhaChar *p, int tamanho);
void pushchar(PilhaChar *p, char valor);
char popchar(PilhaChar *p);
int isEmptychar(PilhaChar *p);
int isFullchar(PilhaChar *p);
void mostrarPilhachar(PilhaChar *p);
void liberarPilhachar(PilhaChar *p);
int verifIgualdadechar(PilhaChar *p1, PilhaChar *p2);
void painelchar();

#endif