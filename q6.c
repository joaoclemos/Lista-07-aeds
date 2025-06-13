#include <stdio.h>

typedef struct {
    int x, y;
} Ponto;

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        Ponto p[3];
        int vert = 0, hor = 0;

        for(int j = 0; j < 3; j++) {
            scanf("%d %d", &p[j].x, &p[j].y);
        }

        if(p[0].x == p[1].x && p[1].x == p[2].x) vert = 3;
        else if(p[0].x == p[1].x || p[1].x == p[2].x || p[0].x == p[2].x) vert = 1;

        if(p[0].y == p[1].y && p[1].y == p[2].y) hor = 3;
        else if(p[0].y == p[1].y || p[1].y == p[2].y || p[0].y == p[2].y) hor = 1;

        if(vert == 0) printf("Nao ha alinhamentos verticais\n");
        else printf("alinhamentos verticais: %d\n", vert);

        if(hor == 0) printf("Nao ha alinhamentos horizontais\n");
        else printf("alinhamentos horizontais: %d\n", hor);
    }

    return 0;
}
