#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

void backtrack (vector<vector<int>>& graph, int n, int i, vector<int>& color, vector<int>& best, int& blacks) {
	if (i == n + 1) {
		int count = 0;
		for(int j = 1; j <= n; j++) {
			if(color[j] == 1)
				count++;
		}
		if(count>blacks) {
			blacks = count;
			best = color;
		}
	}
	else {
		bool aux = true;
		for(auto it = graph[i].begin(); it != graph[i].end(); it++) {
			if(color[*it])
				aux = false;
		}
		if (aux) {
			color[i] = 1;
			backtrack(graph, n, i+1, color, best, blacks);
			color[i] = 0;
		}
		backtrack(graph, n, i+1, color, best, blacks);
	}

}

int main() {
	int cases, n, m, u, v;
	cin >> cases;
	for(int i = 0; i < cases; i++) {
		cin >> n >> m;
		vector<vector<int> > graph(n+1);
		vector<int> color(n+1, 0);
		for (int j = 0; j < m; j++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int blacks = 0;
		vector<int> best(n+1);
		backtrack(graph, n, 1, color, best, blacks);
		int count = 0;
		int first = -1;
		for(int j = 1; j <= n; j++) {
			if (best[j]) {
				if(first == -1)
					first = j;
				count++;
			}
		}
		cout << count << endl;
		cout << first;
		for(int j = first+1; j <= n; j++) {
			if (best[j]) {
				cout << " " << j;
			}
		}
		cout << endl;
	}
	return 0;
}