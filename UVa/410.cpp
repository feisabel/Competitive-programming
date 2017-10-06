#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int main () {
	int c, s;
	int k = 1;
	while(cin >> c >> s) {
		cout << "Set #" << k << endl;
		k++;
		vector<int> masses;
		int x;
		for(int i = 0; i < s; i++) {
			cin >> x;
			masses.push_back(x);
		}
		sort(masses.begin(), masses.end());
		int c2 = c;
		if(s < c)
			c2 = s;
		vector<vector<int>> chambers(c);
		int j = s-1;
		for(int i = 0; i < c2; i++) {
			chambers[i].push_back(masses[j]);
			j--;
		}
		if(j >= 0) {
			for(int i = c-1; i >= 0 && j >= 0; i--) {
				chambers[i].push_back(masses[j]);
				j--;
			}
		}
		vector<int> CM(c, 0);
		double AM = 0;
		for(int i = 0; i < c; i++) {
			cout << " " << i << ":";
			for(int l = 0; l < chambers[i].size(); l++) {
				CM[i] += chambers[i][l];
				cout << " " << chambers[i][l];
			}
			cout << endl;
			AM += CM[i];
		}
		AM /= double(c);
		double imbalance = 0;
		for(int i = 0; i < c; i++) {
			imbalance += abs(CM[i] - AM);
		}
		cout << "IMBALANCE = ";
		printf("%.5f", imbalance);
		cout << endl;
		cout << endl;
	}
	return 0;
}