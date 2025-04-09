#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;  // número de passes possíveis
    cin >> N;

    // Grafo representado por uma lista de adjacência para 11 jogadores (indexação de 1 a 11)
    vector<vector<int>> adj(12);  // tamanho 12, pois os jogadores são numerados de 1 a 11

    // Ler as N opções de passe
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);  // Adiciona Y como adjacente a X
        adj[Y].push_back(X);  // Adiciona X como adjacente a Y (passe bidirecional)
    }

    int s = 1;  // goleiro (jogador 1)
    int t = 9;  // centroavante (jogador 9)

    // Vetores auxiliares para a BFS
    vector<bool> used(12, false);  // usado para verificar se o jogador já foi visitado
    vector<int> dist(12, -1);      // dist: distância até cada jogador (-1 significa não visitado)

    // BFS
    queue<int> q;
    q.push(s);
    used[s] = true;
    dist[s] = 0;  // distância até o próprio goleiro é 0

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // Para cada jogador adjacente a 'v'
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                dist[u] = dist[v] + 1;  // distância do jogador 'u' é a distância de 'v' + 1
                q.push(u);
            }
        }
    }

    // Verificar a distância até o centroavante (jogador 9)
    if (dist[t] == -1) {
        cout << -1 << endl;  // Não foi possível chegar ao centroavante
    } else {
        // Imprimir o número mínimo de jogadores envolvidos no caminho (distância + 1)
        cout << dist[t] + 1 << endl;  // +1 porque inclui o jogador 1 e o jogador 9
    }

    return 0;
}
