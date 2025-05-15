#include <stdio.h>

#define MAX 4

int main() {
    char documentos[MAX][50];
    int inicio = 0, fim = 0, tamanho = 0;
    char novoDoc[50];
    char c;

    printf("Digite os nomes de 4 documentos para a fila da impressora:\n");
    while (tamanho < MAX) {
        printf("Documento %d: ", tamanho + 1);
        if (fgets(documentos[fim], 50, stdin) != NULL) {
            // Remove \n do fgets
            int len = 0;
            while (documentos[fim][len] != '\0') {
                if (documentos[fim][len] == '\n') {
                    documentos[fim][len] = '\0';
                    break;
                }
                len++;
            }
            fim = (fim + 1) % MAX;
            tamanho++;
        } else {
            printf("Entrada inválida. Tente novamente.\n");
            while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer
        }
    }

    printf("\nFila circular da impressora iniciada.\n");

    for (int i = 1; i <= 5; i++) { 
        printf("\nIteração %d:\n", i);
        printf("Imprimindo documento: %s\n", documentos[inicio]);
        inicio = (inicio + 1) % MAX;
        tamanho--;

        printf("Digite o nome do novo documento para adicionar na fila: ");
        if (fgets(novoDoc, 50, stdin) != NULL) {
            int len = 0;
            while (novoDoc[len] != '\0') {
                if (novoDoc[len] == '\n') {
                    novoDoc[len] = '\0';
                    break;
                }
                len++;
            }
            documentos[fim][0] = '\0';  // limpa
            for (int j = 0; novoDoc[j] != '\0'; j++) {
                documentos[fim][j] = novoDoc[j];
            }
            documentos[fim][strlen(novoDoc)] = '\0';
            fim = (fim + 1) % MAX;
            tamanho++;
        } else {
            printf("Entrada inválida. Documento não adicionado.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("Estado atual da fila:\n");
        int idx = inicio;
        for (int k = 0; k < tamanho; k++) {
            printf(" - %s\n", documentos[idx]);
            idx = (idx + 1) % MAX;
        }
    }

    printf("\nProcesso finalizado.\n");
    return 0;
}
