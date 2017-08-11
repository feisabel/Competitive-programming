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
	int t, x, y;
	cin >> t;
	for(int tt = 0; tt < t; tt++) {
		cin >> x >> y;
		x -= 2;
		y -= 2;
		while(x % 3 !=0)
			x++;
		while(y%3!=0)
			y++;
		x /= 3;
		y /= 3;
		cout << x * y << endl;
	}
	return 0;
}