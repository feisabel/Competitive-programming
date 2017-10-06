#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

bool ok(vector<int>& queens) {
	for(int i = 0; i < 7; i++) {
		int q = queens[i];
		for(int j = i+1; j < 8; j++) {
			if(q == 7)
				break;
			q++;
			if(q == queens[j]) {
				return false;
			}
		}
	}
	for(int i = 0; i < 7; i++) {
		int q = queens[i];
		for(int j = i+1; j < 8; j++) {
			if(q == 0)
				break;
			q--;
			if(q == queens[j]) {
				return false;
			}
		}
	}
	return true;
}

void backtrack(int& best, int i, vector<int>& queens, int moves, vector<bool>& visited, vector<int>& solution) {
	if(i == 8) {
		if(ok(solution)) {
			if (moves < best) {
				best = moves;
			}
		}
		return;
	}
	for(int j = 0; j < 8; j++) {
		if(!visited[j]) {
			visited[j] = true;
			solution[i] = j;
			if(j == queens[i]) {
				backtrack(best, i+1, queens, moves, visited, solution);
			}
			else {
				backtrack(best, i+1, queens, moves+1, visited, solution);
			}
			visited[j] = false;
		}
	}
	return;
}

int main() {
	int k = 1;
	int x;
	while(cin >> x) {
		cout << "Case " << k << ": ";
		k++;
		vector<int> queens;
		queens.push_back(x-1);
		for(int i = 0; i < 7; i++) {
			cin >> x;
			queens.push_back(x-1);
		}
		int best = INT_MAX;
		vector<bool> visited(8, false);
		vector<int> solution = queens;
		backtrack(best, 0, queens, 0, visited, solution);
		cout << best << endl;
	}
	return 0;
}