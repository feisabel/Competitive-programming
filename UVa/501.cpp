#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <set>

using namespace std; 

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin,s);
	for(int tt = 0; tt < t; tt++) {
		int n, m, x;
		cin >> m >> n;
		vector<int> add;
		vector<int> get;
		multiset<int> bb;
		for(int i = 0; i < m; i++) {
			cin >> x;
			add.push_back(x);
		}
		for(int i = 0; i < n; i++) {
			cin >> x;
			get.push_back(x);
		}

		int k = 0;
		while(k < get[0]) {
			bb.insert(add[k]);
			k++;
		}
		auto it = bb.begin();
		cout << *it << endl;

		for(int i = 1; i < n; i++) {
			int smlr = 0;
			while(k < get[i]) {
				if(add[k] < *it)
					smlr++;
				bb.insert(add[k]);
				k++;
			}
			int j = 1;
			if(smlr == 0) {
				it++;
			}
			else {
				while(j < smlr) {
					it--;
					j++;
				}
			}
			cout << *it << endl;
		}

		getline(cin, s);
		if(tt != t-1)
			cout << endl;
	}
	return 0;
}