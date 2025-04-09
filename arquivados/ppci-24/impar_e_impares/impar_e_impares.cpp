#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int num_impar=0, maior_impar=0, maior_par=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(a[i]%2==1){
            num_impar++;
            maior_impar = max(maior_impar, a[i]);
        }
        else{
            maior_par = max(maior_par, a[i]);
        }
    }
    sort(a.begin(), a.end());
    if(num_impar==0)    cout << "-1\n";
    else{
        int resp = 0;
        for(int i=0; i<n; ++i){
            if(a[i]%2==0 and a[i]<maior_impar){
                resp++;
                maior_impar += a[i];
            }
            if(a[i]%2==0 and a[i]>maior_impar){
                resp+=2;
                maior_impar += maior_par;
            }
        }
        cout << resp << '\n';
    }

return 0;
}
