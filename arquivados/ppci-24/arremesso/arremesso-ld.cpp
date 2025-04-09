#include <bits/stdc++.h>

#define ll long long int

#define M_PI          3.141592653589793238462643383279502884L /* pi */

#define EPS 1e-12
#define modulo(n) (n >= 0 ? n : -(n))
#define INF 1e90

using namespace std;

ll n;
ll raio[128];
ll valor[128];
ll xl, xr, xp, yp;

inline ll cmpf(long double a, long double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

struct pvec {
    long double x, y;
    pvec(long double x=0, long double y=0) :x(x), y(y) {}
    pvec operator+(pvec p) { return pvec(x+p.x,y+p.y); }
    pvec operator-(pvec p) { return pvec(x-p.x,y-p.y); }
    pvec operator*(long double a) { return pvec(a*x,a*y); }
    bool operator==(pvec p) { return cmpf(x,p.x)==0 and cmpf(y,p.y)==0; }
    bool operator!=(pvec p) { return cmpf(x,p.x)!=0 or cmpf(y,p.y)!=0; }
    long double dot(pvec p) { return x*p.x + y*p.y; }
    long double cross(pvec p) { return x*p.y - y*p.x; } // < 0 se p tá a direita de this
    long double abs() { return sqrt(x*x + y*y); }
    long double abs2() { return x*x + y*y; }
    long double angulo(pvec p) { // angulo entre vetores
                   //[---cos do angulo----]
        return acos( dot(p)/(abs()*p.abs()) );
    }
    bool entre(pvec a, pvec c) { // this ta alinhado entre a e c?
        pvec b = *this;
        return (cmpf( (a-b).cross(c-b),0.0)== 0 and cmpf( (a-b).dot(c-b), 0.0) <= 0);
    }
};

// area de triangulo, dados 3 pontos
long double area_tri(pvec p1, pvec p2, pvec p3) {
    return fabs( (p2-p1).cross(p3-p1) )/2.0;
}

struct reta {
    pvec P, vd;
    reta(pvec A, pvec B) :P(A), vd(B-A) {} // Definir reta dados dois pontos!!
    bool paralelo(reta s) { return cmpf(vd.x*s.vd.y,s.vd.x*vd.y)==0; }
    bool pertence(pvec p) { return cmpf((p-P).cross(vd),0.0) == 0; }
};

struct circ {
    pvec c;
    long double r;
    circ(pvec c=pvec(0,0), long double r=0) :c(c), r(r) {} //dado ponto e raio
    bool llersec_reta(reta s, pvec &p1, pvec &p2) {
        long double H=s.P.x - c.x;
        long double I=s.P.y - c.y;
        long double A = s.vd.x*s.vd.x + s.vd.y*s.vd.y;
        long double B = 2.0*(s.vd.x*H + s.vd.y*I);
        long double C = H*H + I*I - r*r;
        long double D = B*B - 4.0*A*C;
        if (cmpf(D,0.0) < 0) return false;
        long double L1 = (-B+sqrt(D))/(2.0*A);
        long double L2 = (-B-sqrt(D))/(2.0*A);
        p1 = s.vd*L1 + s.P;
        p2 = s.vd*L2 + s.P;
        return true;
    }
};

pvec llersec_circ_seg(pvec A, pvec B, long double r) {
    reta s = reta(A,B);
    circ c = circ(pvec(0,0), r);
    pvec p1, p2;
    if (!c.llersec_reta(s, p1, p2)) return pvec(-INF, -INF);
    if (p1.entre(A,B) and p1 != A and p1 != B) return p1;
    if (p2.entre(A,B) and p2 != A and p2 != B) return p2;
    if (p1.entre(A,B)) return p1;
    if (p2.entre(A,B)) return p2;
    else return pvec(-INF,-INF);
}

long double arco(pvec O, pvec A, pvec B, long double r) {
    long double aLfa = (A-O).angulo(B-O);
    return (aLfa*r*r)/2.0;
}

long double llertrisemi(ll r) {
    bool Ldentro = (modulo(xl) <= r);
    bool Rdentro = (modulo(xr) <= r);
    bool Pdentro = (xp*xp + yp*yp <= r*r);
    pvec L = pvec(xl, 0);
    pvec R = pvec(xr, 0);
    pvec P = pvec(xp, yp);
    pvec O = pvec(0,0);
    pvec A = pvec(-r,0);
    pvec B = pvec(r,0);

    // caso 1: todo mundo dentro
    if (Ldentro and Rdentro and Pdentro) {
        // triangulo LRP
        return area_tri(L,R,P);
    }

    // caso 2: P fora
    if (Ldentro and Rdentro and !Pdentro) {
        pvec C = llersec_circ_seg(L, P, r);
        pvec E = llersec_circ_seg(R, P, r);
        // LCO + OER + arco OCE
        return area_tri(L,C,O) + area_tri(O,E,R) + arco(O, C, E, r);
    }

    // caso 3: R fora
    if (Ldentro and !Rdentro and Pdentro) {
        pvec D = llersec_circ_seg(P,R, r);
        // LOP + OPD + arco ODB
        return area_tri(L,O,P) + area_tri(O,P,D) + arco(O, D,B, r);
    }
    // caso 4: L fora
    if (!Ldentro and Rdentro and Pdentro) {
        pvec D = llersec_circ_seg(P, L, r);
        // OPR + OPD + arco OAD
        return area_tri(O,P,R) + area_tri(O,P,D) + arco(O,A,D,r);
    }
    // caso 5: R e P fora
    if (Ldentro and !Rdentro and !Pdentro) {
        // 5.1: PR nao llersecta
        if (llersec_circ_seg(P, R, r).x == -INF) {
            pvec C = llersec_circ_seg(P, L, r);
            // OCL + arco OCB
            return area_tri(O,C,L) + arco(O, C, B, r);
        } else {
            // 5.2: PR llersecta
            pvec C, E;
            if (!circ(O,r).llersec_reta(reta(P,R), C, E)) assert(1==2);
            if (C.x > E.x) swap(C,E);
            pvec D = llersec_circ_seg(L,P,r);
            // ODL + arco ODC + OCE + arco OEB
            return area_tri(O,D,L) + arco(O,D,C,r) + area_tri(O,C,E) + arco(O,E,B,r);
        }
    }
    // caso 6: L e P fora
    if (!Ldentro and Rdentro and !Pdentro) {
        // 6.1: PL nao llersecta
        if (llersec_circ_seg(P, L, r).x == -INF) {
            pvec C = llersec_circ_seg(P, R, r);
            // OCR + arco OCA
            return area_tri(O,C,R) + arco(O,C,A,r);
        } else {
            // 6.2: PL llersecta
            pvec C, E;
            if (!circ(O,r).llersec_reta(reta(P,L), C, E)) assert(1==2);
            if (C.x < E.x) swap(C,E);
            pvec D = llersec_circ_seg(R,P,r);
            // ODR + arco OCD + OCE + arco OEA
            return area_tri(O,D,R) + arco(O,C,D,r) + area_tri(O,C,E) + arco(O,E,A,r);
        }
    }
    // caso 7: L e R fora
    if (!Ldentro and !Rdentro and Pdentro) {
        pvec C = llersec_circ_seg(L, P, r);
        pvec D = llersec_circ_seg(R, P, r);
        // arco OBD + ODP + OPC + arco OCA
        return arco(O,B,D,r) + area_tri(O,D,P) + area_tri(O,P,C) + arco(O,C,A,r);
    }

    // caso 8: todos fora
    if (!Ldentro and !Rdentro and !Pdentro) {
        // 8.1 nenhum segmento llerseca
        if (llersec_circ_seg(P, L, r).x == -INF and llersec_circ_seg(P,R,r).x== -INF) {
            // todo o semi-circulo
            return M_PI*r*r/2.0;
        }
        // 8.2 soh PL llersecta
        if (llersec_circ_seg(P, L, r).x != -INF and llersec_circ_seg(P,R,r).x== -INF) {
            pvec C, D;
            if (!circ(O,r).llersec_reta(reta(P,L), C, D)) assert(1==2);
            if (C.x > D.x) swap(C,D);
            // arco OBD + ODC + arco OCA
            return arco(O,B,D,r) + area_tri(O,D,C) + arco(O,C,A,r);
        }
        // 8.3 soh PR llersecta
        if (llersec_circ_seg(P, L, r).x == -INF and llersec_circ_seg(P,R,r).x != -INF) {
            pvec C, D;
            if (!circ(O,r).llersec_reta(reta(P,R), C, D)) assert(1==2);
            if (C.x < D.x) swap(C,D);
            // arco OBC + OCD + arco ODA
            return arco(O,B,C,r) + area_tri(O,C,D) + arco(O,D,A,r);
        }
        // 8.4 ambos llersectam
        if (llersec_circ_seg(P, L, r).x != -INF and llersec_circ_seg(P,R,r).x != -INF) {
            pvec C, D, E,F;
            if (!circ(O,r).llersec_reta(reta(P,L), C, D)) assert(1==2);
            if (C.x > D.x) swap(C,D);
            if (!circ(O,r).llersec_reta(reta(P,R), E, F)) assert(1==2);
            if (E.x > F.x) swap(E,F);
            // arco OBF + OFE + arco OED + ODC + arco OCA
            return arco(O,B,F,r) + area_tri(O,F,E) + arco(O,E,D,r) + area_tri(O,D,C) + arco(O,C,A,r);
        }
    }

    assert(1==2);
    return -42;
}

int main() {

    scanf("%lld", &n);
    for (ll i=0;i<n;i++)
        scanf("%lld", &raio[i]);
    for (ll i=0;i<n;i++)
        scanf("%lld", &valor[i]);
    scanf("%lld %lld", &xl, &xr);
    scanf("%lld %lld", &xp, &yp);

    long double total = 0.0;
    for (ll i=0;i<n;i++) {
        long double area = llertrisemi(raio[i]) - (i>0 ? llertrisemi(raio[i-1]) : 0.0);
        total += area*(long double)valor[i];
    }
    printf("%.2Lf\n",total);

    return 0;
}
