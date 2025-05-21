#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Fila;

void enfileirar(Fila *f, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    if(f->inicio == NULL)
        f->inicio = novo;
}

void desenfileirar(Fila *f) {
    if(f->inicio != NULL) {
        No *temp = f->inicio;
        f->inicio = f->inicio->prox;
        if(f->inicio == NULL) f->fim = NULL;
        free(temp);
    }
}

void imprimir(Fila *f) {
    No *atual = f->inicio;
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila f = {NULL, NULL};
    enfileirar(&f, 5);
    enfileirar(&f, 10);
    enfileirar(&f, 15);
    imprimir(&f);
    desenfileirar(&f);
    imprimir(&f);
    return 0;
}
