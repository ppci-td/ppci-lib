// Um caso onde o padrao eh 'xx...x' e o texto eh um monte de 'x' com 
// um ou outro 'o' atrapalhando
#include <bits/stdc++.h>

using namespace std;

const int n = 1000000; // Deve ser multiplo de 8, ou deve-se mudar o codigo

int main() {
    if(n%8 != 0) throw "N deve ser multiplo de 8, ou deve-se mudar o codigo\n";

    string s(n, 'x'), p(n/8,'x');
    int v[] = {3, 51, 7, 11, 12, 2557, 37, 5}; // Qlqr numero, sei la

    for (int i = 1; i<=8; ++i) {
        s[i*p.size() - v[i-1]] = 'o';
    }

    printf("%s\n", s.c_str());
    printf("%s\n", p.c_str());

    return 0;
}
