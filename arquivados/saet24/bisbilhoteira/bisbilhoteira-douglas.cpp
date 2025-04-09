#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;

    if (s.size() != n or s.size() > 100) cout << "erro!\n";
    if (s.size() <= 0 or n <= 0) cout << "erro!\n";

    char c = s[0];
    int count = 1;

    for(int i = 1; i<n; ++i) {
        if (s[i] == s[i-1]) count++;
        else {
            cout << s[i-1] << count;
            c = s[i];
            count = 1;
        }
    }
    cout << s[s.size()-1] << count << "\n";

    return 0;
}
