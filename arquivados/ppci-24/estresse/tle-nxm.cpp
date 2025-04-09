// Implementacao naive, que faz verificacoes letra a letra. O(N*M).
#include <bits/stdc++.h>

using namespace std;

char s[1000001], p[1000001];

int main() {
    scanf(" %s %s", s, p);

    const int s_sz = strlen(s);
    const int p_sz = strlen(p);

    if (p_sz > s_sz) {
        printf("0\n");
        return 0;
    }

    int saida = 0;

    int i, j;
    bool achou;
    for (i = 0; i<=s_sz-p_sz; ++i) {
        j = 0;
        for (; j<p_sz; ++j) {
            if (s[i+j] != p[j]) break;
        }
        if (j == p_sz) {
            ++saida;
            continue;
        }
        // Note que, se encontrar a palavra arara por ex.,
        // nao conta 2 vezes, pois eh o mesmo momento, a-
        // pesar de arara possivelmente ser de frente pra
        // tras ou de tras para a frente. Por isso usei
        // o continue da linha 29, pulando a verificacao
        // da palavra ao contrario.

        j = 0;
        for (; j<p_sz; ++j) {
            if (s[i+j] != p[p_sz-1-j]) break;
        }
        if (j == p_sz) {
            ++saida;
        }
    }

    printf("%d\n", saida);

    return 0;
}
