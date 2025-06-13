#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int dia;
    int mes;
};

int main() {
    struct Pessoa pessoas[40];
    char *meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                       "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    for(int i = 0; i < 40; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;
        printf("Digite o dia do aniversário: ");
        scanf("%d", &pessoas[i].dia);
        printf("Digite o mês do aniversário: ");
        scanf("%d", &pessoas[i].mes);
        while(getchar() != '\n');
    }

    for(int m = 1; m <= 12; m++) {
        printf("Aniversariantes de %s:\n", meses[m - 1]);
        for(int i = 0; i < 40; i++) {
            if(pessoas[i].mes == m) {
                printf("%s: %d\n", pessoas[i].nome, pessoas[i].dia);
            }
        }
    }

    return 0;
}