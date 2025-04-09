#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n, t;
long long tab[10][10];
int plyr[10][10];
long long mat[10*10][10*10] = {};
long long res[10*10][10*10] = {};
long long aux[10*10][10*10] = {};

void powMat(int exp) {
    if (exp == 0) {
        for (int i = 0; i<n*n; ++i)
            res[i][i] = 1;
        return;
    }

    powMat(exp/2);

    memset(aux, 0, sizeof(aux));
    for (int i = 0; i<n*n; ++i) {
        for (int j = 0; j<n*n; ++j) {
            for (int k = 0; k<n*n; ++k) {
                aux[i][j] += (res[i][k] * res[k][j]) % MOD;
                aux[i][j] %= MOD;
            }
        }
    }
    memcpy(res, aux, sizeof(res));

    if (exp&1) {
        memset(aux, 0, sizeof(aux));
        for (int i = 0; i<n*n; ++i) {
            for (int j = 0; j<n*n; ++j) {
                for (int k = 0; k<n*n; ++k) {
                    aux[i][j] += (mat[i][k] * res[k][j]) % MOD;
                    aux[i][j] %= MOD;
                }
            }
        }
        memcpy(res, aux, sizeof(res));
    }
}

int main() {
    
    // Ler entrada
    scanf("%d", &n);

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j){
            scanf("%lld", &tab[i][j]);
        }
    }

    scanf("%d", &t);

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j){
            scanf("%d", &plyr[i][j]);
            --plyr[i][j];
        }
    }

    // Montar matriz
    for (int i = 0; i<n; ++i) { // Linha (tabuleiro)
        for (int j = 0; j<n; ++j) { // Coluna (tabuleiro)
            int linhaMat = plyr[i][j];
            mat[linhaMat][n*(n-(i+1)) + j] = 1;
        }
    }

    for (int i = 0; i+n<n*n; ++i) {
        mat[i+n][i] = 1;
    }

    // Exponenciar
    powMat(t);

    // Multiplicar matriz pelo vetor
    long long saida[10] = {};
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n*n; ++j) {
            saida[i] += (res[i][j] * tab[n-1 - j/n][j%n]) % MOD;
            saida[i] %= MOD;
        }
    }

    // Imprimir saída
    printf("%lld", saida[0]);
    for (int i = 1; i<n; ++i) {
        printf(" %lld", saida[i]);
    }
    printf("\n");

    return 0;
}
