#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>

using namespace std; 

bool pairCompare(const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) {
	if(a.second.first > b.second.first)
		return true;
	if(a.second.first == b.second.first) {
		if(a.second.second < b.second.second)
			return true;
		if(a.second.second == b.second.second) {
			return a.first < b.first;
		}
		return false;
	}
	return false;

}

int main() {
	int bla;
	cin >> bla;
	string line;
	getline(cin, line);
	getline(cin, line);
	for (int tt = 0; tt < bla; tt++) {
		vector<vector<bool>> correct(101, vector<bool>(10,false));
		vector<vector<int>> times(101, vector<int>(10,0));
		vector<pair<int,pair<int,int>>> scores;
		vector<bool> submited(101, false);
		while (getline(cin, line) && !line.empty()) {
			int i = line.find_first_of(" ", 0);
   			int participant = stoi(line.substr(0, i), nullptr);
   			int j = line.find_first_of(" ", i+1);
			int problem = stoi(line.substr(i+1, j-(i+1)), nullptr);
			i = line.find_first_of(" ", j+1);
			int t = stoi(line.substr(j+1, i-(j+1)), nullptr);
			string result = line.substr(line.size()-1, 1);
			if (result.compare("I") == 0 && !correct[participant][problem]) {
				times[participant][problem]+=20;
				submited[participant] = true;
			}
			else if (result.compare("C") == 0 && !correct[participant][problem]) {
				times[participant][problem] += t;
				correct[participant][problem] = true;
				submited[participant] = true;
			}
			else
				submited[participant] = true;
		}
		for (int i = 1; i < 101; i++) {
			int points = 0;
			int penalty = 0;
			for (int j = 1; j < 10; j++) {
				if (correct[i][j]) {
					points++;
					penalty += times[i][j];
				}
			}
			if(submited[i]) {
				scores.push_back(make_pair(i, make_pair(points, penalty)));
			}
		}
		sort(scores.begin(), scores.end(), pairCompare);
		for(int i = 0; i < scores.size(); i++) {
			cout << scores[i].first << " " << scores[i].second.first << " " << scores[i].second.second << endl;
		}
		if(tt < bla-1)
			cout << endl;
	} 
	return 0;
}