#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <fstream>

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
	string s;
	getline(cin, s);
	while(s.compare("DONE") != 0) {
		int j = s.size()-1;
		int i = 0;
		while(i < j) {
			if(s[i] < 'A')
				i++;
			else if(s[j] < 'A')
				j--;
			else {
				if(s[i] > s[j]) {
					if(s[i]-32 != s[j])
						break;
					else{
						i++;
						j--;
					}
				}
				else if(s[i] < s[j]) {
					if(s[j]-32 != s[i])
						break;
					else{
						i++;
						j--;
					}
				}
				else {
					i++;
					j--;
				}
			}
		}
		if(i < j)
			cout << "Uh oh.." << endl;
		else
			cout << "You won't be eaten!" << endl;
		getline(cin, s);
	}
	return 0;
}