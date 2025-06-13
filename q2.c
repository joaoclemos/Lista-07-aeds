#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
    double preco;
} Registro;

int main() {
    Registro lojas[15];
    
    for(int i = 0; i < 15; i++) {
        printf("Digite o nome da loja %d: ", i+1);
        fgets(lojas[i].nome, 50, stdin);
        lojas[i].nome[strcspn(lojas[i].nome, "\n")] = 0;
        
        printf("Digite o telefone da loja %d: ", i+1);
        fgets(lojas[i].telefone, 20, stdin);
        lojas[i].telefone[strcspn(lojas[i].telefone, "\n")] = 0;
        
        printf("Digite o preço do eletrodoméstico na loja %d: ", i+1);
        scanf("%lf", &lojas[i].preco);
        getchar();
    }
    
    double soma = 0;
    for(int i = 0; i < 15; i++) {
        soma += lojas[i].preco;
    }
    
    double media = soma / 15;
    printf("A média dos preços é: %.2f\n", media);
    
    printf("Lojas com preços abaixo da média:\n");
    for(int i = 0; i < 15; i++) {
        if(lojas[i].preco < media) {
            printf("Nome: %s, Telefone: %s\n", lojas[i].nome, lojas[i].telefone);
        }
    }
    
    return 0;
}