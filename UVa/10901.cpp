#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int tc = 0; tc < cases; tc++) {
		int n, p, m;
		cin >> n >> p >> m;
		string side = "left";
		int t = 0;
		int k;
		string s;
		queue<int> left;
		queue<int> right;
		queue<int> boarded;
		vector<int> cars;
		for(int i = 0; i < m; i++) {
			cin >> k;
			cars.push_back(k);
			cin >> s;
			if(s.compare("left") == 0) {
				left.push(i);
			}
			else{
				right.push(i);
			}
		}
		while(left.size() > 0 || right.size() > 0) {
			if(side.compare("left") == 0) {
				while(left.size() > 0 && cars[left.front()] <= t) {
					boarded.push(left.front());
					left.pop();
					if(boarded.size() == n) {
						break;
					}
				}
				if(!boarded.empty()) {
					side = "right";
					t+=p;
					while(!boarded.empty()) {
						cars[boarded.front()] = t;
						boarded.pop();
					}
				}
				else {
					if(left.empty()) {
						side = "right";
						if(t < cars[right.front()])
							t = cars[right.front()];
						t+=p;
					}
					else if(right.empty() || cars[left.front()] <= cars[right.front()]) {
						t = cars[left.front()];
					}
					else {
						side = "right";
						if(t < cars[right.front()])
							t = cars[right.front()];
						t+=p;
					}
				}
			}
			else{
				while(right.size() > 0 && cars[right.front()] <= t) {
					boarded.push(right.front());
					right.pop();
					if(boarded.size() == n) {
						break;
					}
				}
				if(!boarded.empty()) {
					side = "left";
					t+=p;
					while(!boarded.empty()) {
						cars[boarded.front()] = t;
						boarded.pop();
					}
				}
				else {
					if(right.empty()) {
						side = "left";
						if(t < cars[left.front()])
							t = cars[left.front()];
						t+=p;
					}
					else if(left.empty() || cars[right.front()] <= cars[left.front()]) {
						t = cars[right.front()];
					}
					else {
						side = "left";
						if(t < cars[left.front()])
							t = cars[left.front()];
						t+=p;
					}
				}
			}
		}
		for(int i = 0; i < m; i++) {
			cout << cars[i] << endl;
		}
		if (tc != cases-1)
			cout << endl;
	}
	return 0;
}