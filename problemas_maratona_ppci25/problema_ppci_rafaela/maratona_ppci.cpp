#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int D; // Número de dias
    cin >> D;

    while (D--) {
        int N;
        cin >> N;

        vector<int> fila(N);
        vector<int> ordenada(N);

        for (int i = 0; i < N; i++) {
            cin >> fila[i];
            ordenada[i] = fila[i]; // cópia da fila original
        }

        sort(ordenada.begin(), ordenada.end(), greater<int>()); // ordena em decrescente

        int P=0;

        for (int i = 0; i < N; i++) {
            if (fila[i] == ordenada[i]) {
                P++;
            }
        }
        cout << P << endl; 
    }
   
    return 0;
}

