#include <stdio.h>
#include <string.h>

#define MAX_EXPR 200

// Função para verificar balanceamento dos parênteses
int verifica_balanceamento(const char *expr) {
    char pilha[MAX_EXPR];
    int topo = -1;
    int i;

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            if (topo == MAX_EXPR - 1) {
                // Pilha cheia, impossível continuar
                return 0;
            }
            pilha[++topo] = '(';  // Empilha
        }
        else if (expr[i] == ')') {
            if (topo == -1) {
                // Fecha parêntese sem abrir
                return 0;
            }
            topo--; // Desempilha
        }
    }

    // Se a pilha estiver vazia, está balanceado
    return topo == -1;
}

int main() {
    char expressao[MAX_EXPR];

    printf("Digite uma expressão matemática para verificar os parênteses:\n");

    while (1) {
        if (fgets(expressao, sizeof(expressao), stdin) != NULL) {
            // Remove \n do final
            size_t len = strlen(expressao);
            if (len > 0 && expressao[len - 1] == '\n') {
                expressao[len - 1] = '\0';
            }

            if (strlen(expressao) == 0) {
                printf("Entrada vazia. Por favor, digite uma expressão válida:\n");
                continue;
            }

            int resultado = verifica_balanceamento(expressao);
            if (resultado) {
                printf("A expressão está correta.\n");
            } else {
                printf("A expressão está incorreta.\n");
            }
            break;
        } else {
            printf("Erro na leitura da expressão, tente novamente.\n");
        }
    }

    return 0;
}
