//https://vjudge.net/problem/Aizu-ALDS1_3_B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, q;
    cin >> n >> q;

    queue<pair<string,ll>> qq; 
    vector<string> a(n); 
    vector<ll> b(n);  

    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        qq.push({a[i], b[i]});
    }

ll tempo = 0;

    while (!qq.empty()) {
        string nome = qq.front().first;
    ll tempo_restante = qq.front().second; 
        qq.pop();

        ll tempo_total = min(tempo_restante, q);

        tempo += tempo_total;
        tempo_restante -= tempo_total;

        if (tempo_restante == 0) {
            cout << nome << " " << tempo << endl;
        } else {
            qq.push({nome, tempo_restante});
        }
    }

    return 0;
}
