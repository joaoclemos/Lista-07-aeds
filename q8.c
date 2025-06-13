#include <stdio.h>

struct Moto {
    int consumo;
    int tanque;
};

int main() {
    struct Moto moto;
    int distancia = 25;

    scanf("%d", &moto.consumo);
    scanf("%d", &moto.tanque);

    int autonomia = moto.consumo * moto.tanque;
    int paradas = 0;

    if (distancia > autonomia) {
        paradas = (distancia - 1) / autonomia;
    }

    if (paradas == 0) {
        printf("A moto nao precisa parar para abastecer\n");
    } else {
        printf("A moto precisa parar %d vezes para abastecer\n", paradas);
    }

    return 0;
}
