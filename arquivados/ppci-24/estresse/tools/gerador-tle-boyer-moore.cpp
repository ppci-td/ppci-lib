#include <bits/stdc++.h>

using namespace std;

int n = 1000000;
string p = "zaz";

int main() {
    for(int i = 0; i+p.size()<n; i+=p.size())
        printf("%s", p.c_str());
    printf("\n");

    for(int i = 0; i<n/2; i+=p.size())
        printf("%s", p.c_str());
    printf("\n");

    return 0;
}
