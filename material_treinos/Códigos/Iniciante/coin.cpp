#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<ll> guloso(const vector<ll>& m, ll total) {
    vector<ll> ans;
    vector<ll> sortedm = m;
    sort(sortedm.begin(), sortedm.end(), greater<ll>());
    
    for (ll i : sortedm) {
        while (total >= i) {
            total -= i;
            ans.pb(i);
        }
    }
    
    return ans;
}

vector<ll> pd(const vector<ll>& m, ll total) {
    vector<ll> dp(total + 1, INT_MAX); //atencao para nao chamar esse vetor de "pd" pq chamaria a função recursivamente
    vector<ll> pai(total + 1, -1);
    
    dp[0] = 0;
    
    for (ll i = 1; i <= total; i++) {
        for (ll mAtual : m) {
            if (mAtual <= i && dp[i - mAtual] != INT_MAX && dp[i - mAtual] + 1 < dp[i]) {
                dp[i] = dp[i - mAtual] + 1;
                pai[i] = mAtual;
            }
        }
    }
    
    vector<ll> ans;

    if (dp[total] == INT_MAX) {
        return ans;
    }
    
    ll restante = total;
    while (restante > 0) {
        ll mAtual = pai[restante];
        ans.push_back(mAtual);
        restante -= mAtual;
    }
    
    return ans;
}

int main() {
    vector<ll> moedas = {};
    ll n = ;
    
    vector<ll> total = guloso(moedas, n);
    
    cout << total.size() << endl;
    
    return 0;
}
