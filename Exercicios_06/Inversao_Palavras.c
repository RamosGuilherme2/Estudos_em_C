#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char palavra[MAX];
    char pilha[MAX];
    int topo = -1;

    printf("Digite uma palavra para inverter:\n");

    while (1) {
        if (fgets(palavra, sizeof(palavra), stdin) != NULL) {
            size_t len = strlen(palavra);
            if (len > 0 && palavra[len - 1] == '\n') {
                palavra[len - 1] = '\0';  // Remove newline
            }
            if (strlen(palavra) == 0) {
                printf("Entrada vazia. Digite uma palavra válida:\n");
                continue;
            }
            break;
        } else {
            printf("Erro na leitura. Tente novamente:\n");
        }
    }

    // Empilha cada caractere
    for (size_t i = 0; i < strlen(palavra); i++) {
        pilha[++topo] = palavra[i];
    }

    printf("Palavra invertida: ");
    while (topo != -1) {
        printf("%c", pilha[topo--]);
    }
    printf("\n");

    return 0;
}
