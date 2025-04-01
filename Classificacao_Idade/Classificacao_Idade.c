#include <stdio.h>   // Biblioteca padrão para entrada e saída. Permite usar funções como printf(), scanf(), getchar(), etc.
#include <stdlib.h>  // Biblioteca padrão para gerenciamento de memória, conversões e outras utilidades. Inclui funções como malloc(), free(), atoi(), rand(), etc.
#include <string.h>  // Biblioteca para manipulação de strings. Permite usar funções como strlen(), strcpy(), strcmp(), strcat(), etc.
#include <ctype.h>   // Biblioteca para manipulação de caracteres. Inclui funções como isalpha(), isdigit(), toupper(), tolower(), etc.

int main() {
    char entrada[20];
    int idade;
    char continuar[10];
    int valida;

    do {
        do {
            printf("\nPor favor, informe a idade da pessoa: ");
            scanf("%19s", entrada);
            valida = 1;

            for (int i = 0; i < strlen(entrada); i++) {
                if (!isdigit(entrada[i])) {
                    valida = 0;
                    break;
                }
            }

            if (!valida) {
                printf("Entrada invalida! Por favor, insira apenas numeros.\n");
            }
        } 
        while (!valida);

        idade = atoi(entrada);
        if (idade < 18) {
            printf("Categoria: Menor de idade\n");
        } 
        else if (idade >= 18 && idade <= 64) {
            printf("Categoria: Adulto\n");
        } 
        else {
            printf("Categoria: Idoso\n");
        }

        do {
            printf("\nDeseja informar outra idade? ('S' para continuar / 'N' para sair): ");
            scanf("%9s", continuar); // %9s Limita a entrada a 9 caracteres e não estoura o buffer ;)
            while (getchar() != '\n'); // Limpa o buffer após o scanf, garantindo que os caracteres excedentes não sejam lidos como parte da próxima tentativa de entrada :D
            for (int i = 0; i < strlen(continuar); i++) {
                continuar[i] = tolower(continuar[i]);
            }

            if (strcmp(continuar, "n") == 0) {
                break;
            } 
            else if (strcmp(continuar, "s") == 0) {
                break;
            } 
            else {
                printf("Entrada invalida! Por favor, digite apenas 'S' ou 'N'.\n");
            }
        } 
        while (1);

    }
    while (strcmp(continuar, "n") != 0);
    printf("\nPrograma encerrado. Obrigado por usar!\n");
    return 0; //deu tudo certo!!
}