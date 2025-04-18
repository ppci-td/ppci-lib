//link do problema: https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
int main(){
 
ll a, b, c;
cin >> a >> b >> c;

ll mi, ma;

mi = min({a, b, c});
ma = max({a, b, c});

cout << mi << " " << ma << endl;

return 0;
 
}
