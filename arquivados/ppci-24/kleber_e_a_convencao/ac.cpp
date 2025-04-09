#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e, q;
    cin >> n >> e;
    set<int> est;
    int x=0, y;
    for(int i=0; i<n; i++){
        cin >> y;
        x ^= y;
    }
    int flag=0;
    for(int i=0; i<e; i++){
        cin >> y;
        est.insert(y);
    }
    cin >> q;
    int resp=0;
        for (int i=0;i<31;i++) {
            if (est.find(  x^((1<<i)-1) ) != est.end()){
                resp++;
                    break;
            }
        }
 


    for (int i=0;i<q;i++) {
        char op[32];
        int y;
        cin >> op >> y;
        x ^= y;
        for (int i=0;i<31;i++) {
            if (est.find(  x^((1<<i)-1) ) != est.end()){
                resp++;
                    break;
            }
        }
    }
    cout << resp << '\n';

    return 0;
}
