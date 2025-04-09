#include <bits/stdc++.h>

#define VEZES 1000000

using namespace std;
int n;
int raio[128], valor[128];
int xl, xr, xp, yp;
double area[128];

double getrand() {
    char s[32];
    sprintf(s,"0.");
    for (int i=2;i<10;i++)
        s[i] = rand()%10 + '0';
    s[10]='\0';
    double r;
    sscanf(s,"%lf", &r);
    return r;
}

bool dentrotri(double x, double y) {
    double v1x, v1y, v2x, v2y;
    double t1, t2, t3;
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

double getarea(double r) {
    double pings=0;
    for (int tt=0;tt<VEZES;tt++) {
        double x = getrand()*200 - 100;
        double y = getrand()*100;
        if (dentrotri(x,y) and x*x + y*y <= r*r)
            pings++;
    }
    return (pings/(double)VEZES)*200.0*100.0;
}

int main() {

    srand(time(NULL) + clock());
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", raio+i);
    for (int i=0;i<n;i++) scanf("%d", valor+i);
    scanf("%d %d", &xl, &xr);
    scanf("%d %d", &xp, &yp);

    double total = 0, somaant=0;;
    area[0] = getarea(raio[0]);
    total += area[0]*valor[0];
    somaant=area[0];
    for (int i=1;i<n;i++) {
        area[i] = getarea(raio[i]) - somaant;
        //printf("area %d = %lf\n",i, area[i]);
        total += area[i]*valor[i];
        somaant += area[i];
    }

    printf("%.2lf\n", total);

    return 0;
}
