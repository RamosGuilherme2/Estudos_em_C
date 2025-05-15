#include <stdio.h>

#define MAX 5

int main() {
    int fila[MAX];
    int inicio = 0, fim = 0, tamanho = 0;
    int senha = 1;
    char c;

    printf("Gerando %d senhas para atendimento.\n", MAX);

    while (tamanho < MAX) {
        fila[fim] = senha++;
        fim = (fim + 1) % MAX;
        tamanho++;
    }

    printf("Atendendo senhas:\n");
    while (tamanho > 0) {
        printf("Atendendo senha %d\n", fila[inicio]);
        inicio = (inicio + 1) % MAX;
        tamanho--;

        if (tamanho > 0) {
            printf("Pressione Enter para atender próxima senha...");
            while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer
            getchar();
        }
    }

    printf("Todas as senhas foram atendidas.\n");

    return 0;
}
