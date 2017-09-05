#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string standard(string s) {
	string s2 = "";
	for(int i = 0; i < s.size(); i++) {
		if(s[i] - 'A' <= 26) {
			s2 += (s[i] - 'A') + 'a';
		}
		else {
			s2 += s[i];
		}
	}
	sort(s2.begin(),s2.end());
	return s2;
}

int main() {
	string s;
	cin >> s;
	vector<string> v;
	while(s.compare("#") != 0) {
		v.push_back(s);
		cin >> s;
	}
	map<string,pair<int,int>> anagramas;
	for(int i = 0; i < v.size(); i++) {
		s = standard(v[i]);
		if(anagramas.find(s) == anagramas.end()) {
			anagramas[s] = make_pair(1, i);
		}
		else {
			anagramas[s].first++;
		}
	}
	vector<string> results;
	for(auto it = anagramas.begin(); it != anagramas.end(); it++) {
		if(it->second.first == 1) {
			results.push_back(v[it->second.second]);
		}
	}
	sort(results.begin(), results.end());
	for(int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
	return 0;
}