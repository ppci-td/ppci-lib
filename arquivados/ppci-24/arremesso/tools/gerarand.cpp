#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main() {

    srand(time(NULL) + clock());
    int n = rand()%100 + 1;
    while (S.size() < n)
        S.insert( rand()%100 + 1 );
    printf("%d\n", n);
    bool prim=true;
    for (set<int>::iterator Si = S.begin(); Si != S.end(); Si++) {
        if (!prim) printf(" "); prim=false;
        printf("%d", *Si);
    }
    printf("\n");
    for (int i=0;i<n;i++) {
        if (i) printf(" ");
        printf("%d", rand()%11);
    }
    printf("\n");
    int xl = -(rand()%101);
    int xr = rand()%101;
    printf("%d %d\n", xl, xr);

    printf("%d %d\n", rand()%201 - 100, rand()%101);
    return 0;
}
