#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <stack> 
#include <map>
#include <set>

using namespace std; 

int main() {
	int n, m;
	long x;
	cin >> n >> m;
	while(n!= 0 || m!=0) {
		int sell = 0;
		set<long> cds;
		for(int i = 0; i < n; i++) {
			cin >> x;
			cds.insert(x);
		}
		for(int i = 0; i < m; i++) {
			cin >> x;
			if(cds.count(x)) {
				sell++;
			}
		}
		cout << sell << endl;
		cin >> n >> m;
	}
	return 0;
}