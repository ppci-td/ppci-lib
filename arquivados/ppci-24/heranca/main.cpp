#include<bits/stdc++.h>

using namespace std;

struct Item {
    int w;
    int v;
    double r;
};

bool compare(const Item& a, const Item& b){
    return a.r > b.r;
}


int main(){
    int cw, n, w;
    double maxv, totalv;

    cin >> n >> w;
    vector<Item> items(n);
    for(auto&item : items){
        cin >> item.w >> item.v;
        item.r = (double)item.v/item.w;
    }
    sort(items.begin(), items.end(), compare);
    totalv = 0.0;
    cw = 0;

    for(auto&item: items){
        if(cw+item.w <= w){
            cw += item.w;
            totalv += item.v;
        } else {
            int rw = w - cw;
            totalv += item.r * rw;
            break;
        }
    }
    printf("%.2lf\n", totalv);
}