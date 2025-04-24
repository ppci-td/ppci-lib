#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {

    ll n;
    cin >> n;
    set<pair<string, string>> s;

    for(ll i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        s.insert({a, b});
    }

    cout << s.size() << endl;

    return 0;
}