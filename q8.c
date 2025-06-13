#include <stdio.h>
#include <stdlib.h>

struct Moto {
    int consumo;
    int tanque;
};

int main() {
    struct Moto moto;
    int distancia;
    
    srand(6);
    distancia = rand() % 101;
    
    scanf("%d", &moto.consumo);
    scanf("%d", &moto.tanque);
    
    int autonomia = moto.consumo * moto.tanque;
    int paradas = 0;

    if (distancia > 0 && autonomia > 0) {
        paradas = (distancia - 1) / autonomia;
    }

    if (paradas == 0) {
        printf("A moto nao precisa parar para abastecer\n");
    } else {
        printf("A moto precisa parar %d vezes para abastecer\n", paradas);
    }

    return 0;
}