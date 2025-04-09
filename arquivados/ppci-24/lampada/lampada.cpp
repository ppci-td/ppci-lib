#include <bits/stdc++.h>
using namespace std;


int main(){
	long long int h;
	cin >> h;			//  2*(P.A de 1 a N) + (P.A de 1 a N-1)/2
	h = (3 * h * h + h)/2;	
	cout <<	h << endl;		//  (2 * ((1 + h)*h)) + ((1 + h - 1) * h))/2
					//  (1 + h)*h + h * h / 2
					//  h * h + h + (h * h)/2
					//  (3 * h * h + h)/2
	return 0;
}

	
