#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		bool noError = true;

		string command;
		cin >> command;

		int size;
		cin >> size;
		
		deque<int> list;
		int d;
		char c;
		cin >> c; //'[' 받음
		while (c != ']') {
			if (size == 0) {
				cin >> c; // ']' 받음
				break;
			}
			cin >> d >> c; // (숫자), ',' 또는 ']' 받음
			list.push_back(d);
		}

		int R_cnt = 0;

		for (int i = 0; i < command.length(); i++) {

			if (noError) {
				switch (command[i]) {
				case 'R':
					R_cnt++;
					break;
				case 'D':
					if (list.empty()) {
						cout << "error" << "\n";
						noError = false;
						break;
					}
					else {
						if (R_cnt % 2 == 0) {
							list.pop_front();
						}
						else {
							list.pop_back();
						}
					}
				}
			}
			else {
				break;
			}
		}

		if (R_cnt % 2 != 0) {
			reverse(list.begin(), list.end());
		}

		if (noError) {
			cout << "[";
			for (int i = 0; i < list.size(); i++) {
				cout << list[i];
				if (i != list.size() - 1) {
					cout << ",";
				}
			}
			cout << "]" << "\n";
		}
		
		noError = true;
	}
}