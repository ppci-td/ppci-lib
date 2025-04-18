//link do problema: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/W

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

ll n;
cin >> n;
ll aux = n;
ll ast = 1;

for(ll i = 0; i < n; i++){
    for(ll j = aux-1; j > 0; j--) cout << " ";
    
    for(ll k = 0; k < ast; k++) cout << "*";
    aux -= 1;
    ast += 2;
    cout << endl;
}
ast = (n*2)-1 ;
aux = 0;

for(ll i = 0; i < n; i++){
    for(ll k = 0 ; k < aux ; k++) cout << " ";

    for(ll j = ast; j > 0; j--) cout << "*";

    ast -= 2;
    aux += 1;
    cout << endl;
}

return 0;
}
