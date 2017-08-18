#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <fstream>
#include <algorithm>

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
	int n;
	cin >> n;
	while(n != 0) {
		string result = "";
		cin >> s;
		n = s.size()/n;
		for(int i = 0; i < s.size(); i += n) {
			string sub = s.substr(i,n);
			reverse(sub.begin(), sub.end());
			result = result + sub;
		}
		cout << result << endl;
		cin >> n;
	}
	return 0;
}