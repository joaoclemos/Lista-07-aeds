#include <stdio.h>
#include <string.h>

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
    char continuar;

    do {
        if (num_clientes >= MAX_CLIENTES) break;

        scanf("%d", &clientes[num_clientes].codigo);
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
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
    } while (continuar == 'S');

    printf("%-10s %-30s %-15s %-10s %-15s\n", "Codigo", "E-mail", "Horas", "Pagina", "Valor a Pagar");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < num_clientes; i++)
        printf("%-10d %-30s %-15d %-10c %-15.2f\n",
               clientes[i].codigo, clientes[i].email, clientes[i].horas_acesso,
               clientes[i].pagina, clientes[i].valor_pagar);

    return 0;
}