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
        scanf("%s", pessoas[i].nome);
        scanf("%d", &pessoas[i].dia);
        scanf("%d", &pessoas[i].mes);
        while(getchar() != '\n');
    }
    
    for(int m = 1; m <= 12; m++) {
        int tem_aniversariante = 0;
        for(int i = 0; i < 40; i++) {
            if(pessoas[i].mes == m) {
                tem_aniversariante = 1;
                break;
            }
        }
        if(tem_aniversariante) {
            printf("Aniversariantes do mes %d:\n", m);
            for(int i = 0; i < 40; i++) {
                if(pessoas[i].mes == m) {
                    printf("Nome: %s, Dia: %d\n", pessoas[i].nome, pessoas[i].dia);
                }
            }
        }
    }
    
    return 0;
}