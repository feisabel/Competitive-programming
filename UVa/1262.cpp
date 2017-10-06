#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <set>
#include <string>

using namespace std;

void backtrack(int i, int& n, int k, vector<set<char>>& common, vector<char>& word, bool& cont) {
	if(!cont) {
		return;
	}
	if(i == 5) {
		n++;
		if(n == k) {
			for(int j = 0; j < 5; j++) {
				cout << word[j];
			}
			cout << endl;
			cont = false;
		}
		return;
	}
	for(auto it = common[i].begin(); it != common[i].end(); it++) {
		word.push_back(*it);
		backtrack(i+1, n, k, common, word, cont);
		word.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++) {
		int k;
		cin >> k;
		vector<string> first;
		vector<string> second;
		string s;
		for(int i = 0; i < 6; i++) {
			cin >> s;
			first.push_back(s);
		}
		for(int i = 0; i < 6; i++) {
			cin >> s;
			second.push_back(s);
		}
		vector<set<char>> common(5);
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 6; j++) {
				for(int l = 0; l < 6; l++) {
					if (second[l][i] == first[j][i]) {
						common[i].insert(first[j][i]);
						break;
					}
				}
			}
		}
		vector<char> word;
		bool cont = true;
		int n = 0;
		backtrack(0, n, k, common, word, cont);
		if(cont) {
			cout << "NO" << endl;
		}
	}
	return 0;
}