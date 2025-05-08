//https://codeforces.com/problemset/problem/1498/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sum_of_digits(ll x) {
    ll sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        while (true) {
            ll sum = sum_of_digits(n);
            if (gcd(n, sum) > 1) {
                cout << n << endl;
                break;
            }
            n++;
        }
    }
    return 0;
}
