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
#include <list>

using namespace std; 

int main() {
	int n;
	int t = 1;
	cin >> n;
	while (n) {
		cout << "Scenario #" << t << endl;
		t++;
		queue<int> q;
		vector< queue<int> > team_qs(n);
		map<int,int> team;
		for(int j = 0; j < n; j++) {
			int k;
			cin >> k;
			for (int i = 0; i < k; i++) {
				int a;
				cin >> a;
				team[a] = j;
			}
		}
		string s;
		cin >> s;
		int k;
		while (s.compare("STOP") != 0) {
			if (s.compare("ENQUEUE") == 0) {
				cin >> k;
				if (team_qs[team[k]].empty()) {
					q.push(team[k]);
				}
				team_qs[team[k]].push(k);
			}
			else {
				cout << team_qs[q.front()].front() << endl;
				team_qs[q.front()].pop();
				if(team_qs[q.front()].empty()) {
					q.pop();
				}
			}
			cin >> s;
		}

		cout << endl;
		cin >> n;
	}
	return 0;
}