#include <stdio.h>
#include <string.h>

#define MAX_PAGINAS 5
#define MAX_TAM 100

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char pilha[MAX_PAGINAS][MAX_TAM];
    int topo = -1;
    char pagina[MAX_TAM];
    int i, entrada_valida;

    printf("Digite 5 páginas visitadas (URLs ou nomes):\n");

    for (i = 0; i < MAX_PAGINAS; i++) {
        while (1) {
            printf("Página %d: ", i + 1);
            if (fgets(pagina, sizeof(pagina), stdin) != NULL) {
                // Remover o '\n' do final, se existir
                size_t len = strlen(pagina);
                if (len > 0 && pagina[len - 1] == '\n') {
                    pagina[len - 1] = '\0';
                }
                if (strlen(pagina) == 0) {
                    printf("Entrada vazia. Por favor, digite uma página válida.\n");
                } else {
                    // Empilhar
                    topo++;
                    strcpy(pilha[topo], pagina);
                    break;
                }
            } else {
                printf("Erro na entrada. Tente novamente.\n");
                limpar_buffer();
            }
        }
    }

    printf("\nPáginas visitadas armazenadas na pilha:\n");
    for (i = topo; i >= 0; i--) {
        printf("%d: %s\n", i + 1, pilha[i]);
    }

    printf("\nVoltando às páginas anteriores (desempilhando):\n");
    while (topo >= 0) {
        printf("Página atual: %s\n", pilha[topo]);
        topo--;
    }

    printf("Você voltou à página inicial.\n");

    return 0;
}
