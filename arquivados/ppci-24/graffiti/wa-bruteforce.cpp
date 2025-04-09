#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int a[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int l, d, v;
        cin >> l >> d;
        v = (i % 2 == 0) ? -1 : 1;
        for (int j = l; j < d; j++) a[j] = v;        
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if (sum > 0)  cout << "Gabriela" << endl;
    else if (sum < 0) cout << "Guilherme" << endl;        
    else cout << "Empate" << endl;

    return 0;
}
