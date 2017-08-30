#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <stack> 
#include <map>
#include <vector>

using namespace std; 

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin,s);
	for(int tt = 0; tt < t; tt++) {
		int total = 0;
		vector<pair<string,int>> trees;
		map<string, int> index;
		while(getline(cin,s) && s != "") {
			total++;
			if(index.find(s) == index.end()) {
				index[s] = trees.size();
				trees.push_back(make_pair(s,1));
			}
			else {
				trees[index[s]].second++;
			}
		}
		sort(trees.begin(), trees.end());
		for(int i = 0; i < trees.size(); i++) {
			cout << trees[i].first << " ";
			float p = 100.0 * float(trees[i].second) / total;
			printf("%.4f", p);
			cout << endl;
		}
		if(tt < t-1)
			cout << endl;
	}
	return 0;
}