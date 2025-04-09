#include <bits/stdc++.h>

using namespace std;

int n; 
double r[100], v[100], xl, xr, xp, yp;

int main() {
    scanf("%d", &n);

    for(int i = 0; i<n; ++i) {
        scanf("%lf", &r[i]);
    }
    for(int i = 0; i<n; ++i) {
        scanf("%lf", &v[i]);
    }
    scanf("%lf %lf", &xl, &xr);
    scanf("%lf %lf", &xp, &yp);

    double dx = 1e-5;

    // Dividi em 3 partes do triangulo. 
    // Se xr < xp < xl, só pega a parte do meio.
    // Se o ponto p estiver a esquerda do xr ou a direita do xl,
    // vai entrar em um dos ifs
    double area[100] = {};
    if (xp < xl) {
        for (double x = xp; x<xl; x+=dx) {
            double yl = yp/(xp-xl)*(x-xl);
            double yr = yp/(xp-xr)*(x-xr);
            double prev_h = yl;
            for (int j = 0; j<n; ++j) {
                if (abs(x) > r[j]) continue;

                double h = sqrt(r[j]*r[j] - x*x);

                if (h < yl) continue;

                h = min(h, yr);

                double aux = prev_h;
                prev_h = h;
                h -= aux;

                area[j] += h*dx;
                if (yr == prev_h) break;
            }
        }
    }

    for (double x = xl; x<xr; x+=dx) {
        double prev_h = 0;
        double y;

        if (xp <= xl) {
            y = yp/(xp-xr) * (x-xr);
        }
        else if (xr <= xp) {
            y = yp/(xp-xl) * (x-xl);
        }
        else {
            y = min(yp/(xp-xl)*(x-xl), yp/(xp-xr)*(x-xr));
        }

        for (int j = 0; j<n; ++j) {
            if (abs(x) > r[j]) continue;

            double h = sqrt(r[j]*r[j] - x*x);

            h = min(h, y);

            double aux = prev_h;
            prev_h = h;
            h -= aux;

            area[j] += h*dx;
            if (y == prev_h) break;
        }
    }

    if (xr < xp) {
        for (double x = xr; x<xp; x+=dx) {
            double yl = yp/(xp-xl)*(x-xl);
            double yr = yp/(xp-xr)*(x-xr);
            double prev_h = yr;
            for (int j = 0; j<n; ++j) {
                if (abs(x) > r[j]) continue;

                double h = sqrt(r[j]*r[j] - x*x);

                if (h < yr) continue;

                h = min(h, yl);

                double aux = prev_h;
                prev_h = h;
                h -= aux;

                area[j] += h*dx;
                if (yl == prev_h) break;
            }
        }
    }

    double saida = 0;

    for(int i = 0; i<n; ++i) {
        saida += area[i] * v[i];
    }
    
    printf("%.2lf\n", saida);

    return 0;
}
