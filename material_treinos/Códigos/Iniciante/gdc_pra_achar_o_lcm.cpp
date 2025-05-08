//https://codeforces.com/problemset/problem/1285/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ll n;
    cin >> n;

    ll a = 1, b = n;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ll j = n / i;
            if (gcd(i, j) == 1) {
                if (max(i, j) < max(a, b)) {
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a << " " << b << endl;
    return 0;
}