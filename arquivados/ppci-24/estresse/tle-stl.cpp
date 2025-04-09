#include <bits/stdc++.h>

using namespace std;

char aux[1000001];

int main() {
    string s, p, p_rev;

    scanf(" %s", aux);
    s = aux;

    scanf(" %s", aux);
    p = aux;

    p_rev = p;
    reverse(p_rev.begin(), p_rev.end());

    int saida = 0;
    if (p_rev == p) {
        auto cur_pos = s.find(p, 0);
        while(cur_pos != string::npos) {
            saida++;
            cur_pos = s.find(p, cur_pos+1);
        }
    }
    else {
        auto cur_pos = s.find(p, 0);
        while(cur_pos != string::npos) {
            saida++;
            cur_pos = s.find(p, cur_pos+1);
        }

        cur_pos = s.find(p_rev, 0);
        while(cur_pos != string::npos) {
            saida++;
            cur_pos = s.find(p_rev, cur_pos+1);
        }
    }

    printf("%d\n", saida);

    return 0;
}
