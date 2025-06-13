#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
    double preco;
} Registro;

int main() {
    Registro lojas[15];
    
    printf("Digite os dados das lojas:\n");
    for(int i = 0; i < 15; i++) {
        fgets(lojas[i].nome, 50, stdin);
        lojas[i].nome[strcspn(lojas[i].nome, "\n")] = 0;
        
        fgets(lojas[i].telefone, 20, stdin);
        lojas[i].telefone[strcspn(lojas[i].telefone, "\n")] = 0;
        
        scanf("%lf", &lojas[i].preco);
        getchar();
    }
    
    double soma = 0;
    for(int i = 0; i < 15; i++) {
        soma += lojas[i].preco;
    }
    
    double media = soma / 15;
    printf("A média dos preços cadastrados é: %.2f\n", media);
    printf("Lojas com preços abaixo da média:\n");
    
    for(int i = 0; i < 15; i++) {
        if(lojas[i].preco < media) {
            printf("Nome: %s\n", lojas[i].nome);
            printf("Telefone: %s\n", lojas[i].telefone);
        }
    }
    
    return 0;
}