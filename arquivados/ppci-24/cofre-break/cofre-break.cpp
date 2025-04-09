#include <bits/stdc++.h>

using namespace std;

// A solucao utilizada foi Sliding Window, com um unordered_map para armazenar os indices onde os elementos foram vistos
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    // i e o inicio da janela, j e o fim da janela, start e end sao os indices da sequencia
    int i = 0, j = 0, x = 0, start = 0, end = 0;          
    unordered_map<int, int> seen;

    while (j < n) {
        x = a[j];                               // Pega o elemento atual
        if (seen.count(x) == 1 && seen[x] >= i) // Se o elemento ja foi visto dentro da janela
            i = seen[x] + 1;                    // Atualiza o inicio da janela para que nao tenha elementos repetidos
        else seen[x] = j++;                     // Senao, atualiza onde o elemento foi visto por ultimo e incrementa j

        if (j - i > end - start) {              // Se a sequencia atual (tamanho da janela) é maior que a sequencia salva
            start = i;                          // Atualiza a sequencia salva
            end = j;
        }
    }

    reverse(a + start, a + end);                // Inverte a maior sequencia encontrada
    for (int i = 0; i < n -1; i++)              // Imprime o vetor
        cout << a[i] << " ";
    cout << a[n-1] << "\n";

    return 0;
}

