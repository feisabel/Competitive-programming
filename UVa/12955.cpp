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
	int n;
	vector<int> factorials;
	int fact = 1;
	for(int i = 1; i <= 8; i++) {
		fact *= i;
		factorials.push_back(fact);
	}
	while(cin >> n) {
		int count = 0;
		for(int i = 7; i >= 0; i--) {
			while(n >= factorials[i]) {
				n -= factorials[i];
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}