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
	string s;
	getline(cin, s);
	for(int t = 0; t < n; t++) {
		getline(cin, s);
		stack<char> st;
		bool good = true;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else {
				if(st.empty()) {
					good = false;
					break;
				}
				else if(s[i] == ')') {
					if(st.top() == '(') {
						st.pop();
					}
					else {
						good = false;
						break;
					}
				}
				else if(s[i] == ']') {
					if(st.top() == '[') {
						st.pop();
					}
					else {
						good = false;
						break;
					}
				}
			}
		}
		if(!st.empty())
			good = false;
		if(good)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}