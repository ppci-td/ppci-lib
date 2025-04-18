//link problema: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/T

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

ll n, aux, ast = 1;
cin >> n;
aux = n;

for(ll i = 0; i < n; i++){
    for(ll j = aux-1; j > 0; j--) cout << " ";
    
    for(ll k = 0; k < ast; k++) cout << "*";
    aux -= 1;
    ast += 2;
    cout << endl;
}

return 0;

}
