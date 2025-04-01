#include <stdio.h>
#include <ctype.h>

float lerNumero(const char *mensagem) {
    float num;
    char entrada[50];
    int valido;

    //adicionei uma validação para saber se o que foi digitado é valido ou não e fazer sentido para o programa descrito no enunciado
    do {
        printf("%s", mensagem);
        scanf("%s", entrada);

        valido = sscanf(entrada, "%f", &num);
        if (!valido) {
            printf("Erro: O que foi digitado nao e um numero. Apenas numeros sao permitidos.\n");
        }
    } while (!valido);

    return num;
}

char lerOperacao() {
    char operacao;
    int valido;

    do {
        printf("Escolha a operacao (+, -, *, /): ");
        scanf(" %c", &operacao);
        valido = (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/');
        if (!valido) {
            printf("Erro: Operacao invalida. Digite apenas +, -, * ou /.\n");
        }
    } while (!valido);

    return operacao;
}
int main() {
    float num1, num2, resultado;
    char operacao;

    num1 = lerNumero("Digite o primeiro numero: ");
    num2 = lerNumero("Digite o segundo numero: ");
    operacao = lerOperacao();

    if (operacao == '+') {
        resultado = num1 + num2;
        printf("Resultado: %.2f\n", resultado);
    } else if (operacao == '-') {
        resultado = num1 - num2;
        printf("Resultado: %.2f\n", resultado);
    } else if (operacao == '*') {
        resultado = num1 * num2;
        printf("Resultado: %.2f\n", resultado);
    } else if (operacao == '/') {
        if (num2 != 0) {
            resultado = num1 / num2;
            printf("Resultado: %.2f\n", resultado);
        } else {
            printf("Erro: Divisao por zero nao permitida!\n");
        }
    }

    return 0;
}