#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <stack> 
#include <vector>
#include <queue>
#include <map>

using namespace std; 

int main() {
	multimap<int, int> queries;
	string s;
	cin >> s;
	int q, p, k;
	vector<pair<int,int>> ins;
	int min = INT_MAX;
	while(s != "#") {
		cin >> q >> p;
		if(p < min)
			min = p;
		ins.push_back(make_pair(q,p));
		cin >> s;
	}
	cin >> k;
	sort(ins.begin(), ins.end());
	for(int i = 0; i < ins.size(); i++) {
		for(int j = ins[i].second; j <= min*k; j+=ins[i].second) {
			queries.insert(make_pair(j, ins[i].first));
		}
	}
	int i = 1;
	for(auto it = queries.begin(); it != queries.end() && i <= k; it++, i++) {
		cout << it->second << endl;
	}
	return 0;
}