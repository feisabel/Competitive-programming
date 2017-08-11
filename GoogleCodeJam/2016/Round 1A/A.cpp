#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int t;
	string s;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> s;
		string lw = "";
		lw += s[0];
		for(int j = 1; j < s.size(); j++) {
			string aux = "";
			if(s[j] < lw[0])
				lw += s[j];
			else {
				aux += s[j];
				aux += lw;
				lw = aux;
			}
		}
		cout << "Case #" << i+1 << ": " << lw << endl;
	}
	return 0;
}