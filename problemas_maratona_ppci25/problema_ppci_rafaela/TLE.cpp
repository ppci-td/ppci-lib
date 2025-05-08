#include <bits/stdc++.h>
using namespace std;

int main() {
    int D;          // número de dias
    cin >> D;

    while (D--) {
        int N;
        cin >> N;

        vector<int> fila(N);
        for (int i = 0; i < N; i++)  
            cin >> fila[i];

        int P = 0;

        for (int i = 0; i < N; i++) {
            vector<int> ord = fila;                       
            sort(ord.begin(), ord.end(), greater<int>()); // O(N log N) repetido
            if (fila[i] == ord[i])
                P++;
        }

        // para cada dia fica O(N^2 log N), devido a ordenacao acontecer dentro do for
        
        cout << P << endl;
    }
    return 0;
}
