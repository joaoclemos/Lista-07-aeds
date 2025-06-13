#include <stdio.h>

typedef struct {
    int x, y;
} Ponto;

int main() {
    int n, i, j, k, l, vert, hor;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        Ponto p[3];
        vert = 0;
        hor = 0;
        
        for(j = 0; j < 3; j++)
            scanf("%d %d", &p[j].x, &p[j].y);
            
        for(j = 0; j < 3; j++)
            for(k = j + 1; k < 3; k++) {
                if(p[j].x == p[k].x) vert++;
                if(p[j].y == p[k].y) hor++;
            }
            
        if(vert == 0) printf("Nao ha alinhamentos verticais\n");
        else printf("alinhamentos verticais: %d\n", vert);
        
        if(hor == 0) printf("Nao ha alinhamentos horizontais\n");
        else printf("alinhamentos horizontais: %d\n", hor);
    }
    
    return 0;
}