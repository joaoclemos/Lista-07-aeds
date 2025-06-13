#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTES 500
#define CUSTO_BASE 35.00
#define CUSTO_HORA_ADICIONAL 2.50
#define CUSTO_PAGINA 40.00
#define HORAS_BASE 20

struct Cliente {
    int codigo;
    char email[50];
    int horas_acesso;
    char pagina;
    float valor_pagar;
};

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int num_clientes = 0;

    printf("Digite os dados dos clientes (código -1 para encerrar):\n");
    while (1) {
        scanf("%d", &clientes[num_clientes].codigo);
        if (clientes[num_clientes].codigo == -1) break;

        getchar();
        fgets(clientes[num_clientes].email, 50, stdin);
        clientes[num_clientes].email[strcspn(clientes[num_clientes].email, "\n")] = 0;
        scanf("%d", &clientes[num_clientes].horas_acesso);
        scanf(" %c", &clientes[num_clientes].pagina);
        clientes[num_clientes].pagina = toupper(clientes[num_clientes].pagina);

        float valor = CUSTO_BASE;
        if (clientes[num_clientes].horas_acesso > HORAS_BASE)
            valor += (clientes[num_clientes].horas_acesso - HORAS_BASE) * CUSTO_HORA_ADICIONAL;
        if (clientes[num_clientes].pagina == 'S')
            valor += CUSTO_PAGINA;
        clientes[num_clientes].valor_pagar = valor;

        num_clientes++;
        if (num_clientes >= MAX_CLIENTES) break;
    }

    for (int i = 0; i < num_clientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Codigo: %d\n", clientes[i].codigo);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Horas de Acesso: %d\n", clientes[i].horas_acesso);
        printf("Possui Pagina: %c\n", clientes[i].pagina);
        printf("Valor a Pagar: %.2f Quanzas\n\n", clientes[i].valor_pagar);
    }

    return 0;
}
