//link do problema: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/S

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin >> t;

    while(t--){
        ll x, y, maior, menor, sum = 0;
        cin >> x >> y;

        maior = max(x, y);
        menor = min(x, y);

        for(ll i = menor+1; i < maior; i++){
            if(i%2 != 0) sum += i;
        }

        cout << sum << endl;
    }


    return 0;
}
