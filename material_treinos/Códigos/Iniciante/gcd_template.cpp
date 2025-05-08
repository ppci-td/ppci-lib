#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){

    ll a, b;
    cin >> a >> b;

    ll ans = gcd(a, b);

    cout << ans << endl;

    return 0;
}