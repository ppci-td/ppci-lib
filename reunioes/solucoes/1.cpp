#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
int main(){
 
char x;
cin >> x;
 
if(x > 47 && x < 59) cout << "IS DIGIT" << endl;
if(x > 64 && x < 92) cout << "ALPHA" << endl << "IS CAPITAL" << endl;
if(x > 96 && x < 124) cout << "ALPHA" << endl << "IS SMALL" << endl;
 
return 0;
 
}