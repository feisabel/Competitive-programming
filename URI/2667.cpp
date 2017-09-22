#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int main() {
	int n = 0, a;
	char c;
	string line;
	getline(cin, line);
	stringstream ss(line);
	while(ss >> c) {
		a = c - '0';
		n += a;
		n = n % 3;
	}
	cout << n << endl;
	return 0;
}