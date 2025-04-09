#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main() {
    int n, t;
    long long tab[10+1][10] = {};
    int plyr[10][10];

    scanf("%d", &n);

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j){
            scanf("%lld", &tab[i][j]);
        }
    }

    scanf("%d", &t);

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j){
            scanf("%d", &plyr[i][j]);
            plyr[i][j]--;
        }
    }


    for (int i = 0; i<t; ++i) { // Turno
        for (int j = 0; j<n; ++j) { // Linha
            tab[n][j] = 0;
        }

        for (int j = 0; j<n; ++j) { // Linha
            for (int k = 0; k<n; ++k) { // Coluna
                tab[n][plyr[j][k]] += tab[j][k];
                tab[n][plyr[j][k]] %= MOD;
            }
        }
        for (int j = 0; j<n; ++j) { // Linha
            for (int k = 0; k<n; ++k) { // Coluna
                tab[j][k] = tab[j+1][k];
            }
        }
    }

    printf("%lld", tab[n-1][0]);
    for (int i = 1; i<n; ++i) {
        printf(" %lld", tab[n-1][i]);
    }
    printf("\n");

    return 0;
}
