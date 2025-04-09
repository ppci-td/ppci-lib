#include<bits/stdc++.h>

using namespace std;

struct Item {
    int w;
    int v;
    double r;
};


void bubbleSort(vector<Item>& items) {
    int n = items.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].r < items[j + 1].r) { 
                swap(items[j], items[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main(){
    int cw, n, w;
    double maxv, totalv;

    cin >> n >> w;
    vector<Item> items(n);
    for(auto& item : items){
        cin >> item.w >> item.v;
        item.r = (double)item.v / item.w;
    }

    bubbleSort(items);

    totalv = 0.0;
    cw = 0;

    for(auto& item: items){
        if(cw + item.w <= w){
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
