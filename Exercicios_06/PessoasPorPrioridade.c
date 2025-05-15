#include <stdio.h>

#define MAX 10

int main() {
    int idades[MAX];
    int total = 0;
    char c;

    printf("Digite a quantidade de pessoas (max %d): ", MAX);
    while (scanf("%d", &total) != 1 || total < 1 || total > MAX) {
        printf("Entrada inválida. Digite um número entre 1 e %d: ", MAX);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF); // limpa buffer

    for (int i = 0; i < total; i++) {
        printf("Digite a idade da pessoa %d: ", i + 1);
        while (scanf("%d", &idades[i]) != 1 || idades[i] < 0) {
            printf("Idade inválida. Digite uma idade válida (>=0): ");
            while ((c = getchar()) != '\n' && c != EOF);
        }
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\nAtendimento das pessoas:\n");

    for (int i = 0; i < total; i++) {
        if (idades[i] >= 60) {
            printf("Atendendo pessoa com idade %d (preferencial)\n", idades[i]);
        }
    }

    for (int i = 0; i < total; i++) {
        if (idades[i] < 60) {
            printf("Atendendo pessoa com idade %d\n", idades[i]);
        }
    }

    return 0;
}
