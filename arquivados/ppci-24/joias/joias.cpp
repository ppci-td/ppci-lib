#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; 
    int sx, sy; 
    int tx, ty; 

    scanf("%d", &N);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &tx, &ty);

  
    int distancia = abs(tx - sx) + abs(ty - sy);

    
    printf("%d\n", distancia);

    return 0;
}
