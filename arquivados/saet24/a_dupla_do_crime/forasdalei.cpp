#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ll X, Y;
    cin >> X >> Y;

    ld area_cartolina = X * Y;
    ld area_panfleto = area_cartolina / 20; 
    ld kubitschek = sqrt(area_cartolina / 15);
    ld altura_kubitschek = kubitschek * 5;
    ld largura_kubitschek = kubitschek * 3;
    ld chekskubit = sqrt(area_cartolina / 6);
    ld altura_chekskubit = chekskubit * 3;
    ld largura_chekskubit = chekskubit * 2;
    ld numPanfletosKubitschek = (Y / largura_kubitschek) * (X / altura_kubitschek);
    ld numPanfletosKubitschek_rotacionado = (X / altura_kubitschek) * (Y / largura_kubitschek);
    numPanfletosKubitschek = max(numPanfletosKubitschek, numPanfletosKubitschek_rotacionado);
    ll total_kubitschek = floor(numPanfletosKubitschek);
    ld numPanfletosChekskubit = (Y / largura_chekskubit) * (X / altura_chekskubit);
    ld numPanfletosChekskubit_rotacionado = (X / altura_chekskubit) * (Y / largura_chekskubit);
    numPanfletosChekskubit = max(numPanfletosChekskubit, numPanfletosChekskubit_rotacionado);
    ll total_chekskubit = floor(numPanfletosChekskubit);
    ll max_total = 0;
    
    if(abs((total_kubitschek - total_chekskubit)) == 1) {
        max_total = 20; 
    }
    if((total_kubitschek - total_chekskubit) == 0) {
        max_total = 19;
    }
     /* a ideia e ter um caso que cabe o maximo de panfletos possiveis, que seria 20 pois
        cada unico e 5% do total entao todos unicos seriam 100/5 = 20 e outro caso de quando vai sobrar
        um espaço que não cabe um panfleto, então o maximo seria 19 pois 1 nao caberia devido as dimensoes
        porem nao tenho certeza que o jeito que fiz esses ifs esta correto
        */
    cout << max_total << endl;

    return 0;
}