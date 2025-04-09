#include<bits/stdc++.h>

using namespace std;

int main(){
    int l;
    string s;
    char tmp;
    int cont = 1;

    cin >> l >> s;

    tmp = s[0];

    for (int i = 1; i < l; i++) {
        if (s[i] == tmp)
            cont++;
        else {
            printf("%c%d", tmp, cont);
            cont = 1;            
            tmp = s[i];          
        }
    }

    printf("%c%d\n", tmp, cont);

    return 0;
}