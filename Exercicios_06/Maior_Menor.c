#include <stdio.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int numeros[6];
    int i, maior, menor, pos_maior, pos_menor;
    int entrada_valida;

    printf("Digite 6 números inteiros:\n");

    for (i = 0; i < 6; i++) {
        while (1) {
            printf("Número %d: ", i + 1);
            entrada_valida = scanf("%d", &numeros[i]);
            if (entrada_valida == 1) {
                limpar_buffer();
                break;
            } else {
                printf("Entrada inválida. Digite um número inteiro válido.\n");
                limpar_buffer();
            }
        }
    }

    maior = menor = numeros[0];
    pos_maior = pos_menor = 0;

    for (i = 1; i < 6; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            pos_maior = i;
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
            pos_menor = i;
        }
    }

    printf("Maior número: %d, posição %d\n", maior, pos_maior);
    printf("Menor número: %d, posição %d\n", menor, pos_menor);

    return 0;
}
