#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& tracks, vector<bool>& cd, vector<bool>& best_cd, int& best, int i, int n, int current, bool& cont) {
	if(!cont) 
		return;
	if(i == tracks.size()) {
		return;
	}
	if(current + tracks[i] == n) {
		best = current+tracks[i];
		cd[i] = true;
		best_cd = cd;
		cont = false;
		return;
	}
	if(current + tracks[i] < n) {
		cd[i] = true;
		current += tracks[i];
		if(current > best) {
			best = current;
			best_cd = cd;
		}
		backtrack(tracks, cd, best_cd, best, i+1, n, current, cont);
		cd[i] = false;
		current -= tracks[i];
	}
	backtrack(tracks, cd, best_cd, best, i+1, n, current,cont);
}

int main() {
	int n, t, x;
	while(cin >> n) {
		cin >> t;
		vector<int> tracks;
		vector<bool> best_cd(t,false);
		vector<bool> cd(t, false);
		int best = 0;
		for(int i = 0; i < t; i++) {
			cin >> x;
			tracks.push_back(x);
		}
		bool cont = true;
		backtrack(tracks, cd, best_cd, best, 0, n, 0, cont);
		for(int i = 0; i < t; i++) {
			if(best_cd[i]) {
				cout << tracks[i] << " ";
			}
		}
		cout <<  "sum:" << best << endl;
	}
	return 0;
}