#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++) {
		int n, x;
		cin >> n;
		vector<int> coins;
		for(int i = 0; i < n; i++) {
			cin >> x;
			coins.push_back(x);
		}
		int sum = 0;
		int count = 0;
		for(int i = 0; i < n-1; i++) {
			if(sum + coins[i] < coins[i+1]) {
				sum += coins[i];
				count++;
			}
		}
		cout << count+1 << endl;
	}
	return 0;
}