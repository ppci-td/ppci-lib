//link do problema: https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/Y

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
ll a, b ,c, d;

cin >> a >> b >> c >> d;

ll mult = a % 100;

mult = (mult * (b%100)) %100;
mult = (mult * (c%100)) %100;
mult = (mult * (d%100)) %100;

if(mult < 10) cout << "0" << mult << endl;

else cout << mult << endl;

return 0;
}
