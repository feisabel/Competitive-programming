#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int t, n, m, l;
	vector<bool> v(10);
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0) {
			cout << "Case #" << i+1 << ": INSOMNIA" << endl;
		}
		else{
			for(int j = 0; j < 10; j++)
				v[j] = false;
			int k = 1;
			while(1) {
				m = n * k;
				l = m;
				k++;
				while(1) {
					v[m % 10] = true;
					m = m/10;
					if (m == 0)
						break;
				}
				int a;
				for (a = 0; a < 10; a++){
					if(!v[a])
						break;
				}
				if(a == 10)
					break;
			}
			cout << "Case #" << i+1 << ": " << l << endl;
		}
	}

	return 0;
}