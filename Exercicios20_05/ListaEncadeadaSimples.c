#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void imprimir(No *inicio) {
    No *atual = inicio;
    while(atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}
 int main() {
    No *inicio = malloc(sizeof(No));
    inicio->valor = 1;
    inicio->prox = malloc(sizeof(No));
    inicio->prox->valor = 2;
    inicio->prox->prox = NULL;

    imprimir(inicio);
    return 0;
 }