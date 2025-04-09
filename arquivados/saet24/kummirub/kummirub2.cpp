#include <bits/stdc++.h>
#define MOD 1000000007;

using namespace std;
using ll = long long;

struct Matrix {
    int row, col; // Dimensões
    vector<vector<ll>> data;

    Matrix(int rows, int cols, ll diag) : row(rows), col(cols) {
        data = vector<vector<ll>>(row, vector<ll>(col));
        for (int i = 0; i<row && i<col; ++i)
            data[i][i] = diag;
    }

    Matrix operator*(const Matrix& rhs) {
        Matrix saida(row, rhs.col, 0);
        for (int i = 0; i<row; ++i) {
            for (int k = 0; k<col; ++k) { // Invertido (chache hit)
                for (int j = 0; j<rhs.col; ++j) { // Invertido (chache hit)
                    saida.data[i][j] += (data[i][k] * rhs.data[k][j]) %MOD;
                    saida.data[i][j] %= MOD;
                }
            }
        }
        return saida;
    }

    Matrix pow(int exp) { // Ex: $22 = 0b10110 \implies M^{16} * M^4 * M^2$
        Matrix saida(row, col, 1), aux = *this;
        while (exp) {
            if (exp&1) saida = saida * aux;  // exp\&1 == exp\%2
            aux = aux*aux; // A cada iteração: $M$, $M^2$, $M^4$, $M^8$, ...
            exp >>= 1; // exp /= 2;
        }
        return saida;
    }
};

int main() {
    int n, t;
    Matrix vet(n*n, 1, 0); // Vetor do tabuleiro
    Matrix mat(n*n, n*n, 0); // Matriz da operação

    scanf("%d", &n);

    for (int i = 0; i<n; ++i)
        for (int j = 0; j<n; ++j)
            scanf("%lld", &vet.data[(n-1-i)*n + j][0]);

    scanf("%d", &t);

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            int aux;
            scanf("%d", &aux);
            mat.data[aux-1][(n-1-i)*n + j] = 1; // Montagem da matriz
        }
    }

    for (int i = 0; i<n*n-n; ++i)
        mat.data[n+i][i] = 1; // Montagem da matriz

    mat = mat.pow(t); // Exponenciação binária

    vet = mat*vet; // Aplicação da matriz para obter o resultado

    printf("%lld", vet.data[0][0]);
    for (int i = 1; i<n; ++i)
        printf(" %lld", vet.data[i][0]);
    printf("\n");

    return 0;
}

