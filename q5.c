#include <stdio.h>

struct Cliente {
    char nome[50];
    char endereco[50];
    char telefone[15];
};

int main() {
    struct Cliente clientes[2];
    
    for(int i = 0; i < 2; i++) {
        scanf("%[^\n]%*c", clientes[i].nome);
        scanf("%[^\n]%*c", clientes[i].endereco);
        scanf("%[^\n]%*c", clientes[i].telefone);
    }
    
    for(int i = 0; i < 2; i++) {
        printf("%s %s %s\n", clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
    
    return 0;
}