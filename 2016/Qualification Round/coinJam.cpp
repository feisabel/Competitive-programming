#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int t, n, j, a, b;
	cin >> t;
	cin >> n >> j;
	string s = "3 2 5 2 7 2 9 2 11";
	string s2 = "1";
	string aux;
	for(int i = 0; i < n - 2; i++) {
		s2 += '0';
	}
	s2 += '1';
	a = n-2;
	b = n-3;
	cout << "Case #1:" << endl;
	cout << s2 << " " << s << endl;
	j--;
	while(j > 0 && a > 1) {
		for(int k = b; k > 0 && j > 0; k-=2) {
			aux = s2;
			aux[a] = '1';
			aux[k] = '1';
			cout << aux << " " << s << endl;
			j--;
		}
		a--;
		b--;
	}
	if(j > 0) {
		s2[n-2] = '1';
		s2[n-3] = '1';
		a = n-4;
		b = n-5;
		while(j > 0 && a > 1) {
			for(int k = b; k > 0 && j > 0; k-=2) {
				aux = s2;
				aux[a] = '1';
				aux[k] = '1';
				cout << aux << " " << s << endl;
				j--;
			}
			a--;
			b--;
		}
	}
	if(j > 0) {
		s2[n-4] = '1';
		s2[n-5] = '1';
		a = n-6;
		b = n-7;
		while(j > 0 && a > 1) {
			for(int k = b; k > 0 && j > 0; k-=2) {
				aux = s2;
				aux[a] = '1';
				aux[k] = '1';
				cout << aux << " " << s << endl;
				j--;
			}
			a--;
			b--;
		}
	}

	return 0;
}