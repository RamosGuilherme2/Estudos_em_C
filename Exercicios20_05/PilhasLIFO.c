#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int valor;
    struct Pilha *prox;
} Pilha;

Pilha* push(Pilha *topo, int valor) {
    Pilha *novo = malloc(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = topo;
    return novo;
}

Pilha* pop(Pilha *topo) {
    if(topo == NULL) return NULL;
    Pilha *temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

void imprimir(Pilha *topo) {
    while(topo != NULL) {
        printf("%d\n", topo->valor);
        topo = topo->prox;
    }
}

int main() {
    Pilha *pilha = NULL;
    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);
    imprimir(pilha);
    pilha = pop(pilha);
    imprimir(pilha);
    return 0;
}