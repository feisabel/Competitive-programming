#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

void backtrack(int i, int n, int m, vector<pair<int,int>>& pieces,  vector<bool>& visited, pair<int,int>& prev, pair<int,int>& last, bool& cont) {
	if (!cont)
		return;
	if(i == n) {
		if(prev.second == last.first) {
			cont = false;
		}
		return;
	}
	for(int j = 0; j < m; j++) {
		if(!visited[j]) {
			if(pieces[j].second == prev.second) {
				int aux = pieces[j].first;
				pieces[j].first = pieces[j].second;
				pieces[j].second = aux;
			}
			if(pieces[j].first == prev.second) {
				visited[j] = true;
				backtrack(i+1, n, m, pieces, visited, pieces[j], last, cont);
				visited[j] = false;
			}
		}
	}
	return;
}

int main() {
	int n, m, x, y;
	while(cin >> n && n > 0) {
		cin >> m;
		pair<int,int> first;
		pair<int,int> last;
		cin >> x >> y;
		first = {x,y};
		cin >> x >> y;
		last = {x,y};
		vector<pair<int,int>> pieces;
		vector<bool> visited(m, false);
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			pieces.push_back({x,y});
		}
		bool cont = true;
		backtrack(0, n, m, pieces, visited, first, last, cont);
		if(!cont) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}