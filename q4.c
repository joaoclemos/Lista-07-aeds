#include <stdio.h>
#include <string.h>

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
    struct Livro exatas[MAX], humanas[MAX], biologicas[MAX];
    int n_exatas = 0, n_humanas = 0, n_biologicas = 0;
    int codigo, i;
    char area[20];
    
    printf("Digite os dados dos livros (código -1 para encerrar):\n");
    while (1) {
        scanf("%d", &codigo);
        if (codigo == -1) break;
        
        struct Livro livro;
        livro.codigo = codigo;
        scanf(" %c", &livro.doacao);
        scanf(" %[^\n]", livro.nome);
        scanf(" %[^\n]", livro.autor);
        scanf(" %[^\n]", livro.editora);
        scanf(" %[^\n]", livro.area);
        
        if (strcmp(livro.area, "Exatas") == 0 && n_exatas < MAX) {
            exatas[n_exatas] = livro;
            n_exatas++;
        } else if (strcmp(livro.area, "Humanas") == 0 && n_humanas < MAX) {
            humanas[n_humanas] = livro;
            n_humanas++;
        } else if (strcmp(livro.area, "Biologicas") == 0 && n_biologicas < MAX) {
            biologicas[n_biologicas] = livro;
            n_biologicas++;
        }
    }
    
    printf("\nDigite o código e a área para consulta (código -1 para encerrar):\n");
    while (1) {
        scanf("%d", &codigo);
        if (codigo == -1) break;
        scanf(" %[^\n]", area);
        
        int encontrado = 0;
        if (strcmp(area, "Exatas") == 0) {
            for (i = 0; i < n_exatas; i++) {
                if (exatas[i].codigo == codigo) {
                    printf("Área: %s\n", exatas[i].area);
                    encontrado = 1;
                    break;
                }
            }
        } else if (strcmp(area, "Humanas") == 0) {
            for (i = 0; i < n_humanas; i++) {
                if (humanas[i].codigo == codigo) {
                    printf("Área: %s\n", humanas[i].area);
                    encontrado = 1;
                    break;
                }
            }
        } else if (strcmp(area, "Biologicas") == 0) {
            for (i = 0; i < n_biologicas; i++) {
                if (biologicas[i].codigo == codigo) {
                    printf("Área: %s\n", biologicas[i].area);
                    encontrado = 1;
                    break;
                }
            }
        }
        
        if (!encontrado) {
            printf("Livro não encontrado\n");
        }
    }
    
    return 0;
}