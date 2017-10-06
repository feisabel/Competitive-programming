#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

void backtrack(int i, int n, vector<int>& numbers, vector<bool>& solution, int sum, int t, bool& found) {
	if(sum == t) {
		found = true;
		int j;
		for(j = 0; j < n; j++) {
			if(solution[j]) {
				cout << numbers[j];
				break;
			}
		}
		for(j = j+1; j < n; j++) {
			if(solution[j]) {
				cout << "+" << numbers[j];
			}
		}
		cout << endl;
		return;
	}
	if(i == n) {
		return;
	}
	if(sum + numbers[i] <= t) {
		solution[i] = true;
		backtrack(i+1,n,numbers,solution,sum+numbers[i],t, found);
		solution[i] = false;
	}
	int m = numbers[i];
	while(numbers[i] == m) {
		i++;
	}
	backtrack(i,n,numbers,solution,sum,t, found);
}

int main() {
	int t, n;
	cin >> t >> n;
	while(n != 0) {
		cout << "Sums of " << t << ":" << endl;
		vector<int> numbers;
		int x;
		for(int i = 0; i < n; i++) {
			cin >> x;
			numbers.push_back(x);
		}
		vector<bool> solution(n,false);
		bool found = false;
		backtrack(0, n, numbers, solution, 0, t, found);
		if(!found)
			cout << "NONE" << endl;
		cin >> t >> n;
	}
	return 0;
}