#include <bits/stdc++.h>

using namespace std;

int pai[100001];

void make_set(int v) {
    pai[v] = v;
}

int find_set(int v) {
    if (pai[v] == v)
        return v;
    return pai[v] = find_set(pai[v]); // Compressão de caminho
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        pai[b] = a;
}


int main() {
    int n, m;
    int p[100000], d[100000];

    scanf("%d %d", &n, &m);
    if (n > 100000) printf("Erro: n > 100000\n");
    if (m > 100000) printf("Erro: m > 100000\n");
    for(int i = 0; i<m; ++i) {
        scanf("%d %d", &p[i], &d[i]);
        if (p[i] >= n) printf("Erro: p[%d] = %d eh maior/igual a n=%d\n", i, p[i], n);
        if (p[i] < 0) printf("Erro: p[%d] = %d eh menor que 0\n", i, p[i]);
        if (d[i] < 1) printf("Erro: d[%d] = %d eh menor que 1\n", i, d[i]);
        if (d[i] > n-p[i]) printf("Erro: d[%d] = %d eh maior que n-p[%d] = %d\n", i, d[i], i, n-p[i]);
    }

    // Uso de Disjoint Set Union (DSU) para compressão de intervalos
    // Resumindo, quando uma posição é pintada, ele passa a apontar
    // para a posição seguinte como o próximo a ser pintado. Se ele
    // já havia sido pintado, já vai ter apontado para o seguinte.
    // A magia está na propriedade de compressão de caminhos do DSU,
    // onde uma eventual chamada de find_set() aproveita e comprime
    // o caminho ao fazer pai[v] = find_set(pai[v]). As chamadas se-
    // guintes se tornam O(1) :O
    for(int i = 0; i<=n; ++i) pai[i] = i;

    int gabi = 0, gui = 0;
    for (int i = m-1; i>=0; --i) {
        for (int j = find_set(p[i]); j < p[i]+d[i]; j = find_set(j)) {
            if (i&1) gui++;
            else gabi++;
            union_sets(j+1, j);
        }
    }

    if (gabi > gui) printf("Gabriela\n");
    else if (gui > gabi) printf("Guilherme\n");
    else printf("Empate\n");

    return 0;
}
