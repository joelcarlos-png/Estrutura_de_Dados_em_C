#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listachar.h"
#include "controle.h"

int main(){
    Lista *l = criarLista(10);
    inserirFinal(l, 'j');
    inserirFinal(l, 'e');
    inserirFinal(l, 'l');
    inserirFinal(l, 'c');
    mostrarLista(l);
    inserirIndice(l, 'o', 1);
    mostrarLista(l);
    consultar(l, 1);
    remover(l, 1);
    mostrarLista(l);
}
