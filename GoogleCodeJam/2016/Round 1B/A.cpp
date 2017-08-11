#include <iostream>
#include <string>
#include <vector>

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
	int tests, t;
	cin >> tests;
	for(t = 1; t <= tests; t++) {
		string s;
		cin >> s;
		int k = 0;
		vi numbers(10);
		vector<bool> is(sz(s), true);
		vi letters(26);
		for(int i = 0; i < sz(s); i++)
			letters[(int)s[i]-65]++;
		while(letters[25] > 0) {
			numbers[0]++;
			letters[25]--;
			letters[4]--;
			letters[17]--;
			letters[14]--;
		}
		while(letters[22] > 0) {
			numbers[2]++;
			letters[22]--;
			letters[14]--;
			letters[19]--;
		}
		while(letters[23] > 0) {
			numbers[6]++;
			letters[23]--;
			letters[18]--;
			letters[8]--;
		}
		while(letters[6] > 0) {
			numbers[8]++;
			letters[6]--;
			letters[4]--;
			letters[8]--;
			letters[7]--;
			letters[19]--;
		}
		while(letters[18] > 0) {
			numbers[7]++;
			letters[18]--;
			letters[4]--;
			letters[4]--;
			letters[21]--;
			letters[13]--;
		}
		while(letters[21] > 0) {
			numbers[5]++;
			letters[21]--;
			letters[5]--;
			letters[8]--;
			letters[4]--;
		}
		while(letters[5] > 0) {
			numbers[4]++;
			letters[5]--;
			letters[14]--;
			letters[20]--;
			letters[17]--;
		}
		while(letters[7] > 0) {
			numbers[3]++;
			letters[7]--;
			letters[19]--;
			letters[4]--;
			letters[4]--;
			letters[17]--;
		}
		while(letters[8] > 0) {
			numbers[9]++;
			letters[8]--;
			letters[13]--;
			letters[13]--;
			letters[4]--;
		}
		while(letters[13] > 0) {
			numbers[1]++;
			letters[13]--;
			letters[14]--;
			letters[4]--;
		}
		cout << "Case #" << t << ": ";
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < numbers[i]; j++)
				cout << i;
		}
		cout << endl;
	}
	return 0;
}