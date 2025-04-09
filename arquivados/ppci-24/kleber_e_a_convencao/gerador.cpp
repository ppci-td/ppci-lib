#include <bits/stdc++.h>
using namespace std;

// testes
// nenhuma insignia - ok
// todas as insignias - ok
// todos bits 1 no estande + xor 0 na coleção - ok
// 4 aleatorios com numeros grandes - ok
// 3 aleatorios com numeros pequenos - ok
// true random - 

int main(){
    // variaveis
    srand(time(0));
    int n=200000, e=200000, q=200000;
    int n_max=1000000000, e_max=1000000000, q_max=1000000000;
    map<int,int> m1, m2;
    int x=0;
    vector<pair<int,char>> a;
    vector<int> b;
    vector<int> v;

    // codigo
    for(int i=0; i<n; i++){
        int y = rand()%n_max;
        x^=y;
        b.push_back(y);
        m1[y]++;
    }
    int j=0, xx;
    while(1<<j<=x) j++;
    xx = ((1<<j)-1)^x;
    m2[xx]++;
    v.push_back(xx);
    for(int i=0; i<q; i++){
        int y = rand()%q_max;
        //int yy = rand()%2;
        x^=y;
        j=0;
        while(1<<j<=x) j++;
        xx = ((1<<j)-1)^x;
        m2[xx]++;
        v.push_back(xx);
        //if(yy)  a.push_back({0,'-'});
        //else    a.push_back({0,'+'});
        if(m1[y]){
            a.push_back({y,'-'});
            m1[y]--;
        }
        else{
            a.push_back({y,'+'});
            m1[y]++;
        }
    }
    j=0;
    while(1<<j<e_max){
        //v.push_back((1<<j)-1);
        j++;
    }
    int k=0;
    while(k<e){
        //if(!m2[y]){
            //m2[y]++;
        //}
    }

    // couts
    cout << b.size() << ' ' << v.size() << '\n';
    for(auto i: b)  cout << i << ' ';
    cout << '\n';
    for(auto i: v)  cout << i << ' ';
    cout << '\n';
    cout << a.size() << '\n';
    for(auto i: a) cout << i.second << ' ' << i.first << '\n';

    return 0;
}
