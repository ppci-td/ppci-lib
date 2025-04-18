#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
int main(){
 
ld n, m;
cin >> n;

m = floor(n);

if(m == n) cout << "int" << " " << m << endl;

else cout << "float" << " " << m << " " << n-m << endl;

return 0;
 
}