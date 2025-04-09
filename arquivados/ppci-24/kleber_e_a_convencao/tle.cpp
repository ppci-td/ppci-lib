#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, e, q;
    cin >> n >> e;
    vector<int> m;
    int x=0, y;
    for(int i=0; i<n; i++){
        cin >> y;
        x ^= y;
    }
    for(int i=0; i<e; i++){
        cin >> y;
        m.push_back(y);
    }
    int resp=0;
    int j=0, xx;
    while(1<<j<=x) j++;
    xx = ((1<<j)-1)^x;
    if(find(m.begin(),m.end(),xx)!=m.end()) resp++;
    cin >> q;
    for(int i=0; i<q; i++){
        char c;
        int y, xx, j=0;
        cin >> c >> y;
        x ^= y;
        while(1<<j<=x) j++;
        xx = ((1<<j)-1)^x;
        if(find(m.begin(),m.end(),xx)!=m.end()) resp++;
    }
    cout << resp << '\n';

    return 0;
}
