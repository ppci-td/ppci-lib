#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = INT_MAX;

int main() {
    ll N, K;
    ll MaximoDeCamadas = 1000;
    
    cin >> N >> K;
    
    vector<ll> baloes(N); 
    vector<ll> macacos(K);

    for (ll i = 0; i < N; ++i) {
        cin >> baloes[i];
    }

    for (ll i = 0; i < K; ++i) {
        cin >> macacos[i];
    }
    
    vector<ll> dp(MaximoDeCamadas + 1, INF);
    dp[0] = 0;
    
    for (ll h = 1; h <= MaximoDeCamadas; ++h) {
        for (ll d : macacos) {
            if (h >= d && dp[h - d] != INF) {
                dp[h] = min(dp[h], dp[h - d] + 1);
            }
        }
    }
    
    ll total_macacos = 0;
    for (ll h : baloes) {
        if (dp[h] == INF) {
            cout << -1 << endl;
            return 0;
        }
        total_macacos += dp[h];
    }
    
    cout << total_macacos << endl;
    
    return 0;
}