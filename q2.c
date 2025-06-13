#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
    double preco;
} Registro;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Registro lojas[15];

    printf("Digite os dados das 15 lojas (Nome, Telefone, Preço):\n");
    for(int i = 0; i < 15; i++) {
        printf("\nLoja %d:\n", i + 1);

        printf("Nome: ");
        fgets(lojas[i].nome, 50, stdin);
        lojas[i].nome[strcspn(lojas[i].nome, "\n")] = '\0';

        printf("Telefone: ");
        fgets(lojas[i].telefone, 20, stdin);
        lojas[i].telefone[strcspn(lojas[i].telefone, "\n")] = '\0';

        printf("Preço: ");
        while (scanf("%lf", &lojas[i].preco) != 1) {
            printf("Preço inválido. Digite novamente: ");
            limparBuffer();
        }
        limparBuffer();
    }

    double soma = 0;
    for(int i = 0; i < 15; i++) {
        soma += lojas[i].preco;
    }
    double media = soma / 15;

    printf("\nA média dos preços cadastrados é: %.2f\n", media);
    printf("Lojas com preços abaixo da média:\n");

    for(int i = 0; i < 15; i++) {
        if(lojas[i].preco < media) {
            printf("Nome: %s\n", lojas[i].nome);
            printf("Telefone: %s\n\n", lojas[i].telefone);
        }
    }

    return 0;
}
