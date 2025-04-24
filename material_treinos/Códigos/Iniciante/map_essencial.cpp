//https://vjudge.net/problem/HackerRank-cpp-maps
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

ll q;
cin >> q;

map<string, ll > m;

for(ll i = 0; i < q; i++){

    ll key, n;
    string a;
    cin >> key >> a;

    if(key == 1) {
        
        cin >> n;
        m[a] += n;
    }

    if(key == 2) m[a] = 0;

    if(key == 3) cout << m[a] << endl;

}

return 0;

}
