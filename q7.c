#include <stdio.h>

typedef struct {
    float largura;
    float altura;
    float area;
} Retangulo;

void calcularArea(Retangulo *r) {
    r->area = r->largura * r->altura;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        Retangulo ret;
        scanf("%f", &ret.largura);
        scanf("%f", &ret.altura);
        
        calcularArea(&ret);
        printf("A área do retângulo é: %.2f\n", ret.area);
    }
    
    return 0;
}