#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair 

int main() {
	string s;
	int n, f, l;
	int j = 1;
	cin >> s;
	while(s != "\n" && !cin.eof()) {
		cin >> n;
		cout << "Case " << j << ":" << endl;
		j++;
		for(int i = 0; i < n; i++) {
			cin >> f >> l;
			int fi = min(f,l), la = max(f,l);
			string s2 = s.substr(fi, la - fi + 1);
			bitset<1000000> bits(s2);
			int count = bits.count();
			if (count == 0 || count == s2.size())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cin >> s;
	}
	return 0;
}