#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int h[1000], d[1000];

    scanf("%d %d", &n, &k);

    if (n < 1 or n > 1000) printf("n fora do range\n");
    if (k < 1 or k > 100) printf("n fora do range\n");

    for(int i = 0; i<n; i++) {
        scanf("%d", &h[i]);
    }

    for(int i = 0; i<k; i++) {
        scanf("%d", &d[i]);
    }

    // --------------------------

    // Minha solução irá calcular a quantidade mínima para
    // cada balão possível, de 1 a 1000. É uma PD O(h*k).

    int num[1001] = {};
    memset(num, 0x3f, sizeof(num)); // Preenche com 0x3f3f3f3f = INFINITO
    num[0] = 0;

    for (int i = 0; i<k; ++i) num[d[i]] = 1;
    
    for (int i = 1; i<=1000; ++i) {
        for (int j = 0; j<k; ++j) {
            if (i - d[j] < 0) continue;
            num[i] = min(num[i], num[i-d[j]]+1);
        }
    }

    int saida = 0;
    for (int i = 0; i<n; ++i) {
        if (num[h[i]] == 0x3f3f3f3f) {
            printf("-1\n");
            return 0;
        }
        saida += num[h[i]];
    }

    printf("%d\n", saida);

    return 0;
}
