#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <stack> 
#include <sstream>

using namespace std; 

int main() {
	string s;
	while(getline(cin,s)) {
		stringstream ss(s);
		stack<int> st;
		stack<int> sums;
		int prev = 0;
		int sum = 0;
		bool good = true;
		int a;
		while(ss >> a) {
			if(a < 0) {
				st.push(a);
				if(prev > 0) {
					sums.push(sum + a*-1);
				}
				else {
					sums.push(a*-1);
				}
				prev = a;
			}
			else {
				if(st.empty() || st.top() != a*-1) {
					good = false;
					break;
				}
				else {
					if(prev > 0 && sum >= a) {
						good = false;
						break;
					}
					st.pop();
					sum = sums.top();
					sums.pop();
					prev = a;
				}
			}
		}
		if(!st.empty())
			good = false;
		if(good)
			cout << ":-) Matrioshka!" << endl;
		else
			cout << ":-( Try again." << endl;
	}
	return 0;
}