#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <stack> 

using namespace std; 

int main() {
	int n;
	cin >> n; 
	while (n != 0) {
		int k;
		cin >> k;
		while(k != 0) {
			stack<int> cars;
			deque<int> desired;
			desired.push_back(k);
			for(int i = 0; i < n-1; i++) {
				cin >> k;
				desired.push_back(k);
			}
			int i = 1;
			while(i <= n) {
				while(i<= n && desired.size() > 0 && i != desired.front()) {
					cars.push(i);
					i++;
				}
				i++;
				desired.pop_front();
				while(desired.size()> 0 && cars.size() > 0 && desired.front() == cars.top()) {
					desired.pop_front();
					cars.pop();
				}
			}
			if(cars.size() == 0) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			cin >> k;
		}
		cin >> n;
			cout << endl;
	}
}