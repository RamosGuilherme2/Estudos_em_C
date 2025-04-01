#include <stdio.h>

int lerInteiro(const char *mensagem) {
    int num;
    char entrada[50];
    int valido;
//validações no numero
    do {
        printf("%s", mensagem);
        scanf("%s", entrada);

        valido = sscanf(entrada, "%d", &num);
        if (!valido || num <= 0) {
            printf("Erro: O que foi digitado nao e um numero inteiro positivo. Apenas numeros inteiros positivos sao permitidos.\n");
            valido = 0; 
        }
    } while (!valido);

    return num;
}

int main() {
    int N;

    N = lerInteiro("Digite um numero inteiro positivo: ");

    printf("Numeros pares entre 1 e %d:\n", N);
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}