#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long z = 2;
	int count = 0;
	while(z*z<=n) {
		if(n%z == 0) {
			count++;
			while(n%z == 0)
				n/=z;
		}
		else
			z++;
	}
	if(n>1)
		count++;
	long long i = 1 << count;
	i -= count;
	i -= 1;
	cout << i << endl; 
	return 0;
}