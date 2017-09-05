#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n != 0) {
		cout << "Printing order for " << n << " pages:" << endl;
		int sheet = 1;
		int min = 1;
		int max = n;
		bool front = true;
		if(n % 4 == 1) {
			cout << "Sheet 1, front: Blank, " << 1 << endl;
			min++;
			if(n > 4) {
				cout << "Sheet 1, back : " << 2 << ", Blank" << endl;
				min++;
				cout << "Sheet 2, front: Blank, " << 3 << endl;
				min++;
				sheet++;
			}
			front = false;
		}
		else if(n%4 == 2) {
			cout << "Sheet 1, front: Blank, " << 1 << endl;
			cout << "Sheet 1, back : " << 2 << ", Blank" << endl;
			sheet++;
			min = 3;
		}
		else if(n%4 == 3) {
			cout << "Sheet 1, front: Blank, " << 1 << endl;
			cout << "Sheet 1, back : " << 2 << ", " << max << endl;
			sheet++;
			min = 3;
			max--;
		}
		for(int i = 0; i < n/4;i++) {
			if(front) {
				cout << "Sheet " << sheet << ", front: " << max << ", " << min << endl;
				max--;
				min++;
				cout << "Sheet " << sheet << ", back : " << min << ", " << max << endl;
				max--;
				min++;
				sheet++;
			}
			else{
				front = true;
				cout << "Sheet " << sheet << ", back : " << min << ", " << max << endl;
				min++;
				max--;
				sheet++;
			}
		}

		cin >> n;
	}
	return 0;
}