//Exatamente como foi descrito no enunciado, mas da pra melhorar bastante se nao seguir o enunciado :(
#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("Media: %.2f\n", media);

    if (media >= 7) {
        printf("Status: Aprovado\n");
    } else if (media >= 5) {
        printf("Status: Recuperacao\n");
    } else {
        printf("Status: Reprovado\n");
    }

    return 0;
}