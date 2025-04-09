#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n < 1 or n > 200000) printf("n=%d fora do range\n", n);

    ll a[200001];
    ll bigst_odd = -1;
    ll bigst_even = -1;
    vector<ll> pares;
    for(int i = 0; i<n; ++i) {
        ll a;
        scanf("%lld", &a);
        if (a&1) bigst_odd = max(bigst_odd, a);
        else {
            bigst_even = max(bigst_even, a);
            pares.push_back(a);
        }

    }

    if (bigst_odd == -1) {
        printf("-1\n");
        return 0;
    }
    
    sort(pares.begin(), pares.end());

    int saida = 0;
    for (int a : pares) {
        if (bigst_odd < a) {
            bigst_odd += bigst_even;
            saida++;
        }
        bigst_odd += a;
        saida++;
    }

    printf("%d\n", saida);

    return 0;
}
