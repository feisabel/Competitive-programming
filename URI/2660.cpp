#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if(a < b)
		return gcd(b,a);
	while(b!=0) {
		int aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

int main() {
	int n, L, max = 0, maxi;
	long long mmc, t;
	cin >> n >> L;
	cin >> mmc;
	for(int i = 1; i < n; i++) {
		cin >> t;
		mmc = (t*mmc)/gcd(t,mmc);
	}
	for(int i = 1; i <= L; i++) {
		t = (i*mmc)/gcd(i,mmc);
		if(t > max && t <= L) {
			max = t;
			maxi = i;
		}
	}
	cout << maxi << endl;
	return 0;
}