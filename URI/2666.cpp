#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int DFS(int u, vector<bool>& visited, vector<vector<pair<int,int>>>& tree, vector<int>& gold, int c) {
	int d = 0;
	for(int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i].first;
		if(!visited[v]) {
			visited[v] = true;
			d += DFS(v, visited, tree, gold, c);
			int k = gold[v]/c;
			if(gold[v] % c != 0)
				k++;
			d += k * 2 * tree[u][i].second;
			gold[u]+=gold[v];
		}
	}
	return d;
}

int main() {
	int n, c,g, u, v, w;
	cin >> n >> c;
	vector<int> gold;
	for(int i = 0; i < n; i++) {
		cin >> g;
		gold.push_back(g);
	}
	vector<vector<pair<int,int>>> tree(n);
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;
		tree[u-1].push_back({v-1,w});
		tree[v-1].push_back({u-1,w});
	}
	vector<bool> visited(n,false);
	visited[0] = true;
	cout << DFS(0, visited, tree, gold, c) << endl;
	return 0;
}