#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n, m, k = 1;
	char c;
	scanf("%i %i", &n, &m);
	vector<vector<vector<int> > > answers;
	vector<int> ns;
	vector<int> ms;
	while (n != 0 || m != 0) {
		vector<vector<int> > mat(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				mat[i].push_back(0);
			}
		}
		getchar();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%c", &c);
				if (c == '*')
					mat[i][j] = -1;
			}
			getchar();
		}
		for(int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(mat[i][j] == -1) {
					if (i-1 >= 0) {
						if (j-1 >= 0) {
							if(mat[i-1][j-1] != -1)
								mat[i-1][j-1]++;
						}
						if(mat[i-1][j] != -1)
								mat[i-1][j]++;
						if(j+1 < m) {
							if(mat[i-1][j+1] != -1)
								mat[i-1][j+1]++;
						}
					}
					if (j - 1 >= 0) {
						if(mat[i][j-1] != -1)
								mat[i][j-1]++;
					}
					if (j+1 < m) {
						if(mat[i][j+1] != -1)
								mat[i][j+1]++;
					}
					if (i+1 < n) {
						if (j-1 >=0) {
							if(mat[i+1][j-1] != -1)
								mat[i+1][j-1]++;
						}
						if(mat[i+1][j] != -1)
								mat[i+1][j]++;
						if(j+1 < m) {
							if(mat[i+1][j+1] != -1)
								mat[i+1][j+1]++;
						}
					}
				}
			}
		}
		answers.push_back(mat);
		ns.push_back(n);
		ms.push_back(m);
		scanf("%i %i", &n, &m);
	}
	vector<int>::iterator in;
	vector<int>::iterator im;
	vector<vector<vector<int> > >::iterator ia;
	for(in = ns.begin(), im = ms.begin(), ia = answers.begin(); in != ns.end(); in++, im++, ia++) {
		cout << "Field #" << k  << ":" << endl;
		k++;
		for(int i = 0; i < *in; i++) {
			for(int j = 0; j < *im; j++) {
				vector<vector<int> > a = *ia;
				if (a[i][j] == -1)
					cout << '*';
				else
					cout << a[i][j];
			}
			cout << endl;
		}
		if(in + 1 != ns.end())
			cout << endl;
	}


	return 0;
}