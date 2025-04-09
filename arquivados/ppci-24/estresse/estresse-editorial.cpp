#include <bits/stdc++.h>

using namespace std;

int lsp[1000001]; // lsp[i] = Longest Suffix Preffix de p[0..i], ou Maior Sufixo Que É Prefixo Também

int kmp(string &s, string &p) {
    int saida = 0;

    // Pré-processamento
    lsp[0] = 0;
    for (int i = 1, j = 0; i<p.size();) {
        if (p[i] == p[j]) lsp[i++] = ++j;
        else if (j) j = lsp[--j];
        else lsp[i++] = 0;
    }

    // Busca pelas ocorrências do padrão
    for (int i = 0, j = 0; i<s.size();) {
        if (s[i] == p[j]) j++, i++;
        else if (j) j = lsp[--j];
        else i++;

        if (j == p.size()) {
            ++saida;
            j = lsp[--j];
        }
    }

    return saida;
}

char saux[1000001], paux[1000001];

int main() {
    scanf("%s %s", saux, paux);

    string s(saux), p(paux);

    int saida;

    saida = kmp(s, p);

    string p_rev = p;
    reverse(p_rev.begin(), p_rev.end());

    if (p != p_rev)
        saida += kmp(s, p_rev);

    printf("%d\n", saida);

    return 0;
}
