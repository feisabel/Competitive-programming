#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {

	int a,b;
	vector<int> answers;
	vector<int> firsts;
	vector<int> lasts;
	while(scanf("%i %i", &a, &b) != EOF) {
		vector<int> vec;
		firsts.push_back(a);
		lasts.push_back(b);
		int temp = a;
		if (a > b) {
			a = b;
			b = temp;
		}
		for(int i = a; i <= b; i++) {
			int n = i;
			int count = 0;
			while(n != 1) {
				if(n%2 != 0)
					n = 3 * n + 1;
				else
					n /= 2;
				count++;
			}
			count++;
			vec.push_back(count);
		}
		int max = 0;
		for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			if (max < *it)
				max = *it;
		}
		answers.push_back(max);
	}
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	vector<int>::iterator it3;
	for( it1 = firsts.begin(), it2 = lasts.begin(), it3 = answers.begin(); it3 != answers.end(); it1++, it2++, it3++) {
		cout << *it1 << " " << *it2 << " " << *it3 << endl;
	}

	return 0;
}