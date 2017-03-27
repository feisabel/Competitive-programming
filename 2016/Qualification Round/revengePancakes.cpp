#include <iostream>
#include <string>
#include <vector>

using namespace std;

string invert(string s, int k) {
	string s2 = "";
	for (int i = k; i >= 0; i--) {
		if (s[i] == '+')
			s2 += '-';
		else
			s2 += '+';
	}
	for (int i = k+1; i < s.size(); i++)
		s2 += s[i];
	return s2;
}

int main () {
	int t, j;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		int ans = 0;
		while(1) {
			bool b = false;
			int f, p;
			for(j = s.size() - 1; j >= 0; j--) {
				if(s[j] == '-' && !b) {
					b = true;
					p = j;
					f = j;
				}
				else if(s[j] == '-' && j == p-1) {
					p = j;
				}
				else if(s[j] == '-') {
					break;
				}
			}
			if (j < 0 && !b) {
				cout << "Case #" << i+1 << ": " << ans + 0 << endl;
				break;
			}
			else if(j < 0 && b) {
				if(s[0] == '-')
					cout << "Case #" << i+1 << ": " << ans + 1 << endl;
				else
					cout << "Case #" << i+1 << ": " << ans + 2 << endl;
				break;
			}
			else {
				if(s[0] == '+') {
					int k;
					for(k = f; k >= 0; k--) {
						if (s[k] == '+')
							break;
					}
					s = invert(s, k);
					ans += 1;
				}
				else{
					s = invert(s, f);
					ans += 1;
				}
			}
		}
	}

	return 0;
}