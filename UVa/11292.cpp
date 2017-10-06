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
	int n, m;
	while(cin >> n >> m && (n!=0 || m!=0)) {
		int x;
		vector<int> heads;
		vector<int> knights;
		for(int i = 0; i < n; i++) {
			cin >> x;
			heads.push_back(x);
		}
		for(int i = 0; i < m; i++) {
			cin >> x;
			knights.push_back(x);
		}
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		int j = 0;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			while(j < m && knights[j] < heads[i]) {
				j++;
			}
			if(j == m) {
				sum = -1;
				break;
			}
			sum += knights[j];
			j++;
		}
		if(sum < 0) {
			cout << "Loowater is doomed!" << endl;
		}
		else {
			cout << sum << endl;
		}
	}
	return 0;
}