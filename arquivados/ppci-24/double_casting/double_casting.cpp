#include <bits/stdc++.h>
using namespace std;

int a[200005];
int main(){
    int n, k;
    cin >> n >> k;
    map<int,int> num;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int r=0, l=0, soma_temp=0, pares=0, resp=0;
    // O(r+l) = O(n)
    while(r<n){
        soma_temp += a[r];
        num[a[r]]++;
        if(num[a[r]]%2==0)  pares++;
        r++;
        while(soma_temp>k){
            soma_temp -= a[l];
            num[a[l]]--;
            if(num[a[l]]%2==1)  pares--;
            l++;
        }
        resp = max(resp, pares);
    }
    cout << resp << '\n';

    return 0;
}
