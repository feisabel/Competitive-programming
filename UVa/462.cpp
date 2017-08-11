#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <fstream>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair 

int main() {
	vector<char> suit;
	suit.pb('S');
	suit.pb('H');
	suit.pb('D');
	suit.pb('C');
	map<char, int> index;
	index['S'] = 0;
	index['H'] = 1;
	index['D'] = 2;
	index['C'] = 3;
	string s;
	while(getline(cin, s)) {
		vector<int> cards(4, 0);
		vector<bool> stopped(4, false);
		int points = 0;
		for(int i = 0; i < 39; i+=3)
			cards[index[s[i+1]]]++;
		for(int i = 0; i < 39; i+=3) {
			if(s[i] == 'A') {
				points += 4;
				stopped[index[s[i+1]]] = true;
			}
			else if(s[i] == 'K') {
				points += 3;
				if(cards[index[s[i+1]]] > 1)
					stopped[index[s[i+1]]] = true;
				else
					points--;

			}
			else if(s[i] == 'Q') {
				points += 2;
				if(cards[index[s[i+1]]] > 2)
					stopped[index[s[i+1]]] = true;
				else
					points--;
			}
			else if(s[i] == 'J') {
				points += 1;
				if(cards[index[s[i+1]]] <= 3)
					points--;
			}
		}
		if(points >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3]) {
			cout << "BID NO-TRUMP" << endl;
		}
		else {
			int max = 0, k;
			for(int i = 0; i < 4; i++) {
				if(cards[i] == 2)
					points++;
				else if(cards[i] == 1 || cards[i] == 0)
					points+=2;
				if(cards[i] > max) {
					max = cards[i];
					k = i;
				}
			}
			if(points >= 14)
				cout << "BID " << suit[k] << endl;
			else
				cout << "PASS" << endl;
		}
	}
	return 0;
}