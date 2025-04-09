#include <bits/stdc++.h>

using namespace std;
int n;
int raio[128], valor[128];
int xl, xr, xp, yp;

bool dentrotri(int x, int y) {

    int v1x, v1y, v2x, v2y;
    int t1, t2, t3;
    v1x = xr - xl;
    v1y = 0 - 0;
    v2x = x - xl;
    v2y = y - 0;
    t1 = v1x*v2y - v1y*v2x;

    v1x = xp - xr;
    v1y = yp - 0;
    v2x = x - xr;
    v2y = y - 0;
    t2 = v1x*v2y - v1y*v2x;

    v1x = xl - xp;
    v1y = 0 - yp;
    v2x = x - xp;
    v2y = y - yp;
    t3 = v1x*v2y - v1y*v2x;

    return (t1 <= 0 and t2 <= 0 and t3 <= 0) or
           (t1 >= 0 and t2 >= 0 and t3 >= 0);
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", raio+i);
    for (int i=0;i<n;i++) scanf("%d", valor+i);
    scanf("%d %d", &xl, &xr);
    scanf("%d %d", &xp, &yp);

    double total = 0;
    for (int x=-100;x<=100;x++)
        for (int y=0;y<=100;y++) if (dentrotri(x,y))
            for (int i=0;i<n;i++)
                if (x*x + y*y <= raio[i]*raio[i]) {
                    //printf("(%d,%d) no raio %d\n", x, y, raio[i]);
                    total += valor[i];
                    break;
                }
    printf("%.2lf\n", total);

    return 0;
}
