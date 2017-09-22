#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main() {
	vector<set<int>> tons(12);
	map<int,string> nota;
	nota[0] = "do";
	nota[1] = "do#";
	nota[2] = "re";
	nota[3] = "re#";
	nota[4] = "mi";
	nota[5] = "fa";
	nota[6] = "fa#";
	nota[7] = "sol";
	nota[8] = "sol#";
	nota[9] = "la";
	nota[10] = "la#";
	nota[11] = "si";
	for(int i = 0; i < 12; i++) {
		tons[i].insert(i);
		tons[i].insert((i+2)%12);
		tons[i].insert((i+4)%12);
		tons[i].insert((i+5)%12);
		tons[i].insert((i+7)%12);
		tons[i].insert((i+9)%12);
		tons[i].insert((i+11)%12);
	}
	set<int> keys;
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> k;
		keys.insert((k-1)%12);
	}
	int i;
	for(i = 0; i < 12; i++) {
		if(includes(tons[i].begin(), tons[i].end(), keys.begin(), keys.end())) {
			cout << nota[i] << endl;
			return 0;
		}
	}
	cout << "desafinado" << endl;
	return 0;
}