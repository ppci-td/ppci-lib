#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
const ll LIM = 100000;
vector<bool> primo(LIM+1, true);

void crivo(){
    primo[0] = primo[1] = false;

    for(ll i = 2; i*i <= LIM; i++){
        if(primo[i]) {
            for(ll j = i*i; j <= LIM; j+= i){
                primo[j] = false;
            }     
        }
    }
}



int main() {

    crivo();

    ll n;
    cin >> n;

    if(primo[n]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
 
}