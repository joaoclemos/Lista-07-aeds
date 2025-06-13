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
    int total_pessoas = 4;

    for(int i = 0; i < total_pessoas; i++) {
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';
        scanf("%d %d", &pessoas[i].dia, &pessoas[i].mes);
        getchar();
    }

    for(int m = 1; m <= 12; m++) {
        int tem_aniversariante = 0;
        for(int i = 0; i < total_pessoas; i++) {
            if(pessoas[i].mes == m) {
                tem_aniversariante = 1;
                break;
            }
        }
        if(tem_aniversariante) {
            printf("\nAniversariantes de %s:\n", meses[m-1]);
            for(int i = 0; i < total_pessoas; i++) {
                if(pessoas[i].mes == m) {
                    printf("Nome: %s, Dia: %d\n", pessoas[i].nome, pessoas[i].dia);
                }
            }
        }
    }

    return 0;
}
