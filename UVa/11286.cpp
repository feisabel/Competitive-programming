#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, c;
	cin >> n;
	while(n != 0) {
		map<vector<int>, int> comb;
		for(int i = 0; i < n; i++) {
			vector<int> v;
			for(int j = 0; j < 5; j++) {
				cin >> c;
				v.push_back(c);
			}
			sort(v.begin(),v.end());
			if(comb.find(v) == comb.end())
				comb[v] = 1;
			else
				comb[v]++;
		}
		int max = 0;
		for(auto it = comb.begin(); it != comb.end(); it++) {
			if(it->second > max)
				max = it->second;
		}
		int count = 0;
		for(auto it = comb.begin(); it != comb.end(); it++) {
			if(it->second == max)
				count += max;
		}
		cout << count << endl;
		cin>>n;
	}
	return 0;
}