#include <bits/stdc++.h>

using namespace std;

int main() {

    srand(time(NULL) + clock());
    int n = 100;
    printf("%d\n", n);
    for (int i=0;i<n;i++) {
        if (i) printf(" ");
        printf("%d",i+1);
    }
    printf("\n");
    for (int i=0;i<n;i++) {
        if (i) printf(" ");
        printf("1");
    }
    printf("\n");
    int xl = -(rand()%101);
    int xr = rand()%101;
    printf("%d %d\n", xl, xr);

    printf("%d %d\n", rand()%201 - 100, rand()%101);
    return 0;
}
