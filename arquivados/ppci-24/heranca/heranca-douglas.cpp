#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int> a, tuple<int, int> b) {
    return double(get<0>(a))/get<1>(a) > double(get<0>(b))/get<1>(b);
}

int main() {
    int n, w;
    tuple<int, int> item[1000000];

    scanf("%d %d", &n, &w);

    for(int i = 0; i<n; ++i) {
        int aux1, aux2;
        scanf("%d %d", &aux1, &aux2);
        item[i] = make_tuple(aux2, aux1);
    }

    sort(item, item+n, comp);

    double saida = 0;
    for(int i = 0; i<n; ++i) {
        int v, p;
        tie(v, p) = item[i];
        double porcentagem = min(1.0, ((double)w)/p);
        saida += porcentagem * v;
        w -= p;
        if (w <= 0)
            break;
    }

    printf("%.2lf\n", saida);

    return 0;
}
