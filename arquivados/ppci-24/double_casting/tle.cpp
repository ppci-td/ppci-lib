#include <bits/stdc++.h>
using namespace std;

int a[200005], num[1000000005] = {0};
int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    map<int, int> num;
    // O(n^2)
    int r=0, l=0, soma=0, pares=0, resp=0;
    for(int i=0; i<n; i++){
        soma = 0;
        pares = 0;
        for(int j=i; j<n; j++){
            num[a[j]]++;
            soma += a[j];
            if(soma>k) break;
            else{
                if(num[a[j]]%2==0 and num[a[j]]>0){
                    pares++;
                }
                resp = max(pares, resp);
            }
        }
        num.clear();
    }
    cout << resp << '\n';

    return 0;
}
