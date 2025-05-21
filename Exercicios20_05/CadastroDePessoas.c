#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa lista[3];

    for(int i = 0; i < 3; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", lista[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &lista[i].idade);
    }
    
    printf("\nLista de pessoas:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s tem %d anos\n", lista[i].nome, lista[i].idade);
    }

    return 0;
}