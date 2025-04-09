// Algoritmo KMP
#include <bits/stdc++.h>

using namespace std;

char s[1000001], p[1000001]; // string do texto e o padrao a ser procurado
int lsp[1000001]; // Longest Suffix Preffix, ou Maior Sufixo Que Eh Prefixo Também, até à posição i :V
int s_sz, p_sz;

vector<int> kmp() {
    vector<int> posicoes;

    s_sz = strlen(s);
    p_sz = strlen(p);

    // Pre-processamento
    lsp[0] = 0;
    for (int i = 1, j = 0; i<p_sz;) {
        if (p[i] == p[j]) lsp[i++] = ++j; // Se for igual, aumenta o sufixo prefixo mais longo ateh ali
        else if (j) j = lsp[--j]; // Se nao eh igual, tentamos um sufixo prefixo de dentro do sufixo prefixo mais longo anterior. Doideira, nao? A explicacao disso eh bem massa
        else lsp[i++] = 0; // Se deu tudo errado, entao o prefixo sufixo mais longo ateh ali eh 0
    }

    // Busca pelo padrao
    for (int i = 0, j = 0; i<s_sz;) {
        if (s[i] == p[j]) j++, i++;
        else if (j) j = lsp[--j];
        else i++;

        if (j == p_sz) {
            posicoes.push_back(i-p_sz); // Constante grande 
            j = lsp[--j];
        }
    }

    return posicoes;
}

int main() {
    scanf(" %s %s", s, p);

    s_sz = strlen(s);
    p_sz = strlen(p);

    vector<int> posicoes1 = kmp();

    for (int i = 0; i<p_sz/2; ++i)
        swap(p[i], p[p_sz-1-i]);

    vector<int> posicoes2 = kmp();

    posicoes1.insert(posicoes1.begin(), posicoes2.begin(), posicoes2.end());
    sort(posicoes1.begin(), posicoes1.end());

    int saida = 0;
    int cur_pos = -1;
    
    for (int pos : posicoes1) {
        if (pos > cur_pos) {
            saida++;
            cur_pos = pos;
        }
    }
    printf("%d\n", saida);

    return 0;
}
