#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

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
	int tests, t;
	cin >> tests;
	for(t = 1; t <= tests; t++) {
		cout << "Case #" << t << ":";
		int n;
		cin >> n;
		vi sen;
		int p;
		int total = 0;
		for(int i = 0; i < n; i++) {
			cin >> p;
			sen.pb(p);
			total+=p;
		}
		int max = 1, max2;
		int imax,imax2;
		while(max != 0) {
			max = 0;
			max2 = 0;
			int i;
			for(i = 0; i < n; i++) {
				if(sen[i] > max) {
					max = sen[i];
					imax = i;
				}
				else if(sen[i] > max2) {
					max2 = sen[i];
					imax2 = i;
				}
			}
			bool b1 = false, b2 = false;
			if(max == 0)
				break;
			for(i = 0; i < n; i++) {
				if(max >= 2 && i!=imax && sen[i] > (float)(total-2)/2)
					b1 = true;
				if(i!=imax && sen[i] > (float)(total-1)/2)
					b2 = true;
			}
			if(max >= 2 && !b1) {
				char ch = 'A' + imax;
				cout << " " << ch << ch;
				sen[imax]-=2;
				total-=2;
			}
			else if(!b2) {
				char ch = 'A' + imax;
				cout << " " << ch;
				sen[imax]--;
				total--;
			}
			else {
				char ch = 'A' + imax;
				cout << " " << ch;
				sen[imax]--;
				ch = 'A' + imax2;
				cout << ch;
				sen[imax2]--;
				total-=2;
			}

		}
		cout << endl;
	}
	return 0;
}