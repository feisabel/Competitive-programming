#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <queue> 

using namespace std; 

int main() {
	int n;
	while(cin >> n && n != 0) {
		queue<int> q;
		queue<int> discarded;
		for(int i = 1; i <= n; i++) {
			q.push(i);
		}
		while(q.size() >= 2) {
			discarded.push(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		if(discarded.size() > 0) { 
			cout << "Discarded cards: ";
			while(discarded.size() > 1) {
				cout << discarded.front() << ", ";
				discarded.pop();
			}
			cout << discarded.front() << endl;
		}
		else
			cout << "Discarded cards:" << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
	return 0;
}