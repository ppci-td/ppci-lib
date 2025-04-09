#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, k;
ll a[200000];

int main() {
    scanf("%d %d", &n, &k);

    int aux = 0;
    for(int i = 0; i<n; ++i) {
        scanf("%lld", &a[i]);
        ++aux;
    }

    if (aux != n or aux > 200000) {
        printf("erro: %d %d %d\n", n, k, aux);
        return 1;
    }

    ll total = 0;
    map<int, int> spells;
    int dcs = 0;
    int max_dcs = 0;
    for(int i = 0, j = 0; i<n;) {
        if (total+a[i] <= k) {
            total += a[i];
            spells[a[i]]++;
            if (spells[a[i]] == 0) {
                spells.erase(a[i]);
            }
            else if (spells[a[i]]%2 == 0)
                max_dcs = max(++dcs, max_dcs);
            ++i;
        }
        else if (j < i){
            total -= a[j];
            spells[a[j]]--;
            if (spells[a[j]]&1)
                --dcs;
            ++j;
        }
        else {
            ++j, ++i;
        }
        //printf("i: %d, j: %d\n", i, j);
        //for (auto num : spells) {
            //printf(" + %d: %lu\n", num, spells.count(num));
        //}
    }

    printf("%d\n", max_dcs);

    return 0;
}
