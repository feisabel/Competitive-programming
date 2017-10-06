#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

void backtrack(int i, int n, vector<int>& solution, vector<bool>& used, set<int>& primes) {
	if(i == n) {
		if(primes.count(solution[n-1] + 1)) {
			for(int i = 0; i < n-1; i++) {
				cout << solution[i] << " ";
			}
			cout << solution[n-1] << endl;
		}
		return;
	}
	for(int j = 2; j <= n; j++) {
		if(!used[j]) {
			if(primes.count(solution[i-1] + j)) {
				used[j] = true;
				solution[i] = j;
				backtrack(i+1, n, solution, used, primes);
				used[j] = false;
			}
		}
	}
}

int main() {
	int n, k = 1;
	while(cin >> n) {
		if(k!=1) 
			cout << endl;
		cout << "Case " << k << ":" << endl;
		k++;
		vector<int> solution(n, 0);
		solution[0] = 1;
		vector<bool> used(n+1, false);
		used[1] = true;
		int temp[]= {2,3,5,7,11,13,17,19,23,29,31};
  		set<int> primes(temp,temp+11);
		backtrack(1, n, solution, used, primes);
	}
	return 0;
}