#include <stdio.h>

int lerInteiro(const char *mensagem) {
    int num;
    char entrada[50];
    int valido;

    //validadores aqui para fazer sentido no programa
    do {
        printf("%s", mensagem);
        scanf("%s", entrada);

        valido = sscanf(entrada, "%d", &num);
        if (!valido) {
            printf("Erro: O que foi digitado nao e um numero. Apenas numeros inteiros sao permitidos.\n");
        }
    } while (!valido);

    return num;
}

int main() {
    int numero;

    numero = lerInteiro("Digite um numero inteiro: ");

    printf("Tabuada de %d:\n", numero);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}