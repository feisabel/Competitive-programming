#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <climits>

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
	int n, b, h, w, p, a, total = INT_MAX;
	bool ok = false;
	while(scanf("%i %i %i %i", &n, &b, &h, &w) != EOF) {
		total = INT_MAX;
		for(int i = 0; i < h; i++) {
			cin >> p;
			ok = false;
			for(int j = 0; j < w; j++) {
				cin >> a;
				if(a >= n)
					ok = true;
			}
			if (p*n > b)
				ok = false;
			if(ok) {
				if(p*n < total)
					total = p*n;
			}
		}
		if(total < INT_MAX)
			cout << total << endl;
		else
			cout << "stay home" << endl;
	}
	return 0;
}