#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <map>

using namespace std;

struct Stats {
	int points;
	int wins;
	int ties;
	int losses;
	int goaldiff;
	int goals;
	int took;
	int games;
	string name;
};

bool case_insensitve_cmp (char c1, char c2) { 
	return tolower(c1) < tolower(c2); 
}

bool cmp(const Stats& s1, const Stats& s2) {
	if(s1.points > s2.points) {
		return true;
	}
	else if(s2.points > s1.points) {
		return false;
	}
	else {
		if(s1.wins > s2.wins) {
			return true;
		}
		else if(s2.wins > s1.wins) {
			return false;
		}
		else {
			if(s1.goaldiff > s2.goaldiff) {
				return true;
			}
			else if(s2.goaldiff > s1.goaldiff) {
				return false;
			}
			else {
				if(s1.goals > s2.goals) {
					return true;
				}
				else if(s2.goals > s1.goals) {
					return false;
				}
				else {
					if(s1.games < s2.games) {
						return true;
					}
					else if(s2.games < s1.games) {
						return false;
					}
					else {
						return lexicographical_compare(s1.name.begin(), s1.name.end(), s2.name.begin(), s1.name.end(), case_insensitve_cmp);
					}
				}
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	string tname;
	getline(cin, tname);
	for(int tc2 = 0; tc2 < tc; tc2++) {
		getline(cin, tname);
		int t;
		cin >> t;
		map<string,int> team;
		vector<Stats> v(t);
		string s;
		getline(cin, s);
		for(int i = 0; i < t; i++) {
			getline(cin, s);
			team[s] = i;
			v[i].name = s;
			v[i].points = 0;
			v[i].goaldiff = 0;
			v[i].wins = 0;
			v[i].goals = 0;
			v[i].took = 0;
			v[i].games = 0;
			v[i].ties = 0;
			v[i].losses = 0;
		}
		int g;
		cin >> g;
		getline(cin, s);
		for(int i = 0; i < g; i++) {
			getline(cin, s);
			stringstream ss(s);
			string t1, t2, aux;
			int g1, g2;
			getline(ss, t1, '#');
			getline(ss, aux, '@');
			g1 = stoi(aux, nullptr);
			getline(ss, aux, '#');
			g2 = stoi(aux, nullptr);
			getline(ss, t2);
			if(g1 > g2) {
				v[team[t1]].points += 3;
				v[team[t1]].wins += 1;
				v[team[t2]].losses += 1;
			}
			else if(g1 < g2) {
				v[team[t2]].points += 3;
				v[team[t2]].wins += 1;
				v[team[t1]].losses += 1;
			}
			else{
				v[team[t1]].points += 1;
				v[team[t2]].points += 1;
				v[team[t1]].ties += 1;
				v[team[t2]].ties += 1;
			}
			v[team[t1]].goals += g1;
			v[team[t2]].goals += g2;
			v[team[t1]].took += g2;
			v[team[t2]].took += g1;
			v[team[t1]].games += 1;
			v[team[t2]].games += 1;
		}
		for(int i = 0; i < t; i++) {
			v[i].goaldiff = v[i].goals - v[i].took;
		}
		sort(v.begin(), v.end(), cmp);
		cout << tname << endl;
		for(int i = 0; i < t; i++) {
			cout << i+1 << ") " << v[i].name << " " << v[i].points << "p, " << v[i].games << "g (";
			cout << v[i].wins << "-" << v[i].ties << "-" << v[i].losses << "), " << v[i].goaldiff << "gd (";
			cout << v[i].goals << "-" << v[i].took << ")" << endl;
		}
		if(tc2 != tc-1)
			cout << endl;
	}
	return 0;
}