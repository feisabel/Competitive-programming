#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <fstream>
#include <list> 

using namespace std; 

int main() {
	int n;
	cin >> n;
	vector<list<int>> blocks(n);
	vector<int> where(n);
	for(int i = 0; i < n; i++) {
		blocks[i].push_back(i);
		where[i] = i;
	}
	string line;
	while(getline(cin, line) && line.compare("quit") != 0) {
		int start = 0, end = 4;
		string action = line.substr(start,end-start);
		start = end-start;
		end = line.find_first_of(" ", start);
		int from = stoi(line.substr(start, end-start), nullptr);
		start = end-start;
		end = line.find_first_of(" ", start);
		string how = line.substr(start, end-start);
		start = end-start;
		end = line.find_first_of(" ", start);
		int to = stoi(line.substr(start, end-start), nullptr);

		if(from != to && where[from] != where[to]) {
			if(action.compare("move")) {
				for(list<int>::reverse_iterator it = blocks[where[from]].rbegin(); it != blocks[where[from]].rend(); it++) {
					if(*it == from)
						break;
					blocks[*it].splice(blocks[*it].end(), blocks[where[from]], prev(blocks[where[from]].end()));
				}
				if(how.compare("onto")) {
					for(list<int>::reverse_iterator it = blocks[where[to]].rbegin(); it != blocks[where[to]].rend(); it++) {
						if(*it == to)
							break;
						blocks[*it].splice(blocks[*it].end(), blocks[where[to]], prev(blocks[where[to]].end()));
					}
				}
				blocks[where[to]].splice(blocks[where[to]].end(), blocks[where[from]], prev(blocks[where[from]].end()));
			}
			else {
				if(how.compare("onto")) {
					for(list<int>::reverse_iterator it = blocks[where[to]].rbegin(); it != blocks[where[to]].rend(); it++) {
						if(*it == to)
							break;
						blocks[*it].splice(blocks[*it].end(), blocks[where[to]], prev(blocks[where[to]].end()));
					}
				}
				list<int>::iterator it;
				for(it = blocks[where[from]].begin(); it != blocks[where[from]].end(); it++) {
					if(*it == from)
						break;
				}
				blocks[where[to]].splice(blocks[where[to]].end(), blocks[where[from]], it, prev(blocks[where[from]].end()));
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << i << ":";
		for(list<int>::iterator it = blocks[i].begin(); it != blocks[i].end(); it++) {
			cout << " " << *it;
		}
		cout << endl;
	}
}