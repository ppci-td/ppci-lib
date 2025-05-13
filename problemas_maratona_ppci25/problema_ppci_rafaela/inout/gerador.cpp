#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // por padrao coloquei para gerar 10 arquivos
    int files = (argc > 1) ? atoi(argv[1]) : 10;

    std::srand(static_cast<unsigned>(std::time(nullptr))); // semente aleatória

    const int MAX_D   = 1000;
    const int MAX_N   = 1000;
    const int MAX_PRI = 1'000'000'000;

    for (int k = 0; k < files; k++) {
        string fname = "in_" + to_string(k) + ".in";
        ofstream fout(fname);
        if (!fout) {
            cerr << "Erro ao abrir " << fname << '\n';
            return 1;
        }

        int D = std::rand() % MAX_D + 1;      // 1‥1000
        fout << D << '\n';

        for (int dia = 0; dia < D; dia++) {
            int N = std::rand() % MAX_N + 1;  // 1‥1000
            fout << N << '\n';
            for (int i = 0; i < N; ++i) {
                int P = std::rand() % MAX_PRI + 1; // 1‥1e9
                fout << P << (i + 1 == N ? '\n' : ' ');
            }
        }
        cout << D<<endl;
    }
    return 0;
}
