#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int st[4 * N];
int lz[4 * N];

// A solução utilizada foi a Segment Tree com Lazy Propagation

// Atualiza o valor do nodo
void apply(int node, int l, int r, int value) {
    st[node] = (r - l + 1) * value;     // O valor do nodo é o tamanho do intervalo multiplicado pelo valor
    lz[node] = value;                   // Atualiza o nodo do lazy com o valor que será propagado
}

// Propaga o valor do nodo para os filhos
void lazyPropagate(int node, int l, int r) {
    if (lz[node] != 0) {
        int mid = (l + r) / 2;
        apply(2 * node, l, mid, lz[node]);            // Atualiza o filho da esquerda
        apply(2 * node + 1, mid + 1, r, lz[node]);    // Atualiza o filho da direita
        lz[node] = 0;
    }
}

// Atualiza o intervalo [l, r] com o valor
void update(int node, int start, int end, int l, int r, int value) {
    // Intervalo vazio
    if (l > r) return;      

    // Intervalo completo ou folha
    if (start == l && end == r) {       
        apply(node, start, end, value);
        return;
    }

    // Intervalo parcial
    lazyPropagate(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, min(r, mid), value);            // Atualiza o filho da esquerda
    update(2 * node + 1, mid + 1, end, max(l, mid + 1), r, value);  // Atualiza o filho da direita

    // Atualiza o valor do nodo
    st[node] = st[2 * node] + st[2 * node + 1];                    
}


int query(int node, int start, int end, int l, int r) {
    // Intervalo vazio
    if (l > r) return 0;      

    // Intervalo completo ou folha                      
    if (start == l && end == r) return st[node];    

    // Intervalo parcial
    lazyPropagate(node, start, end);                // Propaga o valor do nodo

    // Retorna a soma dos intervalos dos filhos
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, min(r, mid)) + 
           query(2 * node + 1, mid + 1, end, max(l, mid + 1), r);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int l, r, d;
        cin >> l >> d;
        // Calcula o último índice do intervalo em r
        r = l + d - 1;                      

        // A Gabriela seta 1 no intervalo e o Guilherme seta -1
        if (i % 2 == 1)  update(1, 0, n - 1, l, r, 1);
        else update(1, 0, n - 1, l, r, -1);
    }

    // Calcula a soma de todos os intervalos
    // Como eles setam 1 e -1, caso pintarem a mesma quantidade, a soma será 0
    // Assim, se a soma for positiva quer dizer que houve mais 1s que -1s, logo Gabriela ganhou
    // O contrário para Guilherme
    int sum = query(1, 0, n - 1, 0, n - 1);
    if (sum > 0)  cout << "Gabriela" << endl;
    else if (sum < 0) cout << "Guilherme" << endl;        
    else cout << "Empate" << endl;

    return 0;
}
