#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ll N;
    cin >> N;

    ld kubitschekVida = 5000.0;
    ld chekskubitVida = 5000.0;

    for (ll i = 1; i <= N; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ld distanciaKubitschek = sqrt(x1 * x1 + y1 * y1);
        ld distanciaChekskubit = sqrt(x2 * x2 + y2 * y2);

        if (i % 2 == 1) { 
            if (distanciaKubitschek > distanciaChekskubit) {
                ld dano = distanciaKubitschek - distanciaChekskubit;
                kubitschekVida -= dano;
            } else {
                ld dano = distanciaChekskubit - distanciaKubitschek;
                chekskubitVida -= dano;
            }
        } else { 
            if (distanciaKubitschek > distanciaChekskubit) {
                ld cura = distanciaKubitschek - distanciaChekskubit;
                chekskubitVida += cura;
                if(chekskubitVida > 5000) chekskubitVida = 5000;
            } else {
                ld cura = distanciaChekskubit - distanciaKubitschek;
                kubitschekVida += cura;
                if(kubitschekVida > 5000) kubitschekVida = 5000;
            }
        }

        if (kubitschekVida <= 0 || chekskubitVida <= 0) {
            break;
        }
    }

    if (kubitschekVida <= 0 && chekskubitVida <= 0) {
        cout << "Empate" << endl;
    } else {
        if (kubitschekVida == chekskubitVida) {
            cout << "Empate" << endl;
        } else if (kubitschekVida > chekskubitVida) {
            cout << "Kubitschek Venceu" << endl;
        } else {
            cout << "Chekskubit Venceu" << endl;
        }
    }

    return 0;
}
