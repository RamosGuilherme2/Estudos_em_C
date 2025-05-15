#include <stdio.h>

int main() {
    int inteiros[10];
    int soma = 0;

        printf("Insira 10 númeors inteiros (um número por vez. Somente inteiros serão válidos)\n");

    for (int i = 0; i < 10; i++) {
        while (1) {
        printf("Digite um número %d: ", i + 1);
        if (scanf("%d", &inteiros[i]) != 1) {
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
            while(getchar() != '\n');
        }
        else {
            soma += inteiros[i];
            break;
            }
        }
    }
        printf("A soma desses números é: %d\n", soma);
}


