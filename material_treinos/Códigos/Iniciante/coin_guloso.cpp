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

int main() {
    vector<ll> moedas = {};
    ll n = ;
    
    vector<ll> total = guloso(moedas, n);
    
    cout << total.size() << endl;
    
    return 0;
}
