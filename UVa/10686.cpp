#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main() {
	int t, cat, w, m;
	cin >> t;
	string s,line;
	for(int tt = 0; tt < t; tt++) {
		vector<string> names;
		vector<set<string>> sets;
		vector<int> minw;
		cin >> cat;
		for(int i = 0; i < cat; i++) {
			cin >> s >> w >> m;
			names.push_back(s);
			minw.push_back(m);
			set<string> wset;
			for(int j = 0; j < w; j++) {
				cin >> s;
				wset.insert(s);
			}
			sets.push_back(wset);
		} 
		vector<set<string>> n(names.size());
		getline(cin, line);
		if(line.compare("") == 0)
			getline(cin,line);
		while(line.compare("") != 0) {
			int j = 0;
			while (j < line.size()) {
				s = "";
				while(j < line.size() && ((line[j] - 'a' >= 0 && line[j] - 'a' < 26) || (line[j] - 'A' >= 0 && line[j] - 'A' < 26))) {
					s+=line[j];
					j++;
				}
				j++;
				if(s.compare("") != 0) {
					for(int i = 0; i < names.size(); i++) {
						if(sets[i].find(s) != sets[i].end()) {
							n[i].insert(s);
						}
					}
				}
			}
			getline(cin, line);
		}
		vector<string> answer;
		for(int i = 0; i < names.size(); i++) {
			if(n[i].size() >= minw[i]) {
				answer.push_back(names[i]);
			}
		}
		if(answer.size() == 0)
			cout << "SQF Problem." << endl;
		else{
			for(int i = 0; i < answer.size(); i++) {
				if(i > 0)
					cout << ",";
				cout << answer[i];
			}
			cout << endl;
		}
	}
	return 0;
}