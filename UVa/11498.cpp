#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <fstream>

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
	int k, x, y, n, m;
	scanf("%i", &k);
	while(k != 0) {
		scanf("%i %i", &n, &m);
		for(int i = 0; i < k; i++) {
			scanf("%i %i", &x, &y);
			if(x == n || y == m)
				cout << "divisa" << endl;
			else if(x < n) {
				if(y > m)
					cout << "NO" << endl;
				else
					cout << "SO" << endl;
			}
			else {
				if(y > m) 
					cout << "NE" << endl;
				else
					cout << "SE" << endl;
			}
		}
		scanf("%i", &k);
	}
	return 0;
}