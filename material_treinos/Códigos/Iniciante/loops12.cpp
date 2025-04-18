#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(n == 0) cout << 0 << endl;

        while(n > 0){
            ll aux = n % 10;
            cout << aux << " ";
            n /= 10;
        }
        cout << endl;
    }

return 0;
}