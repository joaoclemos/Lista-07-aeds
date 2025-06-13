#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1500

struct Livro {
    int codigo;
    char doacao;
    char nome[100];
    char autor[50];
    char editora[50];
    char area[20];
};

int main() {
    struct Livro livros[MAX];
    int total_livros = 0;
    int codigo_consulta;
    char area_consulta[20];
    
    printf("Cadastro de livros (digite -1 para encerrar):\n");
    while (1) {
        int ignorar;
        if (scanf("%d", &ignorar) != 1 || ignorar == -1) break;
        
        scanf("%d %c", &livros[total_livros].codigo, &livros[total_livros].doacao);
        scanf(" %[^\n]", livros[total_livros].nome);
        scanf(" %[^\n]", livros[total_livros].autor);
        scanf(" %[^\n]", livros[total_livros].editora);
        scanf(" %[^\n]", livros[total_livros].area);
        
        total_livros++;
        if (total_livros >= MAX) break;
    }
    
    printf("\nConsulta de livros (digite -1 para encerrar):\n");
    while (1) {
        if (scanf("%d", &codigo_consulta) != 1 || codigo_consulta == -1) break;
        scanf(" %[^\n]", area_consulta);
        
        int encontrado = 0;
        for (int i = 0; i < total_livros; i++) {
            if (livros[i].codigo == codigo_consulta) {
                printf("Área: %s\n", livros[i].area);
                encontrado = 1;
                break;
            }
        }
        
        if (!encontrado) {
            printf("Livro não encontrado\n");
        }
    }
    
    return 0;
}