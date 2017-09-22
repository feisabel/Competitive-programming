#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	int n, x, q;
	int a = 1;
	while(cin >> n && n != 0) {
		cout << "Case " << a << ":" << endl;
		a++;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		cin >> q;
		sort(v.begin(),v.end());
		for(int i = 0; i < q; i++) {
			cin >> x;
			int min = INT_MAX;
			int sum;
			for(int j = 0; j < n-1; j++) {
				for(int k = j+1; k < n; k++) {
					if(v[j]+v[k] == x) {
						min = 0;
						sum = x;
						j = n;
						break;
					}
					else if(v[j]+v[k] < x) {
						if(x - (v[j]+v[k]) < min) {
							sum = v[j] + v[k];
							min = x - (v[j]+v[k]);
						}
					}
					else {
						if(v[j]+v[k] - x < min) {
							sum = v[j] + v[k];
							min = v[j]+v[k]-x;
						}
						break;
					}
				}
			}
			cout << "Closest sum to " << x << " is " << sum << "." << endl; 
		}
	}

	return 0;
}