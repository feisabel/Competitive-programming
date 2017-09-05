#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, s, p;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		map<int,int> solved;
		vector<vector<int>> friends(3);
		for(int i = 0; i < 3; i++) {
			cin >> s;
			for(int j = 0; j < s; j++) {
				cin >> p;
				friends[i].push_back(p);
				if(solved.find(p) == solved.end()) {
					solved[p] = 1;
				}
				else {
					solved[p]++;
				}
			}
		}
		vector<int>count(3,0);
		int max = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < friends[i].size(); j++) {
				if(solved[friends[i][j]] == 1)
					count[i]++;
			}
			if(count[i] > max)
				max = count[i];
		}
		cout << "Case #" << tt << ":" << endl;
		for(int i = 0; i < 3; i++) {
			if(count[i] == max) {
				cout << i+1 << " " << max;
				sort(friends[i].begin(), friends[i].end());
				for(int j = 0; j < friends[i].size(); j++) {
					if(solved[friends[i][j]] == 1) {
						cout << " " << friends[i][j];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}