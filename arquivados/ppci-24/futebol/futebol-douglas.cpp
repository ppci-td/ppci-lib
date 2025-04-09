#include <bits/stdc++.h>

using namespace std;

int mat[12][12] = {};

vector<int> bfs(int beg, int end) {
    int pai[12] = {};
    pai[beg] = -1;
    queue<int> q;

    q.push(beg);
    while(not q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i<=11; ++i) {
            if (mat[cur][i] == 1 and pai[i] == 0) {
                q.push(i);
                pai[i] = cur;
            }
        }
    }

    if (pai[9] == 0) return vector<int>(1, -1);

    vector<int> out;

    for (int i = 9; i!=1; i = pai[i]) {
        out.push_back(i);
    }
    out.push_back(1);

    reverse(out.begin(), out.end());

    return out;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 1 or n > 55) printf("n = %d fora do range\n", n);

    for(int i = 0; i<n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 1 or x > 11) printf("x = %d fora do range\n", x);
        if (y < 1 or y > 11) printf("y = %d fora do range\n", y);
        mat[x][y] = mat[y][x] = 1;
    }

    vector<int> seq = bfs(1, 11);

    for (int player : seq) {
        printf("%d ", player);
    }
    printf("\n");

    return 0;
}
